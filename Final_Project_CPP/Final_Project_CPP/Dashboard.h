#pragma once
#include <iostream>
#include <vector>
#include "Data.h"
class Dashboard
{
public:
	Dashboard();

	~Dashboard();

	void DisplayData(const std::vector<Data*>& data);
};

