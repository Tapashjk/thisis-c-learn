#include <iostream>
#include <string>
using namespace std;
int main(){
    int number;
    int revnum=0;
    cout<<"Enter yor number you wnat to revers :";
    cin>>number;
    cout<<"Your orignal numebr is:"<<number;
    while(number){
        revnum=revnum*10+number%10;
        number /=10;
    }
    cout<<"the revers numebr is :"<<revnum;
    }
    