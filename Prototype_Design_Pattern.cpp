#include <bits/stdc++.h>
using namespace std;
class proto{
    public:
    virtual proto* clone()const = 0;
    virtual void show()const = 0;
    virtual ~proto(){}
};
class user:public proto{
    string id;
    string name;
    public:
    user(string id, string name):id(id),name(name){};
    
    //copy constuctor *************
    
    user* clone() const override{
        return new user(*this);
    }
    void show()const override{
        cout<<"UserID : "<<id<<" UserName : "<<name<<endl;
    }
};
int main(){
    user *u = new user("123","name");
    u->show();
    
    user*fresh = u->clone();
    fresh->show();
    return 0;
}
