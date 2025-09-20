// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class car{
    public:
    virtual void help()=0;
    virtual ~car(){}
};
class toy:public car{
    public:
    void help (){
        cout<<"This is toy car"<<endl;
    }
};
class maruti:public car{
    public:
    void help (){
        cout<<"This is maruti car"<<endl;
    }
};
class FactoryCar{
    public:
    static car* load(const string& car){
        if(car=="toy"){
            return new toy();
        }
        else if(car == "maruti"){
            return new maruti();
        }
        else return nullptr;
    }
};

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    car* c = FactoryCar::load("toy");
    c->help();
    car* m = FactoryCar::load("maruti");
    m->help();    
    return 0;
}
