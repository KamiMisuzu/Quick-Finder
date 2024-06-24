#pragma once


#include "Toolibrary.h"
#include "AirDiskStorage.h"



class AirFIleSystem
{
public:
	AirFIleSystem(vector<TexT>& disk_name_vector); 
	~AirFIleSystem();
	bool GetFileSystem();
	bool SelectFile(string file_name);
private:
	AirDiskStorage** diskstrorage = NULL;
	int diskstrorage_size = 0;
};

