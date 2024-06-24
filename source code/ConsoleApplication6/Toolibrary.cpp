#include "Toolibrary.h"





namespace ToolString{
	string SplicingStrings(initializer_list<TexT> args)
	{
		string result;
		for (auto arg : args)
		{
			result+=arg;
		}
		return result;
	}

	string Cutflagstring(TexT str,int number, char* flag)
	{
		int i=0,j=-1;
		string* s = new string(str);
		for (auto str_s : *s)
		{
			j++;
			if (str_s == *flag)
			{
				i++;
			}
			if (i == number)
			{
				string s1(s->substr(0, j));
				return s1;
			}
		}
		return NULL;
	}
}


namespace ToolDisk {
	
	vector<TexT>& GetLocalDiskName(bool isEmpty =false)
	{
		vector<TexT>* disk_set = new vector<TexT>;
		char* lpszVolumeName = new char[max_path];
		char* diskname = new char[max_path];
		HANDLE h = FindFirstVolumeA(lpszVolumeName, max_path);
		do
		{
			GetVolumePathNamesForVolumeNameA(lpszVolumeName, diskname, max_path,nullptr);
			if (!isEmpty && strcmp("", diskname)) {
				string* s1 = new string(diskname);
				*s1 += "\\";
				disk_set->push_back(s1->c_str());
			}
			else
			{
				continue;
			}

		} while (FindNextVolumeA(h, lpszVolumeName, max_path));
		delete[] lpszVolumeName, diskname;
		return *disk_set;
	}
	string GetCurrentPath()
	{
		filesystem::path currentPath = filesystem::current_path();
		string path_text(currentPath.string().c_str());
		return path_text;
	}
}


namespace ToolNTFS {
	//mutex mtx1;
	//condition_variable g_cv;
	//bool TraverseFileSystemA(Concurrency::concurrent_queue<string>* fileSetof, bool callback(TexT, TexT),int thread_number)
	//{
	//	WIN32_FIND_DATAA FindFileData;

	//	string current;
	//	{
	//		unique_lock<mutex> lock(mtx1);
	//		g_cv.wait(lock, [&]() { return !fileSetof->empty(); });
	//		fileSetof->try_pop(current);
	//	}

	//	HANDLE hFind = FindFirstFileExA((current+"\\*").c_str(), FindExInfoBasic, &FindFileData, FindExSearchNameMatch,NULL, FIND_FIRST_EX_LARGE_FETCH);
	//	do
	//	{
	//		do
	//		{
	//			if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
	//				if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

	//					string result;
	//					result.append(current.c_str()).append("\\").append(FindFileData.cFileName);
	//					fileSetof->push(result.c_str());
	//					if (fileSetof->unsafe_size() > thread_number*2)
	//					{
	//						g_cv.notify_one();
	//					}
	//				}
	//			}
	//			callback(current.c_str(), FindFileData.cFileName);
	//		} while (FindNextFileA(hFind, &FindFileData));
	//		FindClose(hFind);
	//		string test;
	//		fileSetof->try_pop(test);
	//		current.assign(test);
	//		string result;
	//		result.append(current.c_str()).append("\\").append("*");
	//		hFind = FindFirstFileExA(result.c_str(), FindExInfoBasic ,&FindFileData, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);

	//	} while (!fileSetof->empty());
	//	FindClose(hFind);
	//	return true;
	//}

	//bool TraverseFileSystemA_thread(TexT disk_path, bool callback(TexT, TexT), int thread_number) {
	//	Concurrency::concurrent_queue<string>* fileSetof = traverse_folder(disk_path);
	//	vector<std::thread> threads;
	//	for (int i = 0; i < thread_number; ++i) {
	//		threads.emplace_back(TraverseFileSystemA, fileSetof, callback, thread_number);
	//	}
	//	for (auto& thread : threads) {
	//		thread.join();
	//	}
	//	return true;
	//}
	///*bool TraverseFileSystemA_thread(TexT disk_path, function<bool(TexT, TexT)> callback,int thread_number)
	//{

	//	LPWIN32_FIND_DATAA FindFileData = new WIN32_FIND_DATAA;
	//	
	//	HANDLE hFind = INVALID_HANDLE_VALUE;
	//	queue<string> *fileSetof =new queue<string> ;
	//	if (hFind== INVALID_HANDLE_VALUE)
	//	{
	//		 hFind = FindFirstFileA(ToolString::SplicingStrings({ disk_path ,"\\","*" }).c_str(), FindFileData);
	//	}
	//	std::vector<std::thread*> threads;
	//	for (int i = 0; i < thread_number; i++) {
	//		std::thread* t1 = new std::thread(TraverseFileSystemA_thread_process, FindFileData, disk_path, fileSetof, callback, ref(hFind));
	//		t1->join();
	//	}	

	//	return true;
	//	
	//}*/

	//Concurrency::concurrent_queue<string>* traverse_folder(TexT file_path)
	//{
	//	WIN32_FIND_DATAA FindFileData;
	//	string Flagbit_str(file_path);
	//	Flagbit_str += "*";
	//	HANDLE hFind = FindFirstFileA(Flagbit_str.c_str(), &FindFileData);
	//	Concurrency::concurrent_queue<string>* file_folder = new Concurrency::concurrent_queue<string>();
	//	do
	//	{
	//		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
	//			string result(file_path);
	//			result += FindFileData.cFileName;
	//			file_folder->push(result);
	//		}
	//	} while (FindNextFileA(hFind, &FindFileData));

	//	return file_folder;
	//}



	//bool TraverseFileSystemA_recursion(TexT disk_path, function<bool(TexT, TexT)> callback) {
	//	WIN32_FIND_DATAA FindFileData;
	//	HANDLE hFind = FindFirstFileExA(disk_path, FindExInfoBasic, &FindFileData, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);
	//	std::mutex mtx;
	//	do
	//	{
	//		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..")) {
	//			string next_path;
	//			next_path += disk_path;
	//			next_path.assign(next_path.substr(0, next_path.size() - 1));
	//			next_path+=FindFileData.cFileName;
	//			next_path+="\\*";
	//			TraverseFileSystemA_recursion(next_path.c_str(), callback);
	//		}
	//		callback(disk_path, FindFileData.cFileName);
	//	} while (FindNextFileA(hFind, &FindFileData));
	//	FindClose(hFind);
	//	return true;

	//}

	/*void start_TraverseFileSystemA_recursion(queue<string>* file_path_queue, function<bool(TexT, TexT)> callback) {
	   do
	   {
		   std::cout << file_path_queue->front().c_str() << std::endl;
		   TraverseFileSystemA_recursion(file_path_queue->front().c_str(), callback);
		   file_path_queue->pop();
	   } while (!file_path_queue->empty());

   }*/


   /*bool TraverseFileSystemA_recursion_thread(TexT disk_path, function<bool(TexT, TexT)> callback, int thread_number) {
	   queue<string>* file_path_queue = traverse_folder(disk_path);
	   int equal_division = file_path_queue->size() / thread_number;

	   int end_queue_number = file_path_queue->size() - equal_division * thread_number;

	   queue<queue<string>*> division;

	   for (int i = 0; i < thread_number; i++)
	   {
		   queue<string>* s = new queue<string>;
		   for (int j = 0; j < equal_division; j++)
		   {
			   string s1(file_path_queue->front());
			   s1 += "\\*";
			   s->push(s1);
			   file_path_queue->pop();
		   }
		   division.push(s);
	   }
	   while (file_path_queue->size() != 0) {
		   string s1(file_path_queue->front());
		   s1 += "\\*";
		   division.back()->push(s1);
		   file_path_queue->pop();
	   }

	   vector<std::thread> threads;

	   for (int i = 0; i < thread_number; ++i) {
		   std::queue<std::string>* path_queue = division.front();
		   threads.emplace_back(start_TraverseFileSystemA_recursion, path_queue,callback);
		   division.pop();
	   }

	   for (std::thread& thread : threads) {
		   thread.join();
	   }



	   return true;
   }*/
	//struct PUSN_RECORD_S
	//{
	//	char FileName[MAX_PATH];
	//	FILE_ID_128 FileReferenceNumber;
	//	FILE_ID_128 ParentFileReferenceNumber;
	//};
	//bool TraverseFileSystemA(TexT disk_path, function<bool(TexT, TexT)> callback) {
	//	HANDLE hVol = CreateFileA(disk_path,
	//		GENERIC_READ | GENERIC_WRITE,
	//		FILE_SHARE_READ | FILE_SHARE_WRITE,
	//		NULL,
	//		OPEN_EXISTING,
	//		FILE_ATTRIBUTE_READONLY,
	//		NULL);
	//	CHAR buffer[4096];

	//	DWORD usnDataSize;
	//	MFT_ENUM_DATA_V0 med = {};
	//	PUSN_RECORD UsnRecord;

	//	vector<PUSN_RECORD_S> push_sefof;



	//	while (0 != DeviceIoControl(hVol,
	//		FSCTL_ENUM_USN_DATA,
	//		&med,
	//		sizeof(med),
	//		buffer,
	//		4096,
	//		&usnDataSize,
	//		NULL))
	//	{

	//		DWORD dwRetBytes = usnDataSize - sizeof(USN);
	//		UsnRecord = (PUSN_RECORD)(((PCHAR)buffer) + sizeof(USN));


	//		while (dwRetBytes > 0) {

	//			// 打印获取到的信息  
	//			const int strLen = UsnRecord->FileNameLength;
	//			char fileName[MAX_PATH] = { 0 };
	//			WideCharToMultiByte(CP_OEMCP, NULL, UsnRecord->FileName, strLen / 2, fileName, strLen, NULL, FALSE);
	//			PUSN_RECORD_S s1 = { 0,UsnRecord->FileReferenceNumber,UsnRecord->ParentFileReferenceNumber};
	//			strcpy_s(s1.FileName, fileName);
	//			push_sefof.push_back(s1);
	//			DWORD recordLen = UsnRecord->RecordLength;
	//			dwRetBytes -= recordLen;
	//			UsnRecord = (PUSN_RECORD)(((PCHAR)UsnRecord) + recordLen);

	//		}
	//		med.StartFileReferenceNumber = *(USN*)&buffer;

	//	}
	//	return true;
	//}


}

namespace ToolFile {
	bool createFile(TexT path, TexT name)
	{
		return false;
	}
	bool createFolder(TexT folder_name)
	{
		return CreateDirectoryA(folder_name, NULL);
	}
	bool IsFolderexists(TexT folder_path)
	{
		return filesystem::exists(folder_path);
	}

	void deleteDirectory(const std::string& directoryPath) {
		string searchPath = directoryPath + "\\*";
		WIN32_FIND_DATAA findFileData;
		HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findFileData);

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
					std::string filePath = directoryPath + "\\" + findFileData.cFileName;
					if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
						deleteDirectory(filePath);
					}
					else {
						DeleteFileA(filePath.c_str());
					}
				}
			} while (FindNextFileA(hFind, &findFileData));

			FindClose(hFind);
		}
		RemoveDirectoryA(directoryPath.c_str());
	}
}

