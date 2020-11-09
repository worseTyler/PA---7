#ifndef BankAccount_H
#define BankAccount_H

class BankAccount {
protected:
	double balance;
	int num_deposits;
	int num_withdrawls;
	double apr;
	double service_charges;
public:
	BankAccount(double, double);

	virtual void deposit(double);
	virtual void withdraw(double);
	virtual void calcInt();
	virtual void monthlyProc();
};


#endif