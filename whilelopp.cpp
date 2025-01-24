// use case of while loop:
// int i = 0;
// while (i < 5) {
//   cout << i << "\n";
//   i++;
// }






#include<iostream>
#include <string>
using namespace std;
int main(){
    int i=0;
    string input;
    string password="123456";
    while (i<5){
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
    return 0;
}