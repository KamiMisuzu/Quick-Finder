// Istimestamp1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <Windows.h>
#include <iostream>
#include <sqlite3.h>

#pragma comment(lib,"sqlite3.lib")
int WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    sqlite3* db_Control;
    sqlite3_stmt* stmt = nullptr;
    int result = time(nullptr);
    sqlite3_open(".\\db\\C.db", &db_Control);
    sqlite3_prepare_v2(db_Control,"select name from table_name", -1,&stmt,nullptr);
    sqlite3_step(stmt);
    int desc_result = sqlite3_column_int(stmt, 0);
    std::cout << result - desc_result;
    return 1;
}