#pragma once

#include <string>

struct ClientData
{
    std::string name             = "";
    float       protein_absorbed = 0.0f;
    float       protein_intake   = 0.0f;
    std::string intake_time      = "";
    float       weight           = 0.0f;
    int         activity_level   = 0;
};