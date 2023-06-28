#include "DataBase.h"

#include <iostream>
#include <fstream>

#include "Data.h"

void DataBase::AddData(Data* data)
{
    // Open the file in append mode
    std::fstream io_file("data.txt", std::ios::app);

    if(io_file.is_open())
    {
        // If the file is empty, add the opening square bracket
        if(io_file.peek() == EOF)
        {
            io_file << "[\n";
        }
        // If the file is not empty, remove the last character (closing square bracket)
        else
        {
            // Read the file content
            std::string file_content = "";
            io_file >> file_content;
            io_file.close();

            // Remove the last character (closing square bracket)
            file_content.pop_back();

            // Append "," and new line
            file_content.append(",\n");


            // Truncate the file, and write new content
            io_file.open("data.txt", std::ios_base::trunc | std::ios_base::out);
            io_file << file_content;
        }

        // Write the new data entry
        io_file << "\t{\n";
        io_file << "\t\t\"Name\": \"" << data->GetName() << "\",\n";
        io_file << "\t\t\"ProteinAbsorbed\": " << data->GetProteinAbsorbed() << ",\n";
        io_file << "\t\t\"ProteinIntakeReq\": " << data->GetProteinIntakeReq() << ",\n";
        io_file << "\t\t\"IntakeTime\": \"" << data->GetIntakeTime() << "\",\n";
        io_file << "\t\t\"Weight\": " << data->GetWeight() << ",\n";
        io_file << "\t\t\"ActivityLevel\": " << data->GetActivityLevel() << "\n";
        io_file << "\t}\n";
        io_file << "]";
        io_file.close();
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
                    delete dataEntry;
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
    std::ofstream o_file("data.txt", std::ios::trunc);
    if (o_file.is_open())
    {
        o_file.close();
    }
    else
    {
        std::cout << "Failed to open file for clearing." << std::endl;
    }
}