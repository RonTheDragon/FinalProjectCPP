#include "DataBase.h"
#include <fstream>
#include "Data.h"
#include <iostream>

DataBase::DataBase()
{
}

DataBase::~DataBase()
{
}

void DataBase::AddData(Data* data)
{
    // Open the file in append mode
    std::ofstream outputFile("data.txt", std::ios_base::app);
    if (outputFile.is_open())
    {
        // Check if the file is empty
        outputFile.seekp(0, std::ios::end);
        bool isEmpty = (outputFile.tellp() == 0);

        // If the file is empty, add the opening square bracket
        if (isEmpty)
        {
            outputFile << "[\n";
        }
        // If the file is not empty, remove the last character (closing square bracket)
        else
        {
            outputFile.close();

            // Read the file content
            std::ifstream inputFile("data.txt");
            std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
                std::istreambuf_iterator<char>());
            inputFile.close();

            // Remove the last character (closing square bracket)
            fileContent.pop_back();

            // Reopen the file in write mode and overwrite the content
            outputFile.open("data.txt", std::ios_base::out | std::ios_base::trunc);
            outputFile << fileContent;
            outputFile << ",\n";
        }

        // Write the new data entry
        outputFile << "\t{\n";
        outputFile << "\t\t\"Name\": \"" << data->GetName() << "\",\n";
        outputFile << "\t\t\"ProteinAbsorbed\": " << data->GetProteinAbsorbed() << ",\n";
        outputFile << "\t\t\"ProteinIntakeReq\": " << data->GetProteinIntakeReq() << ",\n";
        outputFile << "\t\t\"IntakeTime\": \"" << data->GetIntakeTime() << "\",\n";
        outputFile << "\t\t\"Weight\": " << data->GetWeight() << ",\n";
        outputFile << "\t\t\"ActivityLevel\": " << data->GetActivityLevel() << "\n";
        outputFile << "\t}\n";
        outputFile << "]";

        outputFile.close();
    }
    else
    {
        std::cout << "Failed to open file for writing." << std::endl;
    }
}

std::vector<Data*> DataBase::GetData()
{
    std::ifstream inputFile("data.txt");
    if (inputFile.is_open())
    {
        char c;
        std::string name = "";
        float proteinAbsorb = 0;
        float intakeReq = 0;
        std::string time = "00:00";
        float weight = 0;
        int activityLv = 0;
        std::vector<Data*> dataEntries;
        Data* dataEntry = nullptr;

        std::string trash = "";

        while (inputFile.get(c))
        {
            // Process each character of the file here
            if (c == '{')
            {
                dataEntry = new Data();
            }
            else if (c == '}')
            {
                if (dataEntry != nullptr)
                {
                    dataEntries.push_back(dataEntry);
                    dataEntry = nullptr;
                }
            }
            else if (dataEntry != nullptr)
            {
                if (c == '\"')
                {
                    std::string key;
                    std::getline(inputFile, key, '\"');

                    if (key == "Name")
                    {
                        std::getline(inputFile, trash, '\"');
                        
                        std::getline(inputFile, name, '\"');
                        dataEntry->SetName(name);
                       // std::cout << name;
                    }
                    else if (key == "ProteinAbsorbed")
                    {
                        std::getline(inputFile, trash, ':');
                        inputFile >> proteinAbsorb;
                        dataEntry->SetProteinAbsorbed(proteinAbsorb);
                       // std::cout << proteinAbsorb;
                    }
                    else if (key == "ProteinIntakeReq")
                    {
                        std::getline(inputFile, trash, ':');
                        inputFile >> intakeReq;
                        dataEntry->SetProteinIntakeReq(intakeReq);
                       // std::cout << intakeReq;
                    }
                    else if (key == "IntakeTime")
                    {
                        std::getline(inputFile, trash, '\"');
                        std::getline(inputFile, time, '\"');
                        dataEntry->SetIntakeTime(time);
                       // std::cout << time;
                    }
                    else if (key == "Weight")
                    {
                        std::getline(inputFile, trash, ':');
                        inputFile >> weight;
                        dataEntry->SetWeight(weight);
                       // std::cout << weight;
                    }
                    else if (key == "ActivityLevel")
                    {
                        std::getline(inputFile, trash, ':');
                        inputFile >> activityLv;
                        dataEntry->SetActivityLevel(activityLv);
                       // std::cout << activityLv;
                    }
                }
            }
        }

        inputFile.close();
        return dataEntries;
    }
    else
    {
        std::cout << "Failed to open file for reading." << std::endl;
        return std::vector<Data*>();
    }
}



void DataBase::ClearData()
{
    std::ofstream outputFile("data.txt", std::ios::trunc);
    if (outputFile.is_open())
    {
        outputFile.close();
    }
    else
    {
        std::cout << "Failed to open file for clearing." << std::endl;
    }
}
