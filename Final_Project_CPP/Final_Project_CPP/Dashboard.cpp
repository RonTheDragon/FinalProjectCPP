#include "Dashboard.h"

void DisplayData(const std::vector<Data*>& data)
{
    for (Data* item : data)
    {
        std::cout << "Name: " << item->GetName() << std::endl;
        std::cout << "Protein Absorbed: " << item->GetProteinAbsorbed() << std::endl;
        std::cout << "Protein Intake Req: " << item->GetProteinIntakeReq() << std::endl;
        std::cout << "Intake Time: " << item->GetIntakeTime() << std::endl;
        std::cout << "Weight: " << item->GetWeight() << std::endl;
        std::cout << "Activity Level: " << item->GetActivityLevel() << std::endl;
        std::cout << std::endl;
    }
}
