// Final_Project_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Dashboard.h"
#include "Data.h"
#include "ProteinReader.h"
#include "DataBase.h"
#include <iostream>

int main()
{
    ProteinReader protein_reader;
    DataBase database;
    database.ClearData();
    database.AddData(protein_reader.GetData("Ron"));
    database.AddData(protein_reader.GetData("Yossi"));
    DisplayData(database.GetData());
}