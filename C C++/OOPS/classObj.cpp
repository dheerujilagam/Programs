#include<bits/stdc++.h>
using namespace std;

// Abstract Class
class Promotion {
public:
    virtual void AskForPromotion() = 0;
};

// Encapsulation (getters and setters)
class Employee : Promotion{
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void Show() {
        cout << "Name : " << Name << endl;
        cout << "Company : " << Company << endl;
        cout << "Age : " << Age << endl;
    }
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        Age = age;
    }
    int getAge() {
        return Age;
    }
    void AskForPromotion() {
        if(Age > 30) {
            cout << Name << " got promoted! \n";
        } else {
            cout << Name << " not got promoted! \n";
        }
    }
};

class Developer : public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage) 
    : Employee(name, company, age) {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void ShowDeveloper() {
        cout << Name << " solved bug using " << FavProgrammingLanguage << endl;
    }
};

int main() {
    // Employee e1 = Employee("Prabhu", "Darwin Box", 20);
    // e1.Show();
    // e1.setAge(21);
    // cout << e1.getAge() << endl;
    // e1.AskForPromotion();
    Developer d = Developer("abc", "xyz", 30, "cpp");
    d.ShowDeveloper();
}