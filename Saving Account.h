#ifndef SavingsAccount_H 
#define SavingAccount_H

#include "Bank Accout.h"

class SavingsAccount : public BankAccount {
protected:
	bool status;
public:
	SavingsAccount(double in_bal, double in_apr) : BankAccount(in_bal, in_apr);

	void deposit(double);
	void withdraw(double);
	void monthlyProc();
};


#endif // !SavingsAccount_H 

