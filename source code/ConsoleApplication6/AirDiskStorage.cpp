#include "AirDiskStorage.h"



AirDiskStorage::AirDiskStorage(TexT disk_name) :
	disk_name(disk_name),
	initial_path(ToolString::SplicingStrings({ "\\\\?\\",disk_name,"*" })),
	number_of_files(0),
	number_of_folders(0)
{
	int result = time(nullptr);
	table_name.assign(to_string(result));
	db_path = ToolString::SplicingStrings({ ToolDisk::GetCurrentPath().c_str(),"\\db"});
	string disk_name_new = ToolString::Cutflagstring(disk_name, 1, (char*)":");
	this->sqlite_management = new AirSqliteManagement(ToolString::SplicingStrings({ db_path.c_str() ,"\\", disk_name_new.c_str(), ".db"}), disk_name_new);
}	

AirDiskStorage::~AirDiskStorage()
{
	delete[] this->disk_name;
}
TexT AirDiskStorage::GetdiskName()
{
	return this->disk_name;
}


bool AirDiskStorage::ergodic()
{
	initprepare_sql();
	TraverseFileSystemA_thread(disk_name, 3);
	string create_index = "CREATE INDEX idx_name \""+ table_name +"\"ON (file_name);";
	sqlite_management->execSql(create_index.c_str());
	return true;
}

bool AirDiskStorage::selectData(string file_name)
{
	init_db();
	sqlite3_stmt* stmt = nullptr;
	sqlite_management->sql_prepare_v2("select name from table_name", &stmt);
	sqlite3_step(stmt);
	string table_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
	string sql_like_data = "select * from \'" + table_name + "\' where file_name like '%" + file_name + "%'";
	sqlite_management->sql_prepare_v2(sql_like_data.c_str(), &stmt);

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		int id  = sqlite3_column_int(stmt, 0);
		string file_path = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		string file_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		cout << " " << file_path << "&" << file_name << "|";
	}
	return true;
}



bool AirDiskStorage::TraverseFileSystemA(Concurrency::concurrent_queue<string>* fileSetof, int thread_number)
{
	WIN32_FIND_DATAA FindFileData;

	string current;
	{
		unique_lock<mutex> lock(mtx1);
		g_cv.wait(lock, [&]() { return !fileSetof->empty(); });
		fileSetof->try_pop(current);
	}
	string insert_sql = "INSERT INTO \"" + table_name + "\" (file_path, file_name) VALUES (?,?);";
	sqlite3_stmt* pPrepare = nullptr;
	sqlite3_prepare_v2(&sqlite_management->GetdbControl(), insert_sql.c_str(), insert_sql.size(), &pPrepare, 0);

	
	HANDLE hFind = FindFirstFileExA((current + "\\*").c_str(), FindExInfoBasic, &FindFileData, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);
	do
	{
		do
		{
			if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

					string result;
					result.append(current.c_str()).append("\\").append(FindFileData.cFileName);
					fileSetof->push(result.c_str());
					if (fileSetof->unsafe_size() > thread_number * 2)
					{
						g_cv.notify_one();
					}
				}
				sqlite3_reset(pPrepare);
				sqlite3_bind_text(pPrepare, 1, current.c_str(), -1, SQLITE_STATIC);
				sqlite3_bind_text(pPrepare, 2, FindFileData.cFileName, -1, SQLITE_STATIC);
				sqlite3_step(pPrepare);
				{ 
					unique_lock<mutex> lock(mtx2);
					comment_sql++; 
				}
				mtx2.lock();
				if (comment_sql == 10000)
				{
					sqlite_management->execSql("COMMIT");
					sqlite_management->execSql("BEGIN");
					comment_sql = 0;
				}
				mtx2.unlock();
			}
		} while (FindNextFileA(hFind, &FindFileData));
		FindClose(hFind);
		string test;
		fileSetof->try_pop(test);
		current.assign(test);
		string result;
		result.append(current.c_str()).append("\\").append("*");
		hFind = FindFirstFileExA(result.c_str(), FindExInfoBasic, &FindFileData, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);

	} while (!fileSetof->empty());
	sqlite_management->execSql("COMMIT");
	sqlite3_finalize(pPrepare);
	FindClose(hFind);
	return true;
}

bool AirDiskStorage::TraverseFileSystemA_thread(TexT disk_path, int thread_number) {
	Concurrency::concurrent_queue<string>* fileSetof = traverse_folder(disk_path);
	vector<std::thread> threads;
	for (int i = 0; i < thread_number; ++i) {
		threads.emplace_back(bind(&AirDiskStorage::TraverseFileSystemA,this, std::placeholders::_1, std::placeholders::_2), fileSetof,thread_number);
	}
	for (auto& thread : threads) {
		thread.join();
	}
	return true;
}


bool AirDiskStorage::init_db()
{
	sqlite3_open(sqlite_management->Getdb_path().c_str(), &sqlite_management->db_Control);
	return true;
}

bool AirDiskStorage::initprepare_sql()
{ 
	if (!ToolFile::IsFolderexists(db_path.c_str())) {
		ToolFile::createFolder(db_path.c_str());
	}
	else
	{
		ToolFile::deleteDirectory(db_path.c_str());
		ToolFile::createFolder(db_path.c_str());
	}
	init_db();
	sqlite_management->execSql("PRAGMA synchronous = OFF");
	string table_sql("CREATE table ");
	table_sql += '"';
	table_sql += table_name;
	table_sql += '"';
	table_sql += "(id INTEGER PRIMARY KEY, file_path TEXT, file_name TEXT);";
	sqlite_management->execSql(table_sql.c_str());
	sqlite_management->execSql("BEGIN");
	sqlite_management->execSql("create table table_name(name TEXT);");
	string table_insert_name_sql = "insert into table_name(name) values(" + table_name + ");";
	sqlite_management->execSql(table_insert_name_sql.c_str());
	return true;
}
Concurrency::concurrent_queue<string>* AirDiskStorage::traverse_folder(TexT file_path)
{
	WIN32_FIND_DATAA FindFileData;
	string Flagbit_str(file_path);
	Flagbit_str += "*";
	HANDLE hFind = FindFirstFileA(Flagbit_str.c_str(), &FindFileData);
	Concurrency::concurrent_queue<string>* file_folder = new Concurrency::concurrent_queue<string>();
	do
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
			string result(file_path);
			result += FindFileData.cFileName;
			file_folder->push(result);
		}
	} while (FindNextFileA(hFind, &FindFileData));

	return file_folder;
}