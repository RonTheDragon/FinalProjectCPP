#include "Data.h"

Data::Data() : ProteinAbsorbed(0), ProteinIntakeReq(0), IntakeTime(0), Weight(0), ActivityLevel(0)
{
}

Data::Data(float proteinAbsorb, float intakeReq, float time, float weight, int activityLv) :
	ProteinAbsorbed(proteinAbsorb), ProteinIntakeReq(intakeReq), IntakeTime(time), Weight(weight), ActivityLevel(activityLv)
{
}



Data::~Data()
{
}

void Data::SetProteinAbsorbed(float proteinAbsorb)
{
	ProteinAbsorbed = proteinAbsorb;
}

float Data::GetProteinAbsorbed()
{
	return ProteinAbsorbed;
}

void Data::SetProteinIntakeReq(float intakeReq)
{
	ProteinIntakeReq = intakeReq;
}

float Data::GetProteinIntakeReq()
{
	return ProteinIntakeReq;
}

void Data::SetIntakeTime(float time)
{
	IntakeTime = time;
}

float Data::GetIntakeTime()
{
	return IntakeTime;
}

void Data::SetWeight(float weight)
{
	Weight = weight;
}

float Data::GetWeight()
{
	return Weight;
}

void Data::SetActivityLevel(int activityLv)
{
	ActivityLevel = activityLv;
}

int Data::GetActivityLevel()
{
	return ActivityLevel;
}
