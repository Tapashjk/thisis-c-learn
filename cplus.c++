#include<iostream>
#include<string>
using namespace std;
int main (){
    string answer="i will work hard";
    string userinput;

    cout<<"Wht will you do :";
    // this shows that cin only takes the first word typed by the the user  where the getllin take the whole input of the user;
    // cin>>userinput;
    getline(cin,userinput);

    if (userinput==answer){
        cout<<"well done my boi"<<endl;
    }else{
        cout<<"bitch,";
    }
    cout<<"The size of the user input is :"<<userinput.size()<<endl;
    // shupose i want to acces the string
    cout<<userinput[3];
    return 0;

}