#pragma once

#include "AirSqliteManagement.h"
#include "Toolibrary.h"




class AirDiskStorage
{
public:

public:

	AirDiskStorage(TexT disk_name);
	~AirDiskStorage();
	TexT GetdiskName();
	bool ergodic();
	bool selectData(string file_name);

private:
	bool init_db();
	bool initprepare_sql();
	Concurrency::concurrent_queue<string>* traverse_folder(TexT file_path);
	bool TraverseFileSystemA(Concurrency::concurrent_queue<string>* fileSetof, int thread_number);
	bool TraverseFileSystemA_thread(TexT disk_path,int thread_number);

private:
	AirSqliteManagement* sqlite_management;
	TexT disk_name; //当前磁盘名
	string table_name; //
	string initial_path; //初始路径
	string db_path;
	int number_of_files; // 文件数量
	int number_of_folders; //文件夹数量
	mutex mtx1;
	mutex mtx2;
	condition_variable g_cv;
	int comment_sql = 0;


};

