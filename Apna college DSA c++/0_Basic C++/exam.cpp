#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
    public:
    
    void basefunc()
    {
        cout<<"This is a base class function"<<endl;
    }


};

class Car: public Vehicle{
    public:
    void carf()
    {
        cout<<"calling the base function through class CAR:"<<endl;
        
        basefunc();
    }

    
};

class Bike: public Vehicle{
    public:
    void bikef()
    {
        cout<<"calling the base function through class BIKE:"<<endl;
        
        basefunc();
    }

    
};

class Bus: public Vehicle{
    public:
    void busf()
    {
        cout<<"calling the base function through class Bus:"<<endl;
        
        basefunc();
    }


};

int main()
{
    Car c;
    c.carf();
    Bike b;
    b.bikef();
    Bus bu;
    bu.busf();


    cout<<"calling base class function through derived object:"<<endl;
    c.basefunc();
}