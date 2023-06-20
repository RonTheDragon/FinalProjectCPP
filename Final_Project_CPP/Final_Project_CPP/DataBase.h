#pragma once
#include <vector>
#include "Data.h"
class DataBase
{
public:
	DataBase();

	~DataBase();

	void AddData(Data);

	std::vector<Data> GetData();


	void ClearData();

};

