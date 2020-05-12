#include "Savings.h"


Savings::Savings() {
	accountBalance = 0;
	accountType = 'S';
	interestRate = 0;
	accountNo++;
	accountName = "Generic Account " + to_string(accountNo);
}

Savings::Savings(double aSavBalance, double aInterest, string nameAccount) {

	accountNamer(nameAccount);
	accountType = 'S';

	if (aSavBalance < 0) {
		cout << "The initial balance was invalid! Setting balance to $0.00." << endl;
		accountBalance = 0;
	}
	else {
		cout.precision(2);
		cout << "Setting initial balance to $" << fixed << aSavBalance << "." << endl;
		accountBalance = aSavBalance;
	}

	if (aInterest < 0) {
		cout << "The initial interest rate was invalid! Setting rate to 0.0." << endl;
		interestRate = 0;
	}
	else {
		cout << "Setting interest rate to %" << aInterest << "." << endl;
		interestRate = aInterest;
	}
}

double Savings::calculateMonthlyInterest() {
	double monthlyInterest = (accountBalance * interestRate) / 1200;
	return monthlyInterest; //calculates monthly interest figure
}