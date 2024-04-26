#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int number;
    string name;
    double balance;
public:
    BankAccount(int num = 0, string holdname = "", double hBalance = 0) : number(num), name(holdname), balance(hBalance) {}
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successfully!\n\n";
    }
    void withdraw(double amount) {
        if (balance < amount) cout << "Your balance is not enough!\n\n";
        else {
            balance -= amount;
            cout << "Withdraw successfully!\n\n";
        }
    }
    void check() {
        cout << "Your balance is now " << balance << " !\n\n";
    }
};

int main()
{
    int num;
    string holdname, s;
    int hBalance, amount;
    cout << "Enter your account number: ";
    cin >> num;
    cout << "Enter your name: ";
    getline(cin, holdname);
    char c = getchar();
    cout << "Enter your balance: ";
    cin >> hBalance;
    BankAccount* bankAcc = new BankAccount(num, holdname, hBalance);
    while (true) {
        cout << "\nOPTIONS\n1. Deposit\n2. Withdraw\n3. Check balance\n4. Exit\n\nYour option is: ";
        cin >> s;
        if (s.length() > 1 || s[0] < '1' || s[0] > '4') {
            cout << "Invalid input!\n\n";
            continue;
        }
        switch (s[0]) {
        case '4': goto x;
        case '3': bankAcc->check(); break;
        case '2': {
            cout << "Enter the amount you want to withdraw: ";
            cin >> amount;
            bankAcc->withdraw(amount);
            break;
        }
        case '1': {
            cout << "Enter the amount you want to deposit: ";
            cin >> amount;
            bankAcc->deposit(amount);
            break;
        }
        }
    }
x:;
    return 0;
}
