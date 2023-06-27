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
    dtb.ClearData();
    dtb.AddData(pr.GetData("Ron"));
    dtb.AddData(pr.GetData("Yossi"));
    db.DisplayData(dtb.GetData());
}

