// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// observor interface
class observor{
    public:
    virtual void update(const string& msg)=0;
    virtual ~observor()=default;
};

// Subject (publisher)
class subject{
    vector<observor*>observors;
    public:
    void attach(observor*o){
        observors.push_back(o);
    }
    void detach(observor*o){
        observors.erase(remove(observors.begin(),observors.end(),o),observors.end());
    }
    void notify(const string&msg){
        for(auto* o:observors){
            o->update(msg);
        }
    }
};

// Concrete Observor
class user:public observor{
    string name;
    public:
    user(string n):name(n){}
    void update(const string&msg)override{
        cout<<name<<" received: "<<msg<<endl;
    }
};

//Example Usage 
int main() {
    
    subject newsChannel;
    user u1("Alice");
    user u2("Bob");
    
    newsChannel.attach(&u1);
    newsChannel.attach(&u2);
    newsChannel.notify("Breaking New: Observor Pattern in C++!");
    
    newsChannel.detach(&u1);
    newsChannel.notify("Update: Alice unsubscribed ");
    return 0;
}
