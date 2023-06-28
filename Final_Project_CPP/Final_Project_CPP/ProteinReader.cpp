#include "ProteinReader.h"

#include <iomanip>
#include <sstream>

Data* ProteinReader::GetData(std::string name)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> absorbDist(50.0f, 150.0f);
	std::uniform_real_distribution<float> intakeDist(0.8f, 1.2f);
	std::uniform_real_distribution<float> weightDist(50.0f, 100.0f);
	std::uniform_int_distribution<int> activityLvDist(1, 3);

	float proteinAbsorb = absorbDist(gen);
	float intakeReq     = intakeDist(gen);
	std::string time    = GenerateRandomTime(gen);
	float weight        = weightDist(gen);
	int activityLv      = activityLvDist(gen);

	return new Data(name, proteinAbsorb, intakeReq, time, weight, activityLv);
}

std::string ProteinReader::GenerateRandomTime(std::mt19937& gen)
{
	std::uniform_int_distribution<int> hourDist(0, 23);
	std::uniform_int_distribution<int> minuteDist(0, 59);

	int hour   = hourDist(gen);
	int minute = minuteDist(gen);

	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute;

	return ss.str();
}