#include "Saving Account.h"

SavingsAccount::SavingsAccount(double in_bal, double in_apr) : BankAccount(in_bal, in_apr) {
	if (balance >= 25)
		status = true;
	else
		status = false;
}

void SavingsAccount::deposit(double deposit) {
	balance += deposit;
	if (status == false && balance >= 25)
		status = true;
}

void SavingsAccount::withdraw(double withdrawl) {
	if (status == false)
		return;
	BankAccount::withdraw(withdrawl);
}

void SavingsAccount::monthlyProc() {
	if (num_withdrawls > 4)
		service_charges += (num_withdrawls - 4);
	BankAccount::monthlyProc();
	if (balance < 25)
		status = false;
}