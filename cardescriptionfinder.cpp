#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "************** Welcome to Car World ***********************" << endl;

    // List of cars and their descriptions
    string car[] = {"BMW", "FORD", "TOYOTA", "KIA", "MCLAREN", "TESLA", "MASERATI", "HYUNDAI", "FERRARI", "JAGUAR", "LAMBORGHINI", "ASTON MARTIN"};
    string description[] = {
        "BMW, short for Bayerische Motoren Werke, is a German luxury automobile and motorcycle manufacturer renowned for engineering excellence.",
        "Ford Motor Company revolutionized the automotive industry with its assembly line production.",
        "Toyota is a globally renowned Japanese automobile manufacturer, known for its reliability and affordability.",
        "Kia is a South Korean automobile manufacturer known for producing affordable, stylish, and feature-rich vehicles.",
        "McLaren specializes in creating high-performance sports cars and hypercars using advanced technology.",
        "Tesla is a leader in the electric vehicle market, known for innovation and technology.",
        "Maserati is an Italian luxury vehicle manufacturer known for elegant design and high performance.",
        "Hyundai offers a wide range of vehicles, from sedans to electric models, and is known for quality and reliability.",
        "Ferrari produces some of the most coveted luxury sports cars in the world.",
        "Jaguar combines modern technology with traditional British elegance in its luxury vehicles.",
        "Lamborghini is known for its exotic designs and high-performance luxury sports cars.",
        "Aston Martin is a British luxury car manufacturer, famous for its association with James Bond movies."
    };

    int total_car = sizeof(car) / sizeof(car[0]);

    cout << "Total cars: " << total_car << endl;
    cout << "These are the cars available in this shop:" << endl;

    // Display the list of cars
    for (int i = 0; i < total_car; i++) {
        cout << i + 1 << ". " << car[i] << endl;
    }

    string user_input_car;
    string new_car, new_description;
    string new_cars[20]; // Updated array for adding new cars (fixed maximum size)
    string new_descriptions[20]; // Updated array for adding new descriptions

    // Copy initial cars and descriptions into new arrays
    for (int i = 0; i < total_car; i++) {
        new_cars[i] = car[i];
        new_descriptions[i] = description[i];
    }

    int new_total_car = total_car;

    // Main logic
    while (true) {
        cout << "From the above car list, which car do you want to know about?\n";
        cout << "(Type 'exit' to quit or 'add' to add a new car): ";
        cin >> user_input_car;

        // Convert user input to uppercase for case-insensitive comparison
        transform(user_input_car.begin(), user_input_car.end(), user_input_car.begin(), ::toupper);

        if (user_input_car == "EXIT") {
            cout << "Bye, come back again!" << endl;
            break;
        } else if (user_input_car == "ADD") {
            if (new_total_car >= 20) {
                cout << "Sorry, no more cars can be added." << endl;
                continue;
            }
            cout << "Enter the name of the new car: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, new_car);

            cout << "Enter the description of the new car: ";
            getline(cin, new_description);

            // Add the new car and its description to the arrays
            new_cars[new_total_car] = new_car;
            new_descriptions[new_total_car] = new_description;
            new_total_car++;

            cout << "Car and description added successfully!" << endl;
            cout << "Updated car list:" << endl;
            for (int i = 0; i < new_total_car; i++) {
                cout << i + 1 << ". " << new_cars[i] << endl;
            }
        } else {
            bool found = false;

            for (int i = 0; i < new_total_car; i++) {
                string car_name_upper = new_cars[i];
                transform(car_name_upper.begin(), car_name_upper.end(), car_name_upper.begin(), ::toupper);

                if (car_name_upper == user_input_car) {
                    found = true;
                    cout << "********************************************" << endl;
                    cout << "Details about " << new_cars[i] << ":" << endl;
                    cout << new_descriptions[i] << endl;
                    cout << "********************************************" << endl;
                    break;
                }
            }

            if (!found) {
                cout << "The car you entered is not in the list. Please type a correct car name or add it using 'add'." << endl;
            }
        }
    }

    return 0;
}
