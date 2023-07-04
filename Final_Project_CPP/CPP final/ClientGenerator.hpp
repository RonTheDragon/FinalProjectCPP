#pragma once

#include <random>
#include <string>

#include "ClientData.hpp"

class ClientGenerator
{
public:
    ClientGenerator()
        : m_engine{ std::random_device{}() }
    { /* Nothing to do here */ }

    ClientData generate(const std::string& name);

private:
    std::mt19937 m_engine;
};