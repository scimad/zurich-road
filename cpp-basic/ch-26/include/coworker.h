//coworker.h Defining the abstract class Coworker
#ifndef _COWORKER_H
#define _COWORKER_H

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

#endif