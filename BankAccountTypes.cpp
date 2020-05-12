#include <iostream>
#include "BankAccount.h"
#include "Checking.h"
#include "Savings.h"

using namespace std;

int BankAccount::accountNo = 0; //static variable set for generic account numbering

int main() {

	string keepAdding = "Y";
	vector<BankAccount*> userAccounts;		//vector of BankAccount pointers so derived objects don't get "sliced"
	string addName, accType;
	double addBal = 0;

	while (keepAdding == "Y" || keepAdding == "y") {		//lets user add as many of the three accounts as needed
		cout << "Enter the name for new account: " << endl;
		getline(cin, addName);
		cout << "Enter the starting balance for new account: " << endl;
		cin >> addBal;
		cout << "Enter the account type (B for basic, C for Checking, S for savings): ";
		cin >> accType;

		if (accType == "C" || accType == "c") {
			double tFee = 0;
			cout << "Account selected: Checking." << endl;
			cout << "Enter transaction fee for new checking account: ";
			cin >> tFee;
			userAccounts.push_back(new Checking(addBal, tFee, addName));
		}
		else if (accType == "S" || accType == "s") {
			double iRate = 0;
			cout << "Account selected: Savings." << endl;
			cout << "Enter interest rate for new savings account: ";
			cin >> iRate;
			userAccounts.push_back(new Savings(addBal, iRate, addName));
		}
		else {
			cout << "Account selected: Basic." << endl;
			userAccounts.push_back(new BankAccount(addBal, addName));
		}
		cout << "Add another account? Y/N" << endl;
		cin >> keepAdding;
	}

	for (unsigned int i = 0; i < userAccounts.size(); i++) {	//iterate through each account
		cout << "Processing Account: " << userAccounts.at(i)->getName() << endl;
		userAccounts[i]->debit();		//prompt for withdraw, then deposit
		userAccounts[i]->credit();
		if (userAccounts[i]->getType() == 'S') {	//separate piece for savings to add interest
			cout << "Calculating interest to add for Savings account." << endl;
			double mInterest = userAccounts[i]->calculateMonthlyInterest();
			userAccounts[i]->credit(mInterest);
		}
		cout << "The updated balance for " << userAccounts[i]->getName() << "'s account is $"
			<< userAccounts[i]->getBalance() << "." << endl << endl;	//display updated balance
	}

	return 0;

}