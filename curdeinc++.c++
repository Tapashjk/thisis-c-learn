#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_USERS = 5; // Maximum number of users
    string users[MAX_USERS];
    string passwords[MAX_USERS];
    int userCount = 0;
    
    while (true) {
        int choice;
        cout << "Menu:\n";
        cout << "1. Add user\n";
        cout << "2. Update user data\n";
        cout << "3. Remove user\n";
        cout << "4. View all users\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // Add user
            if (userCount < MAX_USERS) {
                cout << "Enter username: ";
                cin >> users[userCount];
                cout << "Enter password: ";
                cin >> passwords[userCount];
                userCount++;
                cout << "User added successfully!\n";
            } else {
                cout << "User limit reached!\n";
            }
        }
        else if (choice == 2) {  // Update user data
            string username;
            cout << "Enter the username to update: ";
            cin >> username;

            bool found = false;
            for (int i = 0; i < userCount; i++) {
                if (users[i] == username) {
                    cout << "Enter new username: ";
                    cin >> users[i];
                    cout << "Enter new password: ";
                    cin >> passwords[i];
                    cout << "User data updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "User not found!\n";
            }
        }
        else if (choice == 3) {  // Remove user
            string username;
            cout << "Enter the username to remove: ";
            cin >> username;

            bool found = false;
            for (int i = 0; i < userCount; i++) {
                if (users[i] == username) {
                    // Shift all users after this one down by 1
                    for (int j = i; j < userCount - 1; j++) {
                        users[j] = users[j + 1];
                        passwords[j] = passwords[j + 1];
                    }
                    userCount--;
                    cout << "User removed successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "User not found!\n";
            }
        }
        else if (choice == 4) {  // View all users
            if (userCount == 0) {
                cout << "No users available.\n";
            } else {
                cout << "Users List:\n";
                for (int i = 0; i < userCount; i++) {
                    cout << "Username: " << users[i] << ", Password: " << passwords[i] << endl;
                }
            }
        }
        else if (choice == 5) {  // Exit
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
