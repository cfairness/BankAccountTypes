#ifndef BankAccount_HEADER
#define BankAccount_HEADER
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount		//header file for base class BankAccount
{

private:

	double accountBalance;
	string accountName;
	static int accountNo;
	char accountType;

public:
	friend class Savings;  //add class Savings and class Checking as friend classes
	friend class Checking;

	BankAccount();  //blank constructor for BankAccount object
	BankAccount(double aSavingsBalance, string nameAccount);  //constructor for BankAccount object that takes parameters
	void accountNamer(string newName);
	string getName();
	char getType();
	virtual bool credit();
	void credit(double addCred);  //additional credit method which does not grab user input
	virtual bool debit();
	double getBalance();
	virtual double calculateMonthlyInterest();

};

#endif

