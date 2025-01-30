#include <iostream>
#include <mysql/mysql.h>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

// MySQL Connection Configuration
const char* DB_HOST = "localhost";
const char* DB_USER = "root";
const char* DB_PASS = "123456789";
const char* DB_NAME = "bank_db";

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;

// Function prototypes
void connectDB();
void mainMenu();
void registerUser();
void createAccount();
void addAmount();
void withdrawAmount();
void transferAmount();
void removeAccount();
void displayBalance();
string generateAccountNumber();

// Database connection
void connectDB() {
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0)) {
        cerr << "Error connecting to database: " << mysql_error(conn) << endl;
        exit(1);
    }
}

// Generate random account number
string generateAccountNumber() {
    stringstream ss;
    for(int i = 0; i < 12; i++) {
        ss << rand() % 10;
    }
    return ss.str();
}

// User registration
void registerUser() {
    string name, email, password;
    
    cout << "\nEnter name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter email: ";
    cin >> email;
    
    cout << "Enter password: ";
    cin >> password;

    string query = "INSERT INTO users (name, email, password) VALUES ('" + 
                  name + "', '" + email + "', '" + password + "')";
    
    if(mysql_query(conn, query.c_str())) {
        cerr << "Registration failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Registration successful!" << endl;
    }
}

// Create bank account
void createAccount() {
    int user_id;
    string type;
    
    cout << "\nEnter user ID: ";
    cin >> user_id;
    
    cout << "Account type (Savings/Current): ";
    cin >> type;
    
    string acc_number = generateAccountNumber();
    
    string query = "INSERT INTO accounts (user_id, account_number, type) VALUES (" + 
                  to_string(user_id) + ", '" + acc_number + "', '" + type + "')";
    
    if(mysql_query(conn, query.c_str())) {
        cerr << "Account creation failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Account created successfully! Account Number: " << acc_number << endl;
    }
}

// Deposit money
void addAmount() {
    string account_number;
    double amount;
    
    cout << "\nEnter account number: ";
    cin >> account_number;
    
    cout << "Enter amount to deposit: ";
    cin >> amount;

    string query = "UPDATE accounts SET balance = balance + " + to_string(amount) + 
                  " WHERE account_number = '" + account_number + "'";
    
    if(mysql_query(conn, query.c_str())) {
        cerr << "Deposit failed: " << mysql_error(conn) << endl;
    } else {
        // Record transaction
        query = "INSERT INTO transactions (account_id, amount, type) "
                "SELECT account_id, " + to_string(amount) + ", 'Deposit' "
                "FROM accounts WHERE account_number = '" + account_number + "'";
        mysql_query(conn, query.c_str());
        cout << "Deposit successful!" << endl;
    }
}

// Transfer money
void transferAmount() {
    string from_acc, to_acc;
    double amount;
    
    cout << "\nEnter your account number: ";
    cin >> from_acc;
    
    cout << "Enter recipient account number: ";
    cin >> to_acc;
    
    cout << "Enter amount to transfer: ";
    cin >> amount;

    // Start transaction
    mysql_query(conn, "START TRANSACTION");

    try {
        // Deduct from sender
        string query = "UPDATE accounts SET balance = balance - " + to_string(amount) + 
                      " WHERE account_number = '" + from_acc + "'";
        if(mysql_query(conn, query.c_str())) throw exception();

        // Add to receiver
        query = "UPDATE accounts SET balance = balance + " + to_string(amount) + 
               " WHERE account_number = '" + to_acc + "'";
        if(mysql_query(conn, query.c_str())) throw exception();

        // Record transactions
        query = "INSERT INTO transactions (account_id, amount, type, related_account) "
                "SELECT a.account_id, " + to_string(amount) + ", 'Transfer', b.account_id "
                "FROM accounts a, accounts b "
                "WHERE a.account_number = '" + from_acc + "' "
                "AND b.account_number = '" + to_acc + "'";
        if(mysql_query(conn, query.c_str())) throw exception();

        mysql_query(conn, "COMMIT");
        cout << "Transfer successful!" << endl;
    } catch(...) {
        mysql_query(conn, "ROLLBACK");
        cerr << "Transfer failed!" << endl;
    }
}

// Remove account
void removeAccount() {
    string account_number;
    
    cout << "\nEnter account number to delete: ";
    cin >> account_number;
    
    string query = "DELETE FROM accounts WHERE account_number = '" + account_number + "'";
    
    if(mysql_query(conn, query.c_str())) {
        cerr << "Account deletion failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Account deleted successfully!" << endl;
    }
}

// Main menu
void mainMenu() {
    int choice;
    do {
        cout << "\nBank Management System\n";
        cout << "1. Register User\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Delete Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: registerUser(); break;
            case 2: createAccount(); break;
            case 3: addAmount(); break;
            case 4: transferAmount(); break;
            case 5: removeAccount(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 6);
}

int main() {
    connectDB();
    mainMenu();
    mysql_close(conn);
    return 0;
}