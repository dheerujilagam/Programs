#include<iostream>
#include<string>
using namespace std;

class College {
protected:
    string CollegeName, Branch;
public:
    College() {
        CollegeName = "";
        Branch = "";
    }

    College(const string& CollegeName, const string& Branch) {
        this->CollegeName = CollegeName;
        this->Branch = Branch;
    }
};

class Student : public College {
    string Name, RollNo;
    int Age;
public:
    /* Constructor Chaining (Delegation)
    Student(string Name) : College(), Name(Name) {}

    Student(string Name, string RollNo) : Student(Name) { this->RollNo = RollNo; }

    Student(string Name, string RollNo, int Age) : Student(Name, RollNo) { this->Age = Age; }
    */

    Student() : College(), Name(""), RollNo(""), Age(0) {}

    Student(string Name) : College(), Name(Name), RollNo(""), Age(0) {}

    Student(string Name, string RollNo) : College(), Name(Name), RollNo(RollNo), Age(0) {}

    Student(string Name, string RollNo, int Age) : College(), Name(Name), RollNo(RollNo), Age(Age) {}

    Student(string Name, string RollNo, int Age, string CollegeName, string Branch) : College(CollegeName, Branch), Name(Name), RollNo(RollNo), Age(Age) {}

    /*
    Student(const string &Name, const string &RollNo, int Age, const string& CollegeName, const string& Branch) : College(CollegeName, Branch) {
        this->Name = Name;
        this->RollNo = RollNo;
        this->Age = Age;
    }
    */

    /*
    void setDetails(string Name, string RollNo, int Age, string CollegeName, string Branch) {
        this->Name = Name;
        this->RollNo = RollNo;
        this->Age = Age;
        this->CollegeName = CollegeName;
        this->Branch = Branch;
    }
    */

    void getName() {
        cout << "Name of the student : " << Name << endl;
    }
    
    void getRollNo() {
        cout << "RollNo of the student : " << RollNo << endl;
    }

    void getAge() {
        cout << "Age of the student : " << Age << endl;
    }

    void Display();
};

void Student :: Display() {
    cout << "College Name : " << CollegeName << "\n";
    cout << "Branch : " << Branch << "\n";
    cout << "Name : " << Name << "\n";
    cout << "RollNo : " << RollNo << "\n";
    cout << "Age : " << Age << "\n";
}

int main() {
    Student s1("J D V Subhash", "20A91A05F4", 21, "AEC", "CSE");
    s1.getName();
    s1.getRollNo();
    s1.getAge();
    s1.Display();

    Student *s2 = new Student("Jilagam Dheerendra", "20A91A04F4", 21, "AEC", "ECE");
    s2->getName();
    s2->getRollNo();
    s2->getAge();
    s2->Display();

    delete s2;
}