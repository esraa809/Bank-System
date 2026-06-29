#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    void addClient(Client obj) override{
        FilesHelper::saveClient(obj);
    }

    //================================================

    void addEmployee(Employee obj) override{
        FilesHelper::saveEmployee(
            "Employee.txt",
            "EmployeeLastId.txt",
            obj
        );
    }

    //================================================

    void addAdmin(Admin obj) override{
        FilesHelper::saveEmployee(
            "Admin.txt",
            "AdminLastId.txt",
            obj
        );
    }

    //================================================

    void getAllClients() override{
        FilesHelper::getClient();
    }

    //================================================

    void getAllEmployees() override{
        FilesHelper::getEmployee();
    }

    //================================================

    void getAllAdmins() override{
        FilesHelper::getAdmin();
    }

    //=================================================

    void removeAllClients() override{
        FilesHelper::clearfile(
            "Client.txt",
            "ClientLastId.txt"
        );
    }

    //=================================================

    void removeAllEmployees() override{
        FilesHelper::clearfile(
            "Employee.txt",
            "EmployeeLastId.txt"
        );
    }

    //=================================================

    void removeAllAdmins() override{
        FilesHelper::clearfile(
            "Admin.txt",
            "AdminLastId.txt"
        );
    }

    //=================================================

    static void getAllData(){

        FilesHelper::getClient();

        FilesHelper::getEmployee();

        FilesHelper::getAdmin();
    }

    //=================================================

    static void updateClient(){

        FileManager fm;

        fm.removeAllClients();

        vector<Client>& AllClients =
            Client::getAllClients();

        for(ClientIt = AllClients.begin();ClientIt != AllClients.end();ClientIt++)
        {
            fm.addClient(*ClientIt);
        }
    }

    //=================================================

    static void updateEmployee(){

        FileManager fm;

        fm.removeAllEmployees();

        vector<Employee>& AllEmployees = Employee::getAllEmployees();

        for(EmployeeIt = AllEmployees.begin();EmployeeIt != AllEmployees.end();EmployeeIt++)
        {
            fm.addEmployee(*EmployeeIt);
        }
    }

    //=================================================

    static void updateAdmin(){

        FileManager fm;

        fm.removeAllAdmins();

        vector<Admin>& AllAdmins = Admin::getAllAdmins();

        for(AdminIt = AllAdmins.begin();AdminIt != AllAdmins.end();AdminIt++)
        {
            fm.addAdmin(*AdminIt);
        }
    }

    //=================================================
};

#endif
