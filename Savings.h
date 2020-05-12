#include <iostream>
#include "BankAccount.h"

class Savings:public BankAccount
{
private:
	
	double interestRate;

public:

	Savings();
	Savings(double aSavBalance, double aInterest, string nameAccount);
	virtual double calculateMonthlyInterest();

};

