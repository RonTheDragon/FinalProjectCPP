#pragma once

#include <vector>

#include "ClientData.hpp"

class ClientDataBase
{
public:
    void add_client(const ClientData& client);
    std::vector<ClientData> get_clients();
};