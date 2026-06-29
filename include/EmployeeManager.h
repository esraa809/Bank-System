#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include "Client.h"
#include "EntryData.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Display My Info\n";
        cout << "2. Add New Client\n";
        cout << "3. List All Clients\n";
        cout << "4. Search For Client\n";
        cout << "5. Edit Client Info\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
    }
    //===========================================================
    static void newClient(Employee* employee) {
        string name = EntryData::getname();
        string password = EntryData::getPassword();

        double balance;
        cout << "Enter Initial Balance (Min 1500): ";
        cin >> balance;
        while (!Validation::validbalance(balance)) {
            cout << "Invalid balance! Min balance is 1500. Try again: ";
            cin >> balance;
        }

        int nextId = FilesHelper::getlast("ClientLastId.txt") + 1;
        Client newCl(nextId, name, password, balance);

        employee->addClient(newCl); //in employee file
        FileManager fm;
        fm.addClient(newCl);
        cout << "\nClient Added Successfully! Generated ID is: " << nextId << endl;
    }
    //======================================================

    static void listAllClients(Employee* employee) {
        cout << "\n================ Registered Clients ================\n";
        employee->listClient();  //in employee client
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter Client ID to search: ";
        cin >> id;
        Client* client = employee->searchClient(id); //in employee file
        if (client) {
            client->display();
        } else {
            cout << "\nClient not found!\n";
        }
    }
    //=======================================================
    static void editClientInfo(Employee* employee) {
        int id;
        cout << "Enter Client ID to edit: ";
        cin >> id;
        Client* client = employee->searchClient(id);  //in employee search
        if (client) {
            string name = EntryData::getname();
            string password = EntryData::getPassword();
            double balance;
            cout << "Enter New Balance: ";
            cin >> balance;
            while (!Validation::validbalance(balance)) {
                cout << "Invalid balance! Min 1500: ";
                cin >> balance;
            }
            employee->editClient(id, name, password, balance); //in employee file
            FileManager::updateClient();
            cout << "\nClient updated successfully!\n";
        } else {
            cout << "\nClient not found!\n";
        }
    }
    //========================================================
    static Employee* login(int id, string password) {
        for (auto& emp : Employee::getAllEmployees()) {
            if (emp.get_id() == id && emp.get_password() == password) {
                return &emp;
            }
        }
        return nullptr;
    }
    //=======================================================
    static bool employeeOptions(Employee* employee) {
        printEmployeeMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:   //Display My Info
                employee->display();
                break;
            //=============================
            case 2:  //Add New Client
                newClient(employee); // in this file
                break;
            //=============================
            case 3:  //List All Clients
                listAllClients(employee); //in this file
                break;
            //=============================
            case 4:  //Search For Client
                searchForClient(employee); //in this file
                break;
            //==============================
            case 5: //Edit Client Info
                editClientInfo(employee); //in this file
                break;
            //==============================
            case 6:
                return false;
            //==============================
            default:
                cout << "Invalid choice!\n";
        }
        return true;
    }
};

#endif
