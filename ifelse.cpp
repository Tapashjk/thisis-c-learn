// simple use case of the else iff

#include<iostream>
#include <string>
using namespace std;
int main(){
    string name,pass;
    string password="Kmc@model2025";
    
    cout<<"                Welcome to the login page                "<<endl;
    
    cout<<"Enter your username :";
    cin>>name;
    cout<<"Welocome,"<<name<<endl;
    
    cout<<"enetr your pasword : "<<endl;
    cin>>pass;
    
    // if else logic
    if (pass==password){
        cout<<"device unlocekd"<<endl;

    }else{
        cout<<"wrong password";
    }

    return 0;
}