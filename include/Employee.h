#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Person.h"
#include"Validation.h"
#include<vector>
#include"Client.h"

class Employee: public Person
{
private:
    double salary;
    static vector<Employee> AllEmployees;

public:
    Employee(){
        salary = 5000;
    }
    Employee(int id, string name ,string password,double salary):
         Person(id,name,password),salary(salary){}
    //------------------------------------
    static vector<Employee>& getAllEmployees(){
       return AllEmployees;
   }
    //====================================
    //setter
    pair<bool, string> setName(string name) {
        if (!Validation::validname(name)) {
            return {false,name};
        }
        this->name =name;
        return{true , name};
    }
    pair<bool, string> setPassword(string password) {
        if (!Validation::validpassword(password)) {
            return {false , this->password };
        }
        this->password = password;
        return {true, password};
    }

   pair<bool, double> setsalary(double salary) {

        if (!Validation::validsalary(salary))
            return { false,salary };

        this->salary = salary;
        return { true, salary};
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
    double get_salary() const{
        return salary;
    }
    //---------------------------------------

    void display(){
        cout<<"\n-------------- Employee Info -----------------\n"<<endl;
        Person::display();
        cout<<"salary : "<<salary<<endl;
        cout<<"-------------------------------------------------"<<endl;

    }
    //===========================================================
    //additional class
    void addClient(Client& client){
        Client::getAllClients().push_back(client);
    }

    Client* searchClient(int id){
        for(ClientIt = Client::getAllClients().begin();ClientIt != Client::getAllClients().end();ClientIt++){
            if(ClientIt->get_id()== id){
                return&(*ClientIt);
            }
        }
        return nullptr;
    }
    void listClient(){
        vector<Client>& client = Client::getAllClients();
        for(auto it = client.begin();it != client.end();it++){
            it->display();
            cout<<"\n---------------------------\n";
        }
    }

    void editClient(int id, const string& name,const string& password,double balance){
        Client* client = searchClient(id);
        client->setName(name);
        client->setPassword(password);
        client->setbalance(balance);
    }
    void checkSalary()const{
        cout<< endl<<"Your Salary is: "<< salary<<endl;
    }
    //===============================================================

};


static vector<Employee>::iterator EmployeeIt;
#endif
