#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "Client.h"
#include "EntryData.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

class ClientManager {
public:
    static void printClientMenu() {
        cout << "\n=== Client Menu ===\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Transfer To\n";
        cout << "5. Update Password\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
    }
    //===================================================

    static void updatePassword(Person* person) {
        string newPass = EntryData::getPassword();
        person->set_password(newPass);

        FileManager::updateClient();
        cout << "\nPassword updated successfully!\n";
    }
    //===================================================
    static Client* login(int id, string password) {
        for (auto& client : Client::getAllClients()) {
            if (client.get_id() == id && client.get_password() == password) {
                return &client;
            }
        }
        return nullptr;
    }
    //==================================================

    static bool clientOptions(Client* client) { //use pointer in parameter to direct update in client data
        printClientMenu();
        int choice;
        cin >> choice;
        cout<<"------------------------------"<<endl;
        switch (choice) {
            case 1: {  //deposit
                double amount = EntryData::getdebositAmount();
                client->debosit(amount);
                FileManager::updateClient();
                cout<<"********************************"<<endl;
                cout << "Deposited successfully!\n";
                break;
            }
            case 2: {  //withdraw
                double amount = EntryData::getWithdrawAmount(client->get_balance());
                client->withdraw(amount);
                FileManager::updateClient();
                cout<<"************************************"<<endl;
                cout << "Withdrawn successfully!\n";
                break;
            }
            case 3:  //check balance
                client->check_balance();
                break;
            case 4: {  //transfar to
                int targetId;
                cout << "Enter target Client ID: ";
                cin >> targetId;

                Client* target = nullptr;
                for (auto& c : Client::getAllClients()) {
                    if (c.get_id() == targetId) {
                        target = &c;
                        break;
                    }
                }
                if (target && target->get_id() != client->get_id()) {
                    double amount = EntryData::getAmount();
                    if (client->transfarto(*target, amount).first) {
                        FileManager::updateClient();
                        cout<<"*******************************"<<endl;
                        cout << "Transfer successful!\n";
                    } else {
                        cout<<"***************************"<<endl;
                        cout << "Transfer failed! Check amount or minimum balance constraint.\n";
                    }
                } else {
                    cout<<"**************************************"<<endl;
                    cout << "Target client not found or invalid!\n";
                }
                break;
            }
            //====================================================
            case 5: //update password
                updatePassword(client);   //in this file
                break;
            //====================================================
            case 6: //logout
                return false;
            //=====================================================
            default:
                cout<<"************************"<<endl;
                cout << "Invalid choice!\n";
            //======================================================
        }
        return true;
    }
};

#endif
