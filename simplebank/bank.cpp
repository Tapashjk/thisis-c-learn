#include <iostream>
#include <mysql/mysql.h>
using namespace std;

// MySQL Database Credentials
const char* HOST = "localhost";
const char* USER = "root";     
const char* PASSWORD = "123456789";  
const char* DATABASE = "bank_db";
const unsigned int PORT = 3306;

// Connect to MySQL Database
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

// Banking System Class
class BankingSystem {
private:
    MYSQL* conn;

    // Execute MySQL Query
    bool executeQuery(const string& query) {
        if (mysql_query(conn, query.c_str()) == 0) {
            return true;
        } else {
            cerr << "MySQL Error: " << mysql_error(conn) << endl;
            return false;
        }
    }

    // Fetch single-row result from MySQL
    MYSQL_ROW fetchRow(const string& query) {
        if (mysql_query(conn, query.c_str()) == 0) {
            MYSQL_RES* res = mysql_store_result(conn);
            if (res) {
                MYSQL_ROW row = mysql_fetch_row(res);
                mysql_free_result(res);
                return row;
            }
        }
        return nullptr;
    }

    // Get Account Balance
    double getBalance(int accNumber) {
        string query = "SELECT balance FROM accounts WHERE account_number = " + to_string(accNumber);
        MYSQL_ROW row = fetchRow(query);
        return row ? stod(row[0]) : -1;
    }

public:
    BankingSystem() { conn = connectToDatabase(); }

    // Create a new account
    void createAccount(const string& name, double initialDeposit) {
        string query = "INSERT INTO accounts (customer_name, balance) VALUES ('" + name + "', " + to_string(initialDeposit) + ")";
        if (executeQuery(query)) {
            cout << "Account created successfully!" << endl;
        }
    }

    // Deposit Money
    void depositMoney(int accNumber, double amount) {
        if (executeQuery("UPDATE accounts SET balance = balance + " + to_string(amount) + " WHERE account_number = " + to_string(accNumber))) {
            executeQuery("INSERT INTO transactions (account_number, transaction_type, amount) VALUES (" + to_string(accNumber) + ", 'Deposit', " + to_string(amount) + ")");
            cout << "Deposit Successful!" << endl;
        }
    }

    // Withdraw Money
    void withdrawMoney(int accNumber, double amount) {
        double balance = getBalance(accNumber);
        if (balance == -1) {
            cout << "Account Not Found!" << endl;
            return;
        }
        if (balance < amount) {
            cout << "Insufficient Balance!" << endl;
            return;
        }

        if (executeQuery("UPDATE accounts SET balance = balance - " + to_string(amount) + " WHERE account_number = " + to_string(accNumber))) {
            executeQuery("INSERT INTO transactions (account_number, transaction_type, amount) VALUES (" + to_string(accNumber) + ", 'Withdrawal', " + to_string(amount) + ")");
            cout << "Withdrawal Successful!" << endl;
        }
    }

    // Transfer Money
    void transferMoney(int fromAcc, int toAcc, double amount) {
        double senderBalance = getBalance(fromAcc);
        if (senderBalance == -1) {
            cout << "Sender Account Not Found!" << endl;
            return;
        }
        if (senderBalance < amount) {
            cout << "Insufficient Balance!" << endl;
            return;
        }

        withdrawMoney(fromAcc, amount);
        depositMoney(toAcc, amount);
        cout << "Transfer Successful!" << endl;
    }

    // View Account Details
    void viewAccount(int accNumber) {
        string query = "SELECT * FROM accounts WHERE account_number = " + to_string(accNumber);
        MYSQL_ROW row = fetchRow(query);

        if (row) {
            cout << "Account Number: " << row[0] << "\nCustomer Name: " << row[1] << "\nBalance: $" << row[2] << endl;
        } else {
            cout << "Account Not Found!" << endl;
        }
    }

    // View Transaction History
    void viewTransactions(int accNumber) {
        string query = "SELECT * FROM transactions WHERE account_number = " + to_string(accNumber);
        if (mysql_query(conn, query.c_str()) == 0) {
            MYSQL_RES* res = mysql_store_result(conn);
            MYSQL_ROW row;
            cout << "Transaction History:\n";
            while ((row = mysql_fetch_row(res))) {
                cout << "Transaction ID: " << row[0] << ", Type: " << row[2] << ", Amount: $" << row[3] << ", Date: " << row[4] << endl;
            }
            mysql_free_result(res);
        } else {
            cout << "No Transactions Found!" << endl;
        }
    }

    ~BankingSystem() { mysql_close(conn); }
};

// Main Function
int main() {
    BankingSystem bank;
    int choice, accNum;
    double amount;
    string name;

    while (true) {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Transfer Money\n5. View Account\n6. View Transactions\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, name);
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
                cout << "Enter From Account: ";
                cin >> accNum;
                cout << "Enter To Account: ";
                cin >> toAcc;
                cout << "Enter Amount: ";
                cin >> amount;
                bank.transferMoney(accNum, toAcc, amount);
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.viewAccount(accNum);
                break;
            case 6:
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.viewTransactions(accNum);
                break;
            case 7:
                cout << "Exiting System..." << endl;
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}
