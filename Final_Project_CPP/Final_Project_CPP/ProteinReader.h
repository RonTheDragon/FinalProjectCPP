#pragma once
#include "Data.h"
#include <random>
#include <sstream>
#include <iomanip>
class ProteinReader
{
public:

	ProteinReader();

	~ProteinReader();

	Data* GetData(string name);

private:
	string GenerateRandomTime(mt19937& gen);
};

