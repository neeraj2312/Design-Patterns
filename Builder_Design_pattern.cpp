#include <bits/stdc++.h>
using namespace std;
class User{
    const string userId;
    const string userName;
    const string emailId;
    User(const string& id, const string& name, const string& email):userId(id),userName(name),emailId(email){}
    public:
    string getUserId() const{
        return userId;
    }
    string getUserName() const{
        return userName;
    }
    string getEmailId() const{
        return emailId;
    }
    
    //inner class to create obj;
    class UserBuilder{
        string userId;
        string userName;
        string emailId; 
        
        public:
        
        UserBuilder& setUserId(const string& Id){
            userId = Id;
            return *this;
        }
        UserBuilder& setUserName(const string& Name){
            userName = Name;
            return *this;
        }
        UserBuilder& setEmailId(const string& email){
            emailId = email;
            return *this;
        }
        
        User build(){
            return User(userId,userName,emailId);
        }
    };
};
int main(){
    
    User user = User::UserBuilder()
    .setUserId("U123")
    .setUserName("Neeraj")
    .setEmailId("neeraj@123")
    .build();
    
    
    cout<<"UserId : "<<user.getUserId()<<endl;
    cout<<"UserName : "<<user.getUserName()<<endl;
    cout<<"EmailId : "<<user.getEmailId()<<endl;
    return 0;
}


















