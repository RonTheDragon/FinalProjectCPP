#pragma once

#include <vector>

#include "ClientData.hpp"

class ClientDashboard
{
public:
    void display_clients(const std::vector<ClientData>& clients);
};