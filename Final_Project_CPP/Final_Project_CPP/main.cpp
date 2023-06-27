// Final_Project_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Dashboard.h"
#include "Data.h"
#include "ProteinReader.h"
#include "DataBase.h"
#include <iostream>

int main()
{
    Dashboard db;
    ProteinReader pr;
    DataBase dtb;
    std::vector<Data*> dataVector;
    dtb.ClearData();
    dtb.AddData(pr.GetData("Ron"));
    dtb.AddData(pr.GetData("Yossi"));
    //db.DisplayData(dtb.GetData());
    dtb.GetData();

    //dataVector.push_back(pr.GetData("Ron"));
    //dataVector.push_back(pr.GetData("Yossi"));
   // db.DisplayData(dataVector);

    // Clean up allocated memory
    for (Data* data : dataVector) {
        delete data;
    }
}

