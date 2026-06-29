#ifndef PARSER_H
#define PARSER_H


#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;


class Parser
{
public:
    static vector<string> split(const string& line) {
        vector<string> parts;
        string part = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '-') {
                parts.push_back(part);
                part = "";
            }
            else {
                part += line[i];
            }
        }
        parts.push_back(part);
        return parts;
    }
    //======================================================
    static Client ParseToClient(const string& line){
        vector<string>parts = split(line);

        Client client(stoi(parts[0]),parts[1],parts[2],stod(parts[3]));

        return client;
    }
    //========================================================
    static Employee ParseToEmployee(const string& line){
        vector<string>parts = split(line);

        Employee employee(stoi(parts[0]),parts[1],parts[2],stod(parts[3]));
        return employee;
    }
    //===========================================================
    static Admin ParseToAdmin(const string& line){
        vector<string>parts = split(line);

        Admin admin(stoi(parts[0]),parts[1],parts[2],stod(parts[3]));

        return admin;
    }
};

#endif
