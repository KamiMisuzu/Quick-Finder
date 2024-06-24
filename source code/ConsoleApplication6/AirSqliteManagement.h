#pragma once

#include <sqlite3.h>
#include "Toolibrary.h"

#pragma comment(lib,"sqlite3.lib")



class AirSqliteManagement
{
public:
	AirSqliteManagement(string db_path,string db_name);
	~AirSqliteManagement() noexcept;
public:
	sqlite3* db_Control;
	TexT GetSql() noexcept;
	bool execSql(TexT t) noexcept;
	string Getdb_path();
	sqlite3& GetdbControl();
	bool sql_prepare_v2(TexT sql,sqlite3_stmt** stmt);

private:
	bool addErrmsg(TexT errorText);

private:
	
	string db_name;
	string db_path;
	string sql;
	int rc;
	queue<TexT> zErrMsg;	
};

