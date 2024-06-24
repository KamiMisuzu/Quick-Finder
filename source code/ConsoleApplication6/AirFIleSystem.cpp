#include "AirFIleSystem.h"

AirFIleSystem::AirFIleSystem(vector<TexT>& disk_name_vector)
{

	diskstrorage_size = disk_name_vector.size();
	this->diskstrorage = new AirDiskStorage*[diskstrorage_size];

	for (int i = 0;i< diskstrorage_size;i++)
	{
		this->diskstrorage[i] = new AirDiskStorage(disk_name_vector[i]);
	}

}

AirFIleSystem::~AirFIleSystem()
{
	delete[] this->diskstrorage;
}

bool AirFIleSystem::GetFileSystem()
{
	for (int i =0;i< diskstrorage_size;i++)
	{
		diskstrorage[i]->ergodic();
	}
	return true;
}

bool AirFIleSystem::SelectFile(string file_name)
{
	for (int i = 0; i < diskstrorage_size; i++)
	{
		diskstrorage[i]->selectData(file_name);
	}
	return true;
}

