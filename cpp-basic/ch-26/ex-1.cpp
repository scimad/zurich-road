//Abstract Classes
/*
Author        : scimad2.71@gmail.com
Written       : 10th May, 2020
Last Modified : 10th May, 2020 
*/
#include <iostream>
#include <string>
using namespace std;
#include "include/coworker.h"
#include <string>
#include <iostream>
using namespace std;

class Coworker
{
    private:
        string name;

    public:
        Coworker(const string& s = ""){
            name = s;
            std::cout<<"The name for coworker has been assigned"<<std::endl;
        }
        virtual ~Coworker(){}

        const string& getName() const{
            std::cout<<"Returning name of Coworker"<<std::endl;
            return name;
        }
        void setName( const string& n){ name = n;}

        virtual void display() const;
        virtual double income() const = 0;
        virtual Coworker& operator= (const Coworker&);
};

class Laborer : public Coworker
{
    private:
        double wages;
        int hr;

    public:
        Laborer (const string& s="", double w=0.0, int h=0)
            : Coworker(s), wages(w), hr(h) {}
        double getWages() const {return wages;}
        void setWages(double w){wages = w;}

        void setHr(int h) { hr = h;}
        int getHr() const {return hr;}

        void display() const;
        double income() const;

        Laborer& operator= (const Coworker&);//{return *this;};
        Laborer& operator= (const Laborer&);
        // ~Laborer(){}
 
};

class Employee : public Coworker
{
    private:
        double salary;
    
    public:
        Employee(const string& s="", double sa=0.0)
            : Coworker(s), salary(sa) { }
        double getSalary() const {return salary;}
        void setSalary(double sa){ salary = sa;}
        void display() const;
        double income() const {return salary;}
        Employee& operator= (const Coworker& );
        Employee& operator= (const Employee& );
};

int main(int argc, char const *argv[])
{
    // Coworker* felPtr[3];
    // felPtr[0] = new Laborer();
    // string s = "Ram";
    // felPtr[1] = new Laborer(s);
    // felPtr[2] = new Employee("Mad", 50000.0);

    // Vec* v[2];
    // v[1] = new Complex();
    // v[0] = new Complex(1,2);

    Coworker* testPtr[2];
    testPtr[0] = new Laborer("55");
    return 0;
}
