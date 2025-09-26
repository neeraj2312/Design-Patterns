// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class single{
  static single*ins;
  single(){
      cout<<"Construtor called"<<endl;
  }
  public:
  static single* getinstance(){
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
    single*s1 = single::getinstance();
    single*s = single::getinstance();
    
    return 0;
}
