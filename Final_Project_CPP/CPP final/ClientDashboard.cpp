#include "ClientDashboard.hpp"

#include <iostream>

void ClientDashboard::display_clients(const std::vector<ClientData>& clients)
{
    for(const auto& client : clients)
    {
        std::cout << "Name:             " << client.name << '\n';
        std::cout << "Protein absorbed: " << client.protein_absorbed << '\n';
        std::cout << "Protein intake:   " << client.protein_intake << '\n';
        std::cout << "Intake time:      " << client.intake_time << '\n';
        std::cout << "Weight:           " << client.weight << '\n';
        std::cout << "Activity level:   " << client.activity_level << '\n';
        std::cout << std::endl;
    }
}