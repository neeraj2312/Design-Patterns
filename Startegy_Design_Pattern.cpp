// Strategy Design Pattern 
// Defines a family of algorithm put them into seperate classes so that they can be changed at runtime.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// -- Startegy Interface for Walk ---
class WalkableRobot{
  public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() = default;
};

class NormalWalk : public WalkableRobot{
    public:
    void walk() override{
        cout<<"Walking Normally..."<<endl;
    }
};

class NoWalk : public WalkableRobot{
    public:
    void walk() override{
        cout<<"Cannot Walk..."<<endl;
    }
};

class TalkableRobot{
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() = default;
};

class NormalTalk : public TalkableRobot{
    public:
    void talk() override{
        cout<<"Talking Normally..."<<endl;
    }
};

class NoTalk : public TalkableRobot{
    public:
    void talk() override{
        cout<<"Cannot Talk..."<<endl;
    }
};

class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual ~FlyableRobot()=default;
};

class NormalFly : public FlyableRobot{
    public:
    void fly() override{
        cout<<"Flying Normally..."<<endl;
    }
};

class NoFly : public FlyableRobot{
    public:
    void fly() override{
        cout<<"Cannot Fly..."<<endl;
    }
};

class Robot{
  protected:
  TalkableRobot *t;
  WalkableRobot *w;
  FlyableRobot  *f;
  public:
  Robot(WalkableRobot*w, TalkableRobot*t, FlyableRobot*f){
      this->w = w;
      this->t = t;
      this->f = f;
  }
  void walk(){
      w->walk();
  }
  void talk(){
      t->talk();
  }
  void fly(){
      f->fly();
  }
  virtual void projection()=0; //abstract methof for subclasses
};

class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot*w, TalkableRobot*t, FlyableRobot*f):Robot(w,t,f){}
    void projection() override{
        cout<<"Displaying friendly companion features..."<<endl;
    }
};

class WorkerRobot : public Robot{
    public:
    WorkerRobot(WalkableRobot*w, TalkableRobot*t, FlyableRobot*f):Robot(w,t,f){}
    void projection() override{
        cout<<"Displaying worker companion feature..."<<endl;
    }
};
int main() {
    Robot *R1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    R1->walk();
    R1->talk();
    R1->fly();
    R1->projection();
    cout<<"--------------------"<<endl;
    
    Robot *R2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    R2->walk();
    R2->talk();
    R2->fly();
    R2->projection();
    return 0;
}
