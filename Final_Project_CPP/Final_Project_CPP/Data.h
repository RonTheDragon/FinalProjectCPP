#pragma once
class Data
{
public:
	Data();

	Data(float proteinAbsorb, float intakeReq, float time, float weight, int activityLv);

	~Data();

	void  SetData(float proteinAbsorb, float intakeReq, float time, float weight, int activityLv);

	void  SetProteinAbsorbed(float proteinAbsorb);
	float GetProteinAbsorbed();
	void  SetProteinIntakeReq(float intakeReq);
	float GetProteinIntakeReq();
	void  SetIntakeTime(float time);
	float GetIntakeTime();
	void  SetWeight(float weight);
	float GetWeight();
	void  SetActivityLevel(int activityLv);
	int   GetActivityLevel();

private:
	float ProteinAbsorbed;
	float ProteinIntakeReq;
	float IntakeTime;
	float Weight;
	int   ActivityLevel;
};

