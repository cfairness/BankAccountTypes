#include "Checking.h"

Checking::Checking() {
	accountBalance = 0;
	transactionFee = 0;
	accountType = 'C';
	accountNo++;
	accountName = "Generic Account " + to_string(accountNo);
}

Checking::Checking(double chkBalance, double aFee, string nameAccount) {

	accountNamer(nameAccount);
	accountType = 'C';

	if (chkBalance < 0) {
		cout << "The initial balance was invalid! Setting balance to $0.00." << endl;
		accountBalance = 0;
	}
	else {
		cout.precision(2);
		cout << "Setting initial checking balance to $" << fixed << chkBalance << " as requested." << endl;
		accountBalance = chkBalance;
	}
	if (aFee < 0) {
		cout << "The transaction fee was invalid! Setting fee to 0.0." << endl;
		transactionFee = 0;
	}
	else {
		cout.precision(2);
		cout << "Setting transaction fee to $" << fixed << aFee << "." << endl;
		transactionFee = aFee;
	}
}

bool Checking::credit() {
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
	if (wasAdded) {
		cout.precision(2);
		cout << "Adding transaction fee..." << endl;
		accountBalance = accountBalance - transactionFee;
		cout << "After transaction fees the checking balance comes to: $" << fixed << accountBalance << "." << endl;
	}
	return wasAdded;
}

bool Checking::debit() {
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
	if (wasDeduct) {
		cout.precision(2);
		cout << "Adding transaction fee..." << endl;
		accountBalance = accountBalance - transactionFee;
		cout << "After transaction fees the checking balance comes to: $" << fixed << accountBalance << "." << endl;
	}
	return wasDeduct;
}