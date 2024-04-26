#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string address;
public:
    Person(string name = "", string address = ""): name(name), address(address) {}
    string getName() { return name; }
    string getAddress() { return address; }
    void setAddress(string address) { this->address = address; }
    virtual string toString() {
        return "Person[name=" + name + ",address=" + address + "]";
    }
};

class Student : public Person {
private:
    string program;
    int year;
    double fee;
public:
    Student(string name = "", string address = "", string program = "", int year = 0, double fee = 0) {
        this->name = name;
        this->address = address;
        this->program = program;
        this->year = year;
        this->fee = fee;
    }
    string getProgram() { return program; }
    void setProgram(string program) { this->program = program; }
    int getyear() { return year; }
    void setYear(int year) { this->year = year; }
    double getFee() { return fee; }
    void setFee(double fee) { this->fee = fee; }
    string toString() {
        return "Student[" + Person::toString() + ",program=" + program 
            + ",year=" + to_string(year) + ",fee=" + to_string(fee) + "]";
    }
};

class Staff : public Person {
private:
    string school;
    double pay;
public:
    Staff(string name = "", string address = "", string school = "", double pay = 0) {
        this->name = name;
        this->address = address;
        this->school = school;
        this->pay = pay;
    }
    string getSchool() { return school; }
    void setSchool(string school) { this->school = school; }
    double getPay() { return pay; }
    void setPay(double pay) { this->pay = pay; }
    string toString() {
        return "Staff[" + Person::toString() + ",school=" + school + ",pay=" + to_string(pay) + "]";
    }
};

class SchoolBusinessTest {
public:
    void work() {
        Student** list = new Student * [5];
        for (int i = 0; i < 5; i++) {
            list[i] = new Student();
            list[i]->setYear(2023);
            cout << list[i]->toString() << "\n";
        }
        Staff* staff = new Staff();
        staff->setAddress("268 Ly Thuong Kiet");
    }
};

int main() {
    SchoolBusinessTest* sbt = new SchoolBusinessTest();
    sbt->work();
    return 0;
}
