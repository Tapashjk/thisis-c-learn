#include <iostream>
#include <mysql/mysql.h>
using namespace std;

// MySQL connection details
const char* HOST = "localhost";
const char* USER = "root";     
const char* PASSWORD = "123456789";  
const char* DATABASE = "bank_db";

// Function to connect to MySQL
MYSQL* connectToDatabase() {
    MYSQL* conn = mysql_init(NULL);
    if (!conn) {
        cerr << "MySQL Initialization Failed!" << endl;
        exit(1);
    }

    conn = mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 3306, NULL, 0);
    if (!conn) {
        cerr << "MySQL Connection Failed!" << endl;
        exit(1);
    }
    return conn;
}

// Class to manage bank accounts
class BankAccount {
public:
    int accountNumber;
    string customerName;
    double balance;

    BankAccount(int accNum, string name, double bal) {
        accountNumber = accNum;
        customerName = name;
        balance = bal;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Class for Banking System
class BankingSystem {
private:
    MYSQL* conn;

public:
    BankingSystem() {
        conn = connectToDatabase();
    }

    // Create a new account
    void createAccount(string name, double initialDeposit) {
        string query = "INSERT INTO accounts (customer_name, balance) VALUES ('" + name + "', " + to_string(initialDeposit) + ")";
        if (mysql_query(conn, query.c_str())) {
            cerr << "Error creating account!" << endl;
        } else {
            cout << "Account created successfully!" << endl;
        }
    }

    // Deposit Money
    void depositMoney(int accNumber, double amount) {
        string query = "UPDATE accounts SET balance = balance + " + to_string(amount) + " WHERE account_number = " + to_string(accNumber);
        if (mysql_query(conn, query.c_str())) {
            cerr << "Deposit Failed!" << endl;
        } else {
            cout << "Deposit Successful!" << endl;
        }
    }

    // Withdraw Money
    void withdrawMoney(int accNumber, double amount) {
        string checkBalanceQuery = "SELECT balance FROM accounts WHERE account_number = " + to_string(accNumber);
        mysql_query(conn, checkBalanceQuery.c_str());
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row = mysql_fetch_row(res);

        if (row) {
            double currentBalance = stod(row[0]);
            if (currentBalance >= amount) {
                string query = "UPDATE accounts SET balance = balance - " + to_string(amount) + " WHERE account_number = " + to_string(accNumber);
                mysql_query(conn, query.c_str());
                cout << "Withdrawal Successful!" << endl;
            } else {
                cout << "Insufficient Balance!" << endl;
            }
        } else {
            cout << "Account Not Found!" << endl;
        }
    }

    // Transfer Money
    void transferMoney(int fromAcc, int toAcc, double amount) {
        withdrawMoney(fromAcc, amount);
        depositMoney(toAcc, amount);
        cout << "Transfer Successful!" << endl;
    }

    // View Account Details
    void viewAccount(int accNumber) {
        string query = "SELECT * FROM accounts WHERE account_number = " + to_string(accNumber);
        mysql_query(conn, query.c_str());
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row = mysql_fetch_row(res);

        if (row) {
            cout << "Account Number: " << row[0] << endl;
            cout << "Customer Name: " << row[1] << endl;
            cout << "Balance: $" << row[2] << endl;
        } else {
            cout << "Account Not Found!" << endl;
        }
    }

    ~BankingSystem() {
        mysql_close(conn);
    }
};

// Main Function
int main() {
    BankingSystem bank;
    int choice, accNum;
    double amount;
    string name;

    while (true) {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Transfer Money\n5. View Account\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer Name: ";
                cin >> name;
                cout << "Enter Initial Deposit: ";
                cin >> amount;
                bank.createAccount(name, amount);
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bank.depositMoney(accNum, amount);
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                bank.withdrawMoney(accNum, amount);
                break;

            case 4:
                int toAcc;
                cout << "Enter From Account Number: ";
                cin >> accNum;
                cout << "Enter To Account Number: ";
                cin >> toAcc;
                cout << "Enter Transfer Amount: ";
                cin >> amount;
                bank.transferMoney(accNum, toAcc, amount);
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.viewAccount(accNum);
                break;

            case 6:
                cout << "Exiting System..." << endl;
                return 0;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}
