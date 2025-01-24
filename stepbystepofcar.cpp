// one of the example of static array handeling
//basics:
// /builidng bolcok of the  of cardescription.cPP


#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
int main (){
    cout<<"******************************  Welcome to the DLS  ***************************************"<<endl;
    string car[] = {"BMW","FORD","TOYOTA","HONDA","LAMBERGINI"};
    string description []={
        "This the super blue car",
        "this is ford just buy it",
        "it like a family car",
        "this is long lasting car",
        "this is fast and a rich car"
    };
    // FIND THE SIZE OF THE ARRAY
    int total_car ;
    total_car= sizeof(car) / sizeof(car[0]);
    cout<<"These are the total car in the shop: "<<total_car<<endl;
    for(int i=0;i<total_car;i++){
    cout<<i+1<<". "<<car[i]<<endl;
    }
    //i will just simply check in the list if the car is available or not
     while (true) {
        string user_input;
        cout << "\nEnter the car name to see if it's in the list or type (exit) to quit: ";
        cin >> user_input;

        // Convert user input to uppercase to make it case-insensitive
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);

        if (user_input == "EXIT") {
            cout << "Goodbye, see you next time!" << endl;
            break;
        } else {
            bool found = false;
            for (int i = 0; i < total_car; i++) {
                string car_name_upper = car[i];

                // Convert car name to uppercase for comparison
                transform(car_name_upper.begin(), car_name_upper.end(), car_name_upper.begin(), ::toupper);

                if (car_name_upper == user_input) {
                    found = true;
                    cout << "------------- " << car[i] << " ----------------" << endl;
                    cout << description[i] << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Car not found or not available in the list." << endl;
            }
        }
    }

    return 0;
}


