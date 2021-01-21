#pragma once
#include "AccountSettings.h"

class CheckingAccount : public AccountSettings {
public:
	CheckingAccount(int checkingBalance) :AccountSettings(checkingBalance) {};
};
