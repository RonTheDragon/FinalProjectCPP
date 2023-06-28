#pragma once
#include <vector>
#include "Data.h"

class DataBase
{
public:
	DataBase() = default;
	~DataBase() = default;

	void               AddData(Data*);
	std::vector<Data*> GetData();
	void               ClearData();
};