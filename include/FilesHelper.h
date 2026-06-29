#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <fstream>
#include <vector>
#include <string>
#include "Client.h"
#include "Parser.h"
using namespace std;


class FilesHelper
{
private:
   static void savelast(const string& filename , int id){
       ofstream file(filename);
       if(file.is_open()){
            file<<id;
            file.close();
       }
   }
   //==========================================
public:

   static int getlast(const string& filename){
       ifstream file (filename);
       int id =0;
       if(file.is_open()){
            file>> id;
            file.close();

       }
       return id;
   }
   //===============================================
   static void saveClient(const Client& c){
        int idd = getlast("ClientLastId.txt");
        fstream file;
        file.open("Client.txt",ios::app);
        file<< idd+ 1<<"-"<<c.get_name()<<"-"<<c.get_password()<<"-"<<c.get_balance()<<endl;

        file.close();
        savelast("ClientLastId.txt",idd+1);

   }
   //==============================================
   static void saveEmployee(const string& datafile,const string& lastidfile,const Employee& e) {
         int iddd = getlast(lastidfile);
        fstream file;
        file.open(datafile,ios::app);
        file<< iddd+1<<"-"<<e.get_name()<<"-"<<e.get_password()<<"-"<<e.get_salary()<<endl;

        file.close();
        savelast(lastidfile,iddd+1);
    }
   //===============================================
   static void getClient(){
       ifstream file;
       string fileline="";
       file.open("Client.txt");
        while(getline(file, fileline )){
            if(fileline.empty()){
                continue;
            }
            Client c = Parser::ParseToClient(fileline);
            vector<Client>& client = Client::getAllClients();
            client.push_back(c);
        }
        file.close();

   }
   //====================================================
   static void getEmployee() {
       ifstream file;
       string fileline="";
       file.open("Employee.txt");
        while(getline(file, fileline )){
            if(fileline.empty()){
                continue;
            }
            Employee e = Parser::ParseToEmployee(fileline);
            vector<Employee>& employee = Employee::getAllEmployees();
            employee.push_back(e);
        }
        file.close();

   }
   //==========================================================
   static void getAdmin() {
       ifstream file;
       string fileline="";
       file.open("Admin.txt");
        while(getline(file, fileline )){
            if(fileline.empty()){
                continue;
            }
            Admin a = Parser::ParseToAdmin(fileline);
            vector<Admin>& admin = Admin::getAllAdmins();
            admin.push_back(a);
        }
        file.close();

   }
   //=========================================================
   static void clearfile(const string& filename, const string& lastidfile) {

      ofstream clearfile ,zeroid;
      clearfile.open(filename,ios::trunc);
      clearfile.close();
      zeroid.open(lastidfile,ios::out);
      zeroid<<0;
      zeroid.close();

   }
   //=========================================================
};

#endif
