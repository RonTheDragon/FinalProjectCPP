#include "ProteinReader.h"

ProteinReader::ProteinReader()
{
}

ProteinReader::~ProteinReader()
{
}

Data* ProteinReader::GetData(string name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> absorbDist(50.0, 150.0);
	uniform_real_distribution<float> intakeDist(0.8, 1.2);
	uniform_real_distribution<float> weightDist(50.0, 100.0);
	uniform_int_distribution<int> activityLvDist(1, 3);

	float proteinAbsorb = absorbDist(gen);
	float intakeReq = intakeDist(gen);
	string time = GenerateRandomTime(gen);
	float weight = weightDist(gen);
	int activityLv = activityLvDist(gen);

	return new Data(name, proteinAbsorb, intakeReq, time, weight, activityLv);
}

string ProteinReader::GenerateRandomTime(mt19937& gen)
{
	uniform_int_distribution<int> hourDist(0, 23);
	uniform_int_distribution<int> minuteDist(0, 59);

	int hour = hourDist(gen);
	int minute = minuteDist(gen);

	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute;

	return ss.str();
}
