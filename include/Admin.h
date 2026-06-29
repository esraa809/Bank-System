
#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee
{
private:
    static vector<Admin> AllAdmins;

public:
    static vector<Admin>& getAllAdmins(){
        return AllAdmins;
    }

    Admin() : Employee() {}

    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}

    void display() {

        cout << "\n-------- Admin Info ----------\n";

        Person::display();

        cout << "Salary : " << get_salary() << endl;

        cout << "------------------------------\n";
    }

    //===========================================================

    void addEmployee(Employee& employee){
        Employee::getAllEmployees().push_back(employee);
    }

    Employee* searchEmployee(int id){
        for(EmployeeIt = Employee::getAllEmployees().begin();
            EmployeeIt != Employee::getAllEmployees().end();
            EmployeeIt++)
        {
            if(EmployeeIt->get_id() == id){
                return &(*EmployeeIt);
            }
        }
        return nullptr;
    }

    void listEmployee(){
        vector<Employee>& employee = Employee::getAllEmployees();

        for(auto it = employee.begin(); it != employee.end(); it++){
            it->display();
            cout << "\n---------------------------\n";
        }
    }

    void editEmployee(int id,
                      const string& name,
                      const string& password,
                      double salary)
    {
        Employee* employee = searchEmployee(id);

        if(employee){
            employee->setName(name);
            employee->setPassword(password);
            employee->setsalary(salary);
        }
    }

    void checkSalary() const{
        cout << "\nYour Salary is: "
             << get_salary()
             << endl;
    }
};

static vector<Admin>::iterator AdminIt;

#endif
