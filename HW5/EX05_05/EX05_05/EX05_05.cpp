#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
  int id;
  double balance;
  static double annualInterestRate;
  string customer;
  
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

  int    getId() { return id; }
  double getBalance() { return balance; }
  double getAnnualInterestRate() { return annualInterestRate; }

  void setId(int idInput) { id = idInput; }
  void setBalance(double balanceInput) { balance = balanceInput; }
  void setAnnualInterestRate(double interest) { annualInterestRate = interest; }


  double getMonthyInterestRate() {
    return annualInterestRate / 12;
  }
  void withdraw(double amount) {
    balance -= amount;
  }
  void deposit(double amount) {
    balance += amount;
  }
};

int main() {

}