//simply i will add item in  the array; process to add array

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Step 1: Define the original array with a fixed size
    int maz_size =20;
    string cars[maz_size]  {"Lambo","oudi","Bmw","Ford","Marcedies","austin martin"};

    //if now current size is given we need to do;

    int curren_sizze = sizeof(cars)/sizeof(cars[0]);
    cout<<"this is the current size of array : "<<curren_sizze<<endl;

    int cur_size= 0;
    for(int i=0;cur_size<maz_size;i++){
        if(!cars[i].empty()){
            cur_size++;
        }else{
            break;
        }
    
    }
    cout<<cur_size;
}




