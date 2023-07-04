#include "ClientDataBase.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/* JSON, value offset */
#define VALUE_OFFSET 2

/* New client insert offset */
#define INSERT_OFFSET 1

/* Utility functions--------------------------------------------------------- */
/* NOTE: These functions make our add_client and get_clients functions more
         readable */

bool file_is_empty(std::fstream& io_file)
{
    /* Move the get pointer to the end of the file */
    io_file.seekg(0, std::ios::end);

    /* Get the current position of the get pointer */
    std::streampos position = io_file.tellg();

    /* If its 0 the file is empty */
    return position == 0;
}

std::string serialize_client(const ClientData& client)
{
    /* Read the client's fields into a formatted string stream
       and convert it to a string before returning */
    std::ostringstream oss;
    oss << "\t\t{\n";
    oss << "\t\t\t\"name\": \"" << client.name << "\",\n";
    oss << "\t\t\t\"protein_absorbed\": " << client.protein_absorbed << ",\n";
    oss << "\t\t\t\"protein_intake\": " << client.protein_intake << ",\n";
    oss << "\t\t\t\"intake_time\": \"" << client.intake_time << "\",\n";
    oss << "\t\t\t\"weight\": " << client.weight << ",\n";
    oss << "\t\t\t\"activity_level\": " << client.activity_level << "\n";
    oss << "\t\t}\n";
    return oss.str();
}

std::string read_file(std::fstream& io_file)
{
    /* Move the get pointer to the beginning of the file */
    io_file.seekg(0, std::ios::beg);

    /* Read the entire file into a string stream */
    std::ostringstream oss;
    oss << io_file.rdbuf();

    /* Convert the string stream into a string and return */
    return oss.str();
}

void insert_client(std::string& out, const ClientData& client)
{
    /* Find the last client's closing bracket */
    size_t found_pos = out.find("}\n");

    /* Prepend a ',' and newline to the new client entry */
    std::string new_entry = ",\n" + serialize_client(client);

    /* Insert the new entry by replacing the newline after
       the last client's closing bracket with our new entry */
    out.replace(found_pos + INSERT_OFFSET, 1, new_entry);
}

void replace_file_content(const std::string& new_content, std::fstream& io_file)
{
    /* Open the file in output mode and truncating it */
    io_file.open("data.txt", std::ios::trunc | std::ios::out);
    if(io_file.is_open())
    {
        /* Write the new content and close the file */
        io_file << new_content;
        io_file.close();
    }
    else
    {
        std::cout << "Failed to open data.txt for new content" << std::endl;
    }
}

std::string& extract_string(std::ifstream& i_file, std::string& line)
{
    /* Read the entire line containing the string */
    std::getline(i_file, line);

    /* Cut everything out until the string */
    line = line.substr(line.find(':') + VALUE_OFFSET);

    /* Remove the double quotes around the string */
    line.erase(std::remove(line.begin(), line.end(), '\"'), line.end());

    /* Remove the ',' at the end */
    line.pop_back();

    /* Return the string */
    return line;
}

float extract_float(std::ifstream& i_file, std::string& line)
{
    /* Read the entire line containing the float */
    std::getline(i_file, line);

    /* Cut everything out until the float */
    line = line.substr(line.find(':') + VALUE_OFFSET);

    /* Remove the ',' at the end */
    line.pop_back();

    /* Convert the string to float and return */
    return std::stof(line);
}

int extract_int(std::ifstream& i_file, std::string& line)
{
    /* Read the entire line containing the int */
    std::getline(i_file, line);

    /* Cut everything out until the int */
    line = line.substr(line.find(':') + VALUE_OFFSET);

    /* Convert the string to int and return */
    return std::stoi(line);
}

/* Member function implementation-------------------------------------------- */

void ClientDataBase::add_client(const ClientData& client)
{
    std::fstream io_file("data.txt", std::ios::in | std::ios::out);
    if(io_file.is_open())
    {
        if(file_is_empty(io_file))
        {
            io_file << "{\n";
            io_file << "\t\"clients\": [\n";
            io_file << serialize_client(client);
            io_file << "\t]\n";
            io_file << "}";
            io_file.close();
        }
        else
        {
            std::string file_content = read_file(io_file);
            io_file.close();

            insert_client(file_content, client);
            replace_file_content(file_content, io_file);
        }
    }
    else
    {
        std::cout << "Failed to open data.txt for adding client" << std::endl;
    }
}

std::vector<ClientData> ClientDataBase::get_clients()
{
    std::ifstream i_file("data.txt", std::ios::in);
    std::vector<ClientData> clients;
    std::string line = "";
    if(i_file.is_open())
    {
        while(std::getline(i_file, line))
        {
            /* We reached a client data block */
            if(line == "\t\t{")
            {
                ClientData client;
                client.name             = extract_string(i_file, line);
                client.protein_absorbed = extract_float(i_file, line);
                client.protein_intake   = extract_float(i_file, line);
                client.intake_time      = extract_string(i_file, line);
                client.weight           = extract_float(i_file, line);
                client.activity_level   = extract_int(i_file, line);
                clients.push_back(client);
            }
        }

        i_file.close();
    }
    else
    {
        std::cout << "Failed to open data.txt for reading clients" << std::endl;
    }

    return clients;
}