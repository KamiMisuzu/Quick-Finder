#include "AirSqliteManagement.h"

AirSqliteManagement::AirSqliteManagement(string db_path,string db_name):db_name(db_name),sql("SELECT sqlite_version();")
{
	this->db_path.assign(db_path);
	/*sqlite3_exec(db_Control, "PRAGMA encoding = \"UTF-8\";", nullptr, nullptr, nullptr);*/
}

AirSqliteManagement::~AirSqliteManagement() 
{
	sqlite3_close(this->db_Control);
}


TexT AirSqliteManagement::GetSql() noexcept
{
	return sql.c_str();
}

bool AirSqliteManagement::execSql(TexT t) noexcept
{
	char** error = NULL;

	sqlite3_exec(db_Control, t, NULL, NULL, error);
	
	if (error!=NULL)
	{
		addErrmsg(*error);
		return false;
	}
	return true;
}

string AirSqliteManagement::Getdb_path()
{
	return db_path;
}

sqlite3& AirSqliteManagement::GetdbControl()
{
	return *db_Control;
}

bool AirSqliteManagement::sql_prepare_v2(TexT sql, sqlite3_stmt** stmt)
{
	sqlite3_prepare_v2(db_Control, sql, -1, &(*stmt), nullptr);
	OutputDebugStringA(sqlite3_errmsg(db_Control));
	return true;
}



bool AirSqliteManagement::addErrmsg(TexT errorText)
{
	zErrMsg.push(errorText);
	return true;
}


