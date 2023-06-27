#pragma once
#include <string>
using namespace std;

class Data
{
public:
	Data();

	Data(string name,float proteinAbsorb, float intakeReq, string time, float weight, int activityLv);

	~Data();

	void  SetData(string name, float proteinAbsorb, float intakeReq, string time, float weight, int activityLv);

	void   SetName(string name);
	string GetName();
	void   SetProteinAbsorbed(float proteinAbsorb);
	float  GetProteinAbsorbed();
	void   SetProteinIntakeReq(float intakeReq);
	float  GetProteinIntakeReq();
	void   SetIntakeTime(string time);
	string GetIntakeTime();
	void   SetWeight(float weight);
	float  GetWeight();
	void   SetActivityLevel(int activityLv);
	int    GetActivityLevel();

private:
	
	string Name;
	float  ProteinAbsorbed;
	float  ProteinIntakeReq;
	string  IntakeTime;
	float  Weight;
	int    ActivityLevel;
};

