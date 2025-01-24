//simple program of  the array :

#include <iostream>
#include <string>
using namespace std;

int main() {
    int j;
    string name[] = {"Tangoo", "talaa", "tripti", "hari", "deepa", "ram", "bhena", "sita", "exit"};

    for (int i = 0; i < 8; i++) { 
        j = i + 1;
        cout << j << ". " << name[i] << endl;
    }

    string choice;
    while (true) {
        cout << "Whose character you want to know or type 'exit': ";
        cin >> choice;

        if (choice == "exit") {
            cout << "Bye bye!" << endl;
            break; 
        } else {
            bool found = false;
            for (int i = 0; i < 8; i++) {
                if (name[i] == choice) {
                    found = true;
                    switch (i) {
                        case 0:
                            cout << name[i] << " is a dedicated and intelligent person." << endl;
                            break;
                        case 1:
                            cout << name[i] << " is a hardworking man." << endl;
                            break;
                        case 2:
                            cout << name[i] << " is very creative." << endl;
                            break;
                        case 3:
                            cout << name[i] << " is a reliable friend." << endl;
                            break;
                        case 4:
                            cout << name[i] << " is very supportive and kind." << endl;
                            break;
                        case 5:
                            cout << name[i] << " is a great companion." << endl;
                            break;
                        case 6:
                            cout << name[i] << " is a wise elder." << endl;
                            break;
                        case 7:
                            cout << name[i] << " is a caring grandparent." << endl;
                            break;
                        default:
                            cout << "Character information not available." << endl;
                            break;
                    }
                    break; 
                }
            }

            if (!found) {
                cout << "Name not found in the list. Please try again." << endl;
            }
        }
    }

    return 0;
}
