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
    string description [maz_size] {
        "An Italian luxury sports car manufacturer renowned for its bold designs, high-performance engines, and exclusivity",
        "A German automaker known for its luxury vehicles and cutting-edge technology",
        "BMW, short for Bayerische Motoren Werke, is a German luxury car brand known for performance and innovation",
        "An iconic American automaker recognized for its reliable trucks, sedans, and pioneering assembly line production"
        "A German luxury car brand renowned for elegance and advanced engineering",
        "A British luxury carmaker famous for its association with James Bond films"
    };
    
    
    //automate the  size of the car array nad description array;
    int cur_size= 0;
    for(int i=0;cur_size<maz_size;i++){
        if(!cars[i].empty()){
            cur_size++;
        }else{
            break;
        }
    
    }
    cout<<cur_size<<endl;




    int dis_size= 0;
    for(int i=0;dis_size<maz_size;i++){
        if(!description[i].empty()){
            dis_size++;
        }else{
            break;
        }
    
    }
    cout<<dis_size<<endl;


    cout<<"**************************************************************************************************************************"<<endl;

    //this the startting of the car project
    cout<<"*****************Welcome to Delux Showroom************************"<<endl;
    cout<<"******************************************************************"<<endl;
    cout<<"These are the current list of car available in the showroom :"<<endl;
        for(int i=0;i<cur_size;i++){
            cout<<i+1<<". "<<cars[i]<<endl;
        }
    
    while(true){
    
    string user_car_input;
    cout<<"If you want to \"Add\" ,\"Exit\" , \"view\" the car: ";
    cin>>user_car_input;
    
    //for case sensitive case;
    transform(user_car_input.begin(),user_car_input.end(),user_car_input.begin(),::tolower);

    //if ujser inputs exit;
    if (user_car_input=="exit"){
        cout<<"Good bye comeback next time sir (*_*)";
        break;
    }
    //if user want to view the the item he typed:
        


















//suppose iw ant to add item in the array
    if (user_car_input=="add"){

        if(cur_size<maz_size){
            string car_add;
            string car_description;
            cout<<"**************************************************************************************************************************"<<endl;
            cout<<"Enter the brand of the car you want to add :";
            cin.ignore();
            getline(cin,car_add);
            cout<<"Description of the car :";
            getline(cin,car_description);

            transform(car_add.begin(),car_add.end(),car_add.begin(),::tolower);
            transform(car_description.begin(),car_description.end(),car_description.begin(),::tolower);
            cars[cur_size]=car_add;
            description[dis_size]=car_description;
            cur_size++;
            dis_size++;
            cout<<"updated sucess fully"<<endl;
             cout<<"***************This is the updated list of car******************* "<<endl;
              for(int i=0 ; i<cur_size ; i++){
                 cout<<i+1<<". "<<cars[i]<<endl;
                 
             }
             }else{
                cout<<"no more space availble";
             
        }
    }else{
        cout<<"Typo Error"<<endl;
        continue;
    }
    }
    


}

