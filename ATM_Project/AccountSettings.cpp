#include "AccountSettings.h"


void AccountSettings::Deposit(int money) { //예금
	if (money > 0) {
		int amount = GetBalance() + money;
		SetBalance(amount);
	}
}

// 출금을 원하는 돈보다 잔액이 없을시 -1을 반환한다.
int AccountSettings::WithDraw(int money) { //출금
	int amount = GetBalance();
	if (amount >= money) {
		amount -= money;
		SetBalance(amount);
		return 0;
	}

	return -1;
}
