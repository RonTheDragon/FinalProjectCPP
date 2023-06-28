#include "Data.h"

Data::Data() : Name(""), ProteinAbsorbed(0), ProteinIntakeReq(0), IntakeTime("00:00"), Weight(0), ActivityLevel(0)
{
}

Data::Data(std::string name, float proteinAbsorb, float intakeReq, std::string time, float weight, int activityLv) :
	Name(name), ProteinAbsorbed(proteinAbsorb), ProteinIntakeReq(intakeReq), IntakeTime(time), Weight(weight), ActivityLevel(activityLv)
{
}

void Data::SetData(std::string name, float proteinAbsorb, float intakeReq, std::string time, float weight, int activityLv)
{
	Name = name;
	ProteinAbsorbed = proteinAbsorb;
	ProteinIntakeReq = intakeReq;
	IntakeTime = time;
	Weight = weight;
	ActivityLevel = activityLv;
}

void Data::SetName(std::string name)
{
	Name = name;
}

std::string Data::GetName()
{
	return Name;
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

void Data::SetIntakeTime(std::string time)
{
	IntakeTime = time;
}

std::string Data::GetIntakeTime()
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