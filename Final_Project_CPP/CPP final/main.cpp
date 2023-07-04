#include "ClientGenerator.hpp"
#include "ClientDataBase.hpp"
#include "ClientDashboard.hpp"

int main()
{
    ClientGenerator client_gen;
    ClientDataBase  client_db;
    ClientDashboard client_dash;
    client_db.add_client(client_gen.generate("moshe"));
    client_db.add_client(client_gen.generate("dor"));
    client_db.add_client(client_gen.generate("shmuel"));
    client_dash.display_clients(client_db.get_clients());

    return 0;
}