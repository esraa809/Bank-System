#ifndef VALIDATION_H
#define VALIDATION_H


#include <iostream>
#include <string>
using namespace std;


class Validation
{
public:
    static bool validname(const string& name){

        if(name.size() < 3 || name.size() > 20){
            return false;
        }
        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name[i])) || name[i]==' ' && isalpha(name[i+1])) {
                return false;
            }
        }
        return true;
    }
    //------------------------------------------------
    static void statusname(pair<bool,string>p){
        if(p.first){
            cout << " Successful operation " << endl;
        }
        else{
            cout << "the name must alphabetic char and min size 3 and max size 20" << endl;
        }
    }
    //------------------------------------------------
    static bool validpassword(const string& password){
        if(password.size() < 8 || password.size() > 20){
            return false;
        }
        for(int i =0;i<password.size();i++){
            if(isspace(password[i])){
                return false;
            }
        }
        return true;
    }
    //------------------------------------------------
    static void statusPassword(pair<bool, string> p) {
        if (p.first) {
            cout << " Successful operation " << endl;
        }
        else {
            cout << "the password must digit and min size 8 and max size 20" << endl;
        }
    }
    //------------------------------------------------
    static bool validbalance(const double& balance){
        if(balance< 1500){
            return false;
        }

        return true;
    }
    //------------------------------------------------
    static void statusbalance(pair<bool, double> p) {
        if (p.first) {
            cout << " Successful operation " << endl;
        }
        else {
            cout << "sorry \n min balance is 1500" << endl;
        }
    }
    //------------------------------------------------
    static bool validamount(const double& amount){
        if(amount <= 0){
            return false;
        }
        else{
            return true;
        }
    }
    //------------------------------------------------
    static bool validcurrency(const string& currency){
       return(currency == "ERP" || currency == "EUR" || currency == "USD" || currency == "EGP" );

    }
    //------------------------------------------------
    static bool validsalary(const double& salary){
        if(salary< 5000){
            return false;
        }

        return true;
    }
    //-------------------------------------------------
    static void statusSalary(pair<bool, double> p) {
        if (p.first) {
            cout << " Successful operation " << endl;
        }
        else {
            cout << "sorry \n min salary is 5000" << endl;
        }
    }
    //-----------------------------------------------
    static bool validwithdraw(double balance , double amount){
        return (balance - amount >= 1500);
    }

};

#endif
