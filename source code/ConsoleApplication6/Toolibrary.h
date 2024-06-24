#pragma once
#include <windows.h>
#include <iostream>
#include <queue>
#include <vector>
#include <fileapi.h>
#include <chrono>
#include <sqlite3.h>
#include <string>
#include <functional>
#include <initializer_list>
#include <filesystem>
#include <thread>
#include <mutex>
#include <concurrent_queue.h>
#include <winioctl.h>
#include <ctime>
#include <locale>
#include <codecvt>
using namespace std;



const int max_path = MAX_PATH + 1;




typedef const char* TexT;


namespace ToolString {
	/*!
	 * @brief SplicingStrings->拼接所有传入的字符串
	 * @param args 字符串集合
	 */
	string SplicingStrings(initializer_list<TexT> args);
	string Cutflagstring(TexT str, int number,char* flag);
}

namespace ToolDisk {
	/*!
	 * @brief GetLocalDiskName->获取本地磁盘名
	 * @param isEmpty 是否获取空名磁盘名
	 */
	vector<TexT>& GetLocalDiskName(bool isEmpty);
	
	string GetCurrentPath();
}
namespace ToolNTFS {
	//Concurrency::concurrent_queue<string>* traverse_folder(TexT file_path);
	//bool TraverseFileSystemA_thread(TexT disk_path, bool callback(TexT, TexT), int thread_number);
	//bool TraverseFileSystemA(TexT disk_path, function<bool(TexT, TexT)> callback);
	//bool TraverseFileSystemA(Concurrency::concurrent_queue<string>* fileSetof, bool callback(TexT, TexT), int thread_number);
	//bool TraverseFileSystemA_thread(TexT disk_path, function<bool(TexT, TexT)> callback, int thread_number);
	//static bool TraverseFileSystemA_thread_process(LPWIN32_FIND_DATAA FindFileData, TexT disk_path, queue<string>* fileSetof,
	//function<bool(TexT, TexT)> callback, HANDLE& hFind);
	//bool TraverseFileSystemA_recursion(TexT disk_path, bool callback(TexT, TexT) );
	
	//bool TraverseFileSystemA_recursion(TexT disk_path, function<bool(TexT, TexT)> callback);
	//bool TraverseFileSystemA_recursion_thread(TexT disk_path, function<bool(TexT, TexT)> callback, int thread_number);


	//bool TraverseFileSystemA(TexT disk_path, function<bool(char*, char*)> callback);
}

namespace ToolFile {
	bool createFile(TexT path, TexT name);
	bool createFolder(TexT folder_name);
	bool IsFolderexists(TexT folder_path);
	void deleteDirectory(const std::string& directoryPath);
}







