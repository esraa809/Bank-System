#ifndef CLIENT_H
#define CLIENT_H
#include<iterator>

#include<Person.h>
#include <vector>
#include <iostream>
#include<Validation.h>

using namespace std;

class Client :public Person
{
private:
    double balance;
    static vector<Client> AllClients;
public:
    //constractor
   Client(){
       balance =1500;
   }
   Client(int id, const string& name ,const string& password,double balance):
       Person(id,name,password),balance(balance){

   }
   //====================================
   static vector<Client>& getAllClients(){
       return AllClients;
   }
   //------------------------------------
   //setter
    pair<bool, string> setName(string name) {
        if (!Validation::validname(name)) {
            this->name= " ";
            return {false,name};
        }
        this->name =name;
        return{true , name};
    }
   pair<bool, string> setPassword(string password) {
        if (!Validation::validpassword(password)) {
            this->password = " ";
            return {false , this->password };
        }
        this->password = password;
        return {true, password};
    }

   pair<bool, double> setbalance(double balance) {

        if (!Validation::validbalance(balance))
            return { false,this->balance };

        this->balance = balance;
        return { true,balance };
    }
   //---------------------------------------
   //getter
    int get_id()const{
       return id;
    }
    string get_name()const{
        return name;
    }
    string get_password()const{
        return password;
    }
    double get_balance() const{
        return balance;
    }
    //-----------------------------------------
    pair <bool, double> withdraw(double amount){
        if(!Validation::validamount(amount)){
                return {false,balance};
        }
        if(!Validation::validwithdraw(balance , amount)){
            return{false,balance};
        }
        balance -= amount;
        return{true , balance} ;
    }
    //--------------------------------------------
    pair <bool, double> debosit(double amount){
        if(!Validation::validamount(amount)){
                return {false,balance};
        }

        balance += amount;
        return{true , balance} ;
    }
    //----------------------------------------------
    void check_balance()const{
        cout<<"the Balance is : "<<balance<<endl;

    }
    //----------------------------------------------
    pair<bool , double> transfarto(Client& another , double amount){
        if(amount <= balance && amount >0){
            if(withdraw(amount).first){
                    another.debosit(amount);
                    return{true , balance};
            }
        }

        return{false , balance};
    }
    //----------------------------------------------
    void display(){
        cout<<"\n-------------- Client Info -----------------\n"<<endl;
        Person::display();
        cout<<"Balance : "<<balance<<endl;
        cout<<"-------------------------------------------------"<<endl;

    }

};

static vector<Client>::iterator ClientIt;

#endif
