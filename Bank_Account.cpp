#include "Bank Accout.h"

BankAccount::BankAccount(double in_balance, double in_apr) {
	balance = in_balance;
	apr = in_apr;
	num_deposits = 0;
	num_withdrawls = 0;
}

void BankAccount::deposit(double deposit) {
	balance += deposit;
	num_deposits++;
}

void BankAccount::withdraw(double withdrawl) {
	balance -= withdrawl;
	num_withdrawls++;
}

void BankAccount::calcInt() {
	double monthly_interest_rate = apr / 12;
	double monthly_interest = balance * monthly_interest_rate;
	balance += monthly_interest;
}

void BankAccount::monthlyProc() {
	balance -= service_charges;
	calcInt();
	num_deposits = 0;
	num_withdrawls = 0;
	service_charges = 0; //where do i set service charges??
}