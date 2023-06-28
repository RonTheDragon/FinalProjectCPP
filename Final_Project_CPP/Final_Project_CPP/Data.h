#pragma once

#include <string>

class Data
{
public:
	Data();

	Data(std::string name, float proteinAbsorb, float intakeReq, std::string time, float weight, int activityLv);

	~Data() = default;

	void  SetData(std::string name, float proteinAbsorb, float intakeReq, std::string time, float weight, int activityLv);

	void   SetName(std::string name);
	std::string GetName();
	void   SetProteinAbsorbed(float proteinAbsorb);
	float  GetProteinAbsorbed();
	void   SetProteinIntakeReq(float intakeReq);
	float  GetProteinIntakeReq();
	void   SetIntakeTime(std::string time);
	std::string GetIntakeTime();
	void   SetWeight(float weight);
	float  GetWeight();
	void   SetActivityLevel(int activityLv);
	int    GetActivityLevel();

private:
	std::string Name;
	float  ProteinAbsorbed;
	float  ProteinIntakeReq;
	std::string  IntakeTime;
	float  Weight;
	int    ActivityLevel;
};