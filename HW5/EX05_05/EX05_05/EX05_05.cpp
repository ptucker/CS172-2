#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// 20/20

//PT -- put these in separate files
class Date {
private:
  int year, month, day;
public:

  Date() {
    time_t tt;
    time(&tt);
    tm TM = *localtime(&tt);
    year = TM.tm_year + 1900;
    month = TM.tm_mon;
    day = TM.tm_mday;
  }

  Date(int yearInput, int monthInput, int dayInput) {
    year = yearInput;
    month = monthInput;
    day = dayInput;
  }

  int getYear() { return year; }
  int getDay() { return day; }
  int getMonth() { return month; }
};




class Transaction {
private:
  Date date;
  char type;

  double amount;
  double balance;
  string description;
public:
  Transaction() {

  }
  Transaction(char typeInput, double amountInput, double balanceInput, string descriptionInput) {
    type = typeInput;
    amount = amountInput;
    balance = balanceInput;
    description = descriptionInput;
  }

  void setValues(char typeInput, double amountInput, double balanceInput, string descriptionInput) {
    type = typeInput;
    amount = amountInput;
    balance = balanceInput;
    description = descriptionInput;
  }

  void setType(char set) { type = set; }
  void setAmount(double set) { amount = set; }
  void setBalance(double bal) { amount = bal; }
  void setAmount(string setDesc) { description = setDesc; }

  const char getType() { return type; }
  const double getAmount() { return amount; }
  const double getBalance() { return balance; }
  const string getDescription() { return description; }

};




class Account {
private:
  int id;
  double balance;
  static double annualInterestRate;
  string customer;
  
  vector<Transaction> transactions;
  int numberOfTransactions = 0;
public:
  Account() {
    id = 0;
    balance = 0.0;
    annualInterestRate = 0.0;
  }
  Account(string name, int idInput, double balanceInput) {
    customer = name;
    id = idInput;
    balance = balanceInput;
  }

  string getName() { return customer; }
  int    getId() { return id; }
  double getBalance() { return balance; }
  double getAnnualInterestRate() { return annualInterestRate; }

  void setName(string name) { customer = name; }
  void setId(int idInput) { id = idInput; }
  void setBalance(double balanceInput) { balance = balanceInput; }
  void setAnnualInterestRate(double interest) { annualInterestRate = interest; }


  double getMonthyInterestRate() {
    return annualInterestRate / 12;
  }
  void withdraw(double amount) {
    balance -= amount;
    Transaction *temp = new Transaction('W', amount, balance, "Standard withdraw");
    transactions.push_back(*temp);
    numberOfTransactions++;
  }
  void deposit(double amount) {
    balance += amount;
    Transaction *temp = new Transaction('D', amount, balance, "Standard deposit");
    transactions.push_back(*temp);
    numberOfTransactions++;
  }

  void getTrasactionData() {
    for (int output = 0; output < numberOfTransactions; output++) {
     cout << "Type of transaction: " << transactions[output].getType() << endl;
     cout << "Transaction amount: " << transactions[output].getAmount() << endl;
     cout << "Balance after transaction: " << transactions[output].getBalance() << endl;
     cout << "Transaction description: " << transactions[output].getDescription() << endl;
     cout << endl;
    }
  }
};

//Have to define outside class
double Account::annualInterestRate = 0;

int main() {
  Account customer1("George", 1122, 1000);
  customer1.setAnnualInterestRate(0.015);
  customer1.deposit(30);
  customer1.deposit(40);
  customer1.deposit(50);
  customer1.withdraw(5);
  customer1.withdraw(4);
  customer1.withdraw(2);
  cout << "Customer name: " << customer1.getName() << endl;
  cout << "Interest Rate: " << customer1.getAnnualInterestRate() << endl;
  cout << "Balance: " << customer1.getBalance() << endl;
  cout << "Transactions:" << endl;
  customer1.getTrasactionData();

}
