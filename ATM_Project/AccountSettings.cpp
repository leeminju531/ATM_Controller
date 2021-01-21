#include "AccountSettings.h"


void AccountSettings::Deposit(int money) { //����
	if (money > 0) {
		int amount = GetBalance() + money;
		SetBalance(amount);
	}
}

// ����� ���ϴ� ������ �ܾ��� ������ -1�� ��ȯ�Ѵ�.
int AccountSettings::WithDraw(int money) { //���
	int amount = GetBalance();
	if (amount >= money) {
		amount -= money;
		SetBalance(amount);
		return 0;
	}

	return -1;
}
