//this is simple progra, to demostrat i you have made error and want to chan the valo n the string

#include<iostream>
#include <string>
using namespace std;
int main(){
    int error_index;
    string new_name;
    string name="Tapash Junwar Chhetri";
    cout<<name<<endl<<"the length of string :"<<name.size()<<endl;
    cout<<"Where is the error in your name :";
    cin>>error_index;
    //part where i will updete the program to my name
    name[error_index]='k';
    cout<<"your name is corrected,new name is:"<<name;

    return 0;

}

