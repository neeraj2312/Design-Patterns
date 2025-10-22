// This code is not thread safe 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class single{
    static single*ins;
    single(){
        cout<<"Constructor is called..."<<endl;
    }
    public:
    static single* create(){
        if(!ins){
            ins = new single();
        }
        else{
            cout<<"Object is already created"<<endl;
        }
        return ins;
    }
};
single* single::ins = nullptr;
int main() {
    single* s = single::create();
    single* s2 = single::create();
    single* s3 = single::create();
    
    return 0;
}


// This one is thread safe
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class single{
    static single*ins;
    static mutex mtx;
    single(){
        cout<<"Constructor is called..."<<endl;
    }
    public:
    static single* create(){
        if(!ins){
            lock_guard<mutex>lock(mtx); //lock for thread safety
            if(!ins)ins = new single();
        }
        else{
            cout<<"Object is already created"<<endl;
        }
        return ins;
    }
};
single* single::ins = nullptr;
int main() {
    single* s = single::create();
    single* s2 = single::create();
    single* s3 = single::create();
    
    return 0;
}

// if we want to avoid these expensive operations, what can we do .
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class single{
    static single*ins;
    single(){
        cout<<"Constructor is called..."<<endl;
    }
    public:
    static single* create(){
        return ins;
    }
};
// This is eager initilization
// advantage - dont need multiple condition and locking
// disadvantage -  suppose we have created a class which is heavy and consume alot of memory, but we have already created the object of thta class but it is not used in the future.
single* single::ins = new single();
int main() {
    single* s = single::create();
    single* s2 = single::create();
    single* s3 = single::create();
    
    return 0;
}
