#ifndef SCREENS_H
#define SCREENS_H

#include <iostream>
#include <stdlib.h>
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "FileManager.h"

using namespace std;

class Screens {
private:

    static void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static void pauseScreen() {
        #ifdef _WIN32
            system("pause");
        #else
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        #endif
    }
    //===============================
public:
    static void bankName() {
        clearScreen();
        cout << "\n               =====================================================\n";
        cout << "               ||                                                 ||\n";
        cout << "               ||                BanK  System                     ||\n";
        cout << "               ||                                                 ||\n";
        cout << "               =====================================================\n";
        pauseScreen();
    }
    //*******************************

    static void welcome() {
        clearScreen();
        cout << "\n                ==================================================\n";
        cout << "                     >> Welcome to Our Secure Bank Application <<   \n";
        cout << "                      We are happy to serve you anytime, anywhere.   \n";
        cout << "                ==================================================\n";
        pauseScreen();
    }
    //********************************
    static void loginOptions() {
        clearScreen();
        cout << "\n==================================================\n";
        cout << "                 MAIN LOGIN MENU                  \n";
        cout << "==================================================\n";
        cout << "1. Login As Client\n";
        cout << "2. Login As Employee\n";
        cout << "3. Login As Admin\n";
        cout << "4. Exit System\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter option: ";
    }
    //*********************************

    static void invalid(int c) {
        clearScreen();
        cout << "\n!!! Invalid option (" << c << ") Try Again !!!\n";
        pauseScreen();
    }
    //*********************************

    static void logout() {
        clearScreen();
        cout << "\n==================================================\n";
        cout << " Logging out... Thank you for using our System!   \n";
        cout << "==================================================\n";
        pauseScreen();
    }
    //***********************************

static void registerScreen(int role) {
    clearScreen();
    string roleName = (role == 1) ? "Client" : (role == 2) ? "Employee" : "Admin";

    cout << "\n==================================================\n";
    cout << "         NEW " << roleName << " REGISTRATION      \n";
    cout << "==================================================\n";
    cout << "[i] Note: Your ID will be generated automatically by the system.\n";
    cout << "==================================================\n\n";

    FileManager fm;

    string name;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    while(!Validation::validname(name)) {
        cout<<"****************************"<<endl;
        cout << "Invalid Name (the name must be alpha from 3 to 20)! "<<endl;
        cout<<"Enter a valid name: ";
        getline(cin, name);
    }


    string password;
    cout << "Enter Password: ";
    cin >> password;
    while(!Validation::validpassword(password)) {
        cout<<"********************************"<<endl;
        cout << "Invalid Password(password must be digit from 8 to 20)"<<endl;
        cout<< "Enter a valid password: ";
        cin >> password;
    }

    if (role == 1) { // Client
        double balance;
        cout << "Enter Balance (Min 1500): ";
        cin >> balance;
        while(!Validation::validbalance(balance)) {
            cout<<"**************************"<<endl;
            cout << "Invalid Balance! Min 1500: ";
            cin >> balance;
        }

        int nextId = FilesHelper::getlast("ClientLastId.txt") + 1;
        Client c(nextId, name, password, balance);
        fm.addClient(c);
        Client::getAllClients().push_back(c);
        cout<<"***********************************"<<endl;
        cout << "\n***[ Registration successful ]***\n";
        cout << "-> Your System Generated ID is: " << nextId << "\n";
    }
    else if (role == 2) { // Employee
        double salary;
        cout << "Enter Salary (Min 5000): ";
        cin >> salary;
        while(!Validation::validsalary(salary)) {
            cout<<"****************************"<<endl;
            cout << " Invalid Salary! Min 5000: ";
            cin >> salary;
        }

        int nextId = FilesHelper::getlast("EmployeeLastId.txt") + 1;
        Employee e(nextId, name, password, salary);
        fm.addEmployee(e);
        Employee::getAllEmployees().push_back(e);
        cout<<"***********************************"<<endl;
        cout << "\n*** [ Registration successful ] ***\n";
        cout << "-> Your System Generated ID is: " << nextId << "\n";
    }
    else if (role == 3) { // Admin
        double salary;
        cout << "Enter Salary (Min 5000): ";
        cin >> salary;
        while(!Validation::validsalary(salary)) {
            cout<<"*********************************"<<endl;
            cout << "[-] Invalid Salary! Min 5000: ";
            cin >> salary;
        }

        int nextId = FilesHelper::getlast("AdminLastId.txt") + 1;
        Admin a(nextId, name, password, salary);
        fm.addAdmin(a);
        Admin::getAllAdmins().push_back(a);
        cout<<"******************************************"<<endl;
        cout << "\n*** [ Admin Registration successful ] ***\n";
        cout << "-> Your System Generated Admin ID is: " << nextId << "\n";
    }
    cout<<"================================"<<endl;
    cout << "-> Please login again using this new ID and your password.\n";
    pauseScreen();
}
//=======================================================
static void loginScreen(int c) {
    while (true) {
        clearScreen();
        string roleName = (c == 1) ? "Client" : (c == 2) ? "Employee" : "Admin";
        cout << "\n==================================================\n";
        cout << "              " << roleName << " LOGIN SCREEN             \n";
        cout << "==================================================\n";

        int id;
        string pass;
        cout << "Enter ID(must be digit) : ";
        cin >> id;
        cout << "Enter Password(must be digit min 8 max 20)  : ";
        cin >> pass;

        bool loginSuccess = false;
        // if entry is true
        if (c == 1) {
            Client* client = ClientManager::login(id, pass);
            if (client) {
                bool loop = true;
                while (loop) {
                    clearScreen();
                    loop = ClientManager::clientOptions(client);
                    if(loop) pauseScreen();
                }
                logout();
                return;
            }
        }
        else if (c == 2) {
            Employee* emp = EmployeeManager::login(id, pass);
            if (emp) {
                bool loop = true;
                while (loop) {
                    clearScreen();
                    loop = EmployeeManager::employeeOptions(emp);
                    if(loop) pauseScreen();
                }
                logout();
                return;
            }
        }
        else if (c == 3) {
            Admin* admin = AdminManager::login(id, pass);
            if (admin) {
                bool loop = true;
                while (loop) {
                    clearScreen();
                    loop = AdminManager::adminOptions(admin);
                    if(loop) pauseScreen();
                }
                logout();
                return;
            }
        }

        clearScreen();
        // if entry false

        cout << "\n==================================================\n";
        cout << "[-] ERROR: Invalid ID or Password, or Account doesn't exist!\n";
        cout << "-> There Are Three Option Of You \n";

        cout << "==================================================\n\n";

        cout << "         1- Try Login Again\n";
        cout << "         2- Register a New Account\n";
        cout << "         3- Return to Main Menu\n\n";
        cout << "          Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            continue;
        }
        else if (choice == 2) {

            clearScreen();
            cout << "\n==================================================\n";
            cout << "               REGISTRATION MENU                  \n";
            cout << "==================================================\n\n";
            cout << "         1- Register as Client\n";
            cout << "         2- Register as Employee\n";
            cout << "         3- Register as Admin\n\n";
            cout << "          Enter your choice: ";
            int regRole;
            cin >> regRole;

            if (regRole >= 1 && regRole <= 3) {
                registerScreen(regRole);
            } else {
                cout << "\n[-] Invalid Choice!\n";
                pauseScreen();
            }
        }
        else if (choice == 3) {
            return;
        }
    }
}
//========================================================

    static void runApp() {
        FileManager::getAllData(); // push back to object in vector

        bankName();
        welcome();

        while (true) {
            loginOptions();  //log as client/employee/admin
            int choice;
            cin >> choice;

            if (choice >= 1 && choice <= 3) {
                loginScreen(choice);
            } else if (choice == 4) {
                clearScreen();
                cout << "\n==================================================\n";
                cout << "     Shutting down bank system. Goodbye!          \n";
                cout << "==================================================\n";
                break;
            } else {
                invalid(choice);
            }
        }
    }
};

#endif
