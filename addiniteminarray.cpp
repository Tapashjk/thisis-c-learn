//simply i will add item in  the array; process to add array

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
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
    cout<<cur_size<<endl;
    
    while(true){
    
    string user_car_input;
    cout<<"Enter the car you want to add to car list: ";
    cin>>user_car_input;
    
    //for case sensitive case;
    transform(user_car_input.begin(),user_car_input.end(),user_car_input.begin(),::tolower);

    //if ujser inputs exit;
    if (user_car_input=="exit"){
        cout<<"Good bye";
        break;
    }


//suppose iw ant to add item in the array
    if (user_car_input=="add"){
        if(cur_size<maz_size){
            string car_add;
            cout<<"Enter the brand of the car you want to add :";
            cin>>car_add;
            getline(cin,user_car_input);
            transform(car_add.begin(),car_add.end(),car_add.begin(),::tolower);

            cars[cur_size]=car_add;
            cur_size++;
            cout<<"updated sucess fully"<<endl;
             cout<<"***************This is the updated list of car******************* "<<endl;
              for(int i=0 ; i<cur_size ; i++){
                 cout<<i+1<<". "<<cars[i]<<endl;
                 
             }
             break;
        }
    }else{
        cout<<"Typo Error";
        continue;
    }
    }
    


}

