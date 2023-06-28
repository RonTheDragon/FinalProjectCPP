#pragma once

#include <random>
#include <string>

#include "Data.h"

class ProteinReader
{
public:
	ProteinReader() = default;
	~ProteinReader() = default;

	Data* GetData(std::string name);

private:
	std::string GenerateRandomTime(std::mt19937& gen);
};