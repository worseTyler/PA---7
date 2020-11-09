#ifndef CheckingAccount_H
#define CheckingAccount_H

#include "Bank Accout.h"

class CheckingAccount : public BankAccount {
public:
	void withdraw();
	void monthlyProc();
};

#endif // !CheckingAccount_H

