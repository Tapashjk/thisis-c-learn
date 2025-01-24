
#include<iostream>
#include <string>
using namespace std;
int main(){
    int i=0;
    string input;
    string password="123456";
    do{
        cout<<"what is you rpassword:" <<endl;
        cin>>input;
        if(input==password){
            cout<<"device unloced";
            break;
        }else{
            cout<<"wRONG password,tryagain"<<endl;
            
        }
        i++;

    }
    while (i>5);
       
    return 0;
}