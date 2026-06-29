#ifndef PERSON_H
#define PERSON_H

using namespace std;
#include<iostream>
#include<string>
#include"Validation.h"

class Person
{
protected:
    int id;
    string name;
    string password;
    string currency;
public:
    //constractor
    Person(){
        id =0;
        name = "";
        password = "";
    }
    Person(int id,string name, string password):
        id(id),name(name),password(password){}
    //------------------------------------------
    //setter
    void set_id(int id){
        this->id = id;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_password(string password){
        this->password = password;
    }
    //-----------------------------------------
    //getter
    int get_id(){
       return id;
    }
    string get_name(){
        return name;
    }
    string get_password(){
        return password;
    }
    //-------------------------------------------
    virtual  void display(){
        cout<<"ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Password : "<<password<<endl;
    }

};

#endif
