#pragma once
#include "AccountSettings.h"
class SavingAccount : public AccountSettings {
public:
	SavingAccount(int savingBalance);
};
SavingAccount::SavingAccount(int savingBalance) : AccountSettings(savingBalance) {
}