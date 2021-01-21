#include <iostream>
#include "AccountSettings.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "CustomerDB.h"

using namespace std;

extern int DB[][3];
extern int DB_Count;
int userIndex;

enum SelectAccount {
	CHECKING = 1,
	SAVING = 2,
	EXIT = 3
};

enum SelectFunction {
	SEE_BALANCE = 1,
	WITHDRAW = 2,
	DEPOSIT = 3,
	FunctionExit =4
};



bool ValidatePin(int user_pin) {
	for (int i = 0; i < DB_Count; i++)
		if (DB[i][PIN_NUMBER] == user_pin) {
			userIndex = i;
			return true;
		}

	return false;
}

int select_Account() {
	int option;

	while (true) {
		cout << "\n 1. Checking Account " << endl;
		cout << " 2. Saving Account " << endl;
		cout << " 3. Exit" << endl;
		cout << " Please, Select Account : ";
		cin >> option;
		if (option == CHECKING || option == SAVING || option == EXIT)	break;
		else	cout << "\n Please, select one of 1 ,2 ,3" << endl;
	}
	return option;

}

int select_Function() {
	int option;

	while (true) {
		cout << "\n 1. See balance" << endl;
		cout << " 2. Withdraw" << endl;
		cout << " 3. Deposit " << endl;
		cout << " 4. EXIT" << endl;
		cout << " Please, Select Option : ";
		cin >> option;
		if (option == SEE_BALANCE || option == WITHDRAW || option == DEPOSIT || option == FunctionExit)	break;
		else	cout << "\n Please, select one of 1, 2, 3, 4" << endl;
	}
	return option;
}



void view(AccountSettings* ac) {
	int option;
	do {
		option = select_Function();
		switch (option) {
		case SEE_BALANCE:
			cout << "\n Your Account Balance is : $" << ac->GetBalance() << endl;
			break;
		case WITHDRAW:
			cout << " Please enter amount to withdrawn :" ;
			int withdrawAmount;
			cin >> withdrawAmount;
			if (withdrawAmount < 0) {
				cout << "\n input value is negative value " << endl;
			}
			else {
				int before_AccountBalance = ac->GetBalance();
				if (ac->WithDraw(withdrawAmount) == -1) {
					cout << "\n Your Account Balance is : $" << ac->GetBalance() << endl;
					cout << " Withdraw Amount over Your Account Balance " << endl;
				}
				else {
					cout << "\n Before Your Account Balance is : $" << before_AccountBalance << endl;
					cout << " Current Your Account Balance is : $" << ac->GetBalance() << endl;
				}

			}

			break;
		case DEPOSIT:
			cout << " Please enter an amount to deposit :";
			int depositAmount;
			cin >> depositAmount;
			if (depositAmount < 0) {
				cout << "\n input value is negative value " << endl;
			}
			else {
				ac->Deposit(depositAmount);
				cout <<"\n $ "<< depositAmount << " was deposited into your account" << endl;
				cout << " Account Balance is : $" << ac->GetBalance() << endl;
			}
			break;
		}
		cout << "\n Would you like to Continue (y/n)? :" ;
		string response;
		cin >> response;
		if (response == "n" || response == "N")	option = FunctionExit;

	} while (option != FunctionExit);
	

}

int main() {
	
	int user_pin, pin_err_count=0;
	
	do {
		cout << " Please enter your pin Number to access your account : ";
		cin >> user_pin;
		if (ValidatePin(user_pin)) {
			int option = select_Account();

			AccountSettings* account = new AccountSettings;
			AccountSettings* temp = account;
			CheckingAccount checkingAccout(DB[userIndex][CHECKING_ACCOUNT_BALANCE]);
			SavingAccount savingAccount(DB[userIndex][SAVING_ACCOUNT_BALANCE]);
	

			switch (option) {
				case CHECKING:
					account = &checkingAccout; 
					break;
				case SAVING:
					account = &savingAccount;
					break;
				case EXIT:
					goto END;
			}
			
			
			view(account);
	



			
			DB[userIndex][3] = account-> GetBalance();
			
			delete temp;
			END:
			cout << " Have a good day, Thank you." << endl;

		}
		else {
			if (pin_err_count >= 5) {
				cout << " 5 times Pin num Error occured, The program will be terminated." << endl;
				break;
			}
			cout << ++pin_err_count << " Pin num Error Occured, Exit program if more than 5 times" << endl;

		}
	} while (!ValidatePin(user_pin));

	return 0;

}