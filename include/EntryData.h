#ifndef ENTRYDATA_H
#define ENTRYDATA_H

#include"Validation.h"

class EntryData
{

public:
    static string getname(){
        string name;
        cout<<"Please Enter Your name(3 - 20)alpha : ";
        cin>>name;
        while(!Validation::validname(name)){
            cout<<"**********************************"<<endl;
            cout << "The name Must Be 3-20 alpha - Try Again\n";
            cin>>name;
        }
        return name;
    }
    //-----------------------------------------
        static string getPassword() {
        string password;
        cout << "Please Enter Your Password (8-20 chars, NO spaces): ";
        cin >> password;
        while (!Validation::validpassword(password)) {
            cout<<"*****************************"<<endl;
            cout << "Invalid Password! Must be 8-20 characters without spaces. Try Again: ";
            cin >> password;
        }
        return password;
    }
    //-------------------------------------------
   static double getWithdrawAmount(double balance) {

       double amount;

       cout << "Enter amount to Withdraw: ";
       cin >> amount;

       while (!Validation::validwithdraw(balance, amount)) {

          cout << "*******************************" << endl;
          cout << "Invalid amount. must be (balance - amount >= 1500) : ";

          cin >> amount;
        }

       return amount;
   }
   //------------------------------------------------
    static double getdebositAmount() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        while (!Validation::validamount(amount)) {
            cout<<"***************************************"<<endl;
            cout << "Invalid amount. must be amount > 0 : ";
            cin >> amount;
        }
        return amount;
    }
    //------------------------------------------------

    static double getAmount() {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;
        while (!Validation::validamount(amount)) {
            cout<<"*******************************"<<endl;
            cout << "Invalid amount. Please enter a positive amount: ";
            cin >> amount;
        }
        return amount;
    }

    static string getCurrency() {
        string curr;
        cout << "Enter currency (ERP , EUR , USD , EGP): ";
        cin >> curr;
        while (!Validation::validcurrency(curr)) {
            cout<<"*******************************"<<endl;
            cout << "Invalid currency. Please enter one of the following (ERP , EUR , USD , EGP)";
            cin >> curr;
        }
        return curr;
    }

};

#endif
