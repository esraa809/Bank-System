
#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include "Admin.h"
#include "EmployeeManager.h"
#include "EntryData.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

class AdminManager {
public:
    static void printAdminMenu() {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Display My Info\n";
        cout << "2. Add New Employee\n";
        cout << "3. List All Employees\n";
        cout << "4. Search For Employee\n";
        cout << "5. Edit Employee Info\n";
        cout << "6. Client Management Menu (Access Employee functions)\n";
        cout << "7. Logout\n";
        cout << "Enter your choice: ";
    }
    //============================================
    static void newEmployee(Admin* admin) {
        string name = EntryData::getname();
        string password = EntryData::getPassword();
        double salary;
        cout << "Enter Salary (Min 5000): ";
        cin >> salary;
        while (!Validation::validsalary(salary)) {
            cout << "Invalid salary! Min 5000: ";
            cin >> salary;
        }

        int nextId = FilesHelper::getlast("EmployeeLastId.txt") + 1;
        Employee emp(nextId, name, password, salary);
        admin->addEmployee(emp);

        FileManager fm;
        fm.addEmployee(emp);
        cout << "\nEmployee Added Successfully! Generated ID is: " << nextId << endl;
    }
    //=================================================

    static void listAllEmployees(Admin* admin) {
        cout << "\n================ Registered Employees ================\n";
        admin->listEmployee();
    }
    //==================================================
    static void searchForEmployee(Admin* admin) {
        int id;
        cout << "Enter Employee ID: ";
        cin >> id;
        Employee* emp = admin->searchEmployee(id);
        if (emp) {
            emp->display();
        } else {
            cout << "\nEmployee not found!\n";
        }
    }
     //==================================================
    static void editEmployeeInfo(Admin* admin) {
        int id;
        cout << "Enter Employee ID to edit: ";
        cin >> id;
        Employee* emp = admin->searchEmployee(id);
        if (emp) {
            string name = EntryData::getname();
            string password = EntryData::getPassword();
            double salary;
            cout << "Enter New Salary: ";
            cin >> salary;
            while (!Validation::validsalary(salary)) {
                cout << "Invalid salary! Min 5000: ";
                cin >> salary;
            }
            admin->editEmployee(id, name, password, salary);
            FileManager::updateEmployee();
            cout << "\nEmployee updated successfully!\n";
        } else {
            cout << "\nEmployee not found!\n";
        }
    }
    //============================================================
    static Admin* login(int id, string password) {
        for (auto& admin : Admin::getAllAdmins()) {
            if (admin.get_id() == id && admin.get_password() == password) {
                return &admin;
            }
        }
        return nullptr;
    }
    //=============================================================
    static bool adminOptions(Admin* admin) {
        printAdminMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                admin->display();
                break;
            case 2:
                newEmployee(admin);
                break;
            case 3:
                listAllEmployees(admin);
                break;
            case 4:
                searchForEmployee(admin);
                break;
            case 5:
                editEmployeeInfo(admin);
                break;
            case 6: {
                bool empLoop = true;
                while (empLoop) {
                    empLoop = EmployeeManager::employeeOptions(admin);
                }
                break;
            }
            case 7:
                return false;
            default:
                cout << "Invalid choice!\n";
        }
        return true;
    }
};

#endif
