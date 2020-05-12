#include <iostream>
#include "BankAccount.h"


class Checking:public BankAccount
{

private:

	double transactionFee;

public:

	Checking();
	Checking(double chkBalance, double aFee, string nameAccount);
	virtual bool credit();
	virtual bool debit();
};

