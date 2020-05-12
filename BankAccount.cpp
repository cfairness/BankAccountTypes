#include "BankAccount.h"


BankAccount::BankAccount()
{
	accountType = 'B';
	accountBalance = 0;
	accountNo++;
	accountName = "Generic Account " + to_string(accountNo);
}

BankAccount::BankAccount(double aSavingsBalance, string nameAccount) {	//constructor takes name input for account

	accountNamer(nameAccount);
	accountType = 'B';		//account type set in each constructor for method getType

	if (aSavingsBalance < 0) {
		cout << "The initial balance was invalid! Setting balance to $0.00." << endl;
		accountBalance = 0;
	}
	else {
		cout.precision(2);
		accountBalance = aSavingsBalance;
		cout << "The account's balance is $" << fixed << accountBalance << "." << endl;
	}
}

void BankAccount::accountNamer(string newName) {   //checks for empty string in account name
	accountNo++;
	if (newName.empty()) {
		accountName = "Generic Account " + to_string(accountNo);
		cout << "No account name entered, setting name to " << accountName << endl;
	}
	else accountName = newName;
}

string BankAccount::getName() { return accountName; }
char BankAccount::getType() { return accountType; }

bool BankAccount::credit() {
	double credToAdd;
	bool wasAdded;
	cout << "Enter the funds to be added to this account:";
	cin >> credToAdd;
	if (credToAdd <= 0) {
		cout << "Invalid Entry. No funds were added." << endl;
		wasAdded = false;
	}
	else {
		cout.precision(2);
		cout << "Adding $" << fixed << credToAdd << " to account." << endl;
		accountBalance = accountBalance + credToAdd;
		cout << "New balance comes to: $" << accountBalance << "." << endl;
		wasAdded = true;
	}
	return wasAdded;
}

void BankAccount::credit(double addCred) {	//additional credit method which doesn't grab user input
	cout.precision(2);
	cout << "Adding $" << fixed << addCred << " to account." << endl;
	accountBalance = accountBalance + addCred;
	cout << "New balance comes to: $" << accountBalance << "." << endl;
}

bool BankAccount::debit() {
	double subDebit;
	bool wasDeduct;
	cout << "Enter the funds to be withdrawn from this account:";
	cin >> subDebit;
	cout << "Attempting to withdraw funds..." << endl;
	if (subDebit > accountBalance) {
		cout << "The balance is less than the debit amount." << endl;
		wasDeduct = false;
	}
	else if (subDebit <= 0) {
		cout << "Invalid entry. No funds withdrawn." << endl;
		wasDeduct = false;
	}
	else {
		cout.precision(2);
		cout << "Successfully withdrew $" << fixed << subDebit << " from the account." << endl;
		accountBalance = accountBalance - subDebit;
		cout << "New balance comes to: $" << fixed << accountBalance << "." << endl;
		wasDeduct = true;
	}
	return wasDeduct;
}

double BankAccount::getBalance() {
	return accountBalance;
}

double BankAccount::calculateMonthlyInterest() { return 0; }		//zero-return version of this method so a Savings class can call its version via vector
