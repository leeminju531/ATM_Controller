#pragma once

#ifndef AC_SETTING
#define AC_SETTING


class AccountSettings {
private:
	int balance;
public:
	AccountSettings() { SetBalance(0); };
	AccountSettings(int balance) { SetBalance(balance); }
	void SetBalance(int balance) { this->balance = balance; }
	int GetBalance() { return balance; }
	void Deposit(int money); // amount ��ŭ ���� �� ����
	int WithDraw(int money); // amount ��ŭ ��� �� ����

};

#endif 