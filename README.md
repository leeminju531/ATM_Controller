# ATM_Controller
Implement a simple ATM controller, based on c++ program
## file description 
![image](https://user-images.githubusercontent.com/70446214/105352872-d6b0dc80-5c31-11eb-92cb-38d17d367b43.png)

- as you can see, DB[][3] is temporary Database. column of array DB[][3] is based on {pin Number, Checking Account Balance, Saving Account Balance}.
if you wanna add new things , you can register.
please, add or modify 'DB[][3]' in conformity with this at ATM_Project/CutstomerDB.h 

- the parent class , AccountSetting, is able to See Balance/Deposit/Withdraw . and Inherited classes, CheckingAcount and SavingAccount, don't have new function.
I just organized the file considering the modification of functions according to the account in the future.



## Instruction


More Detail ) if you normally build 'main.cpp', please enter pin number based on console printing instruction.
if you Enter Pin number '1234' then internally object is formed based on DB[].

after pin Number, please select Account(Checking Account, or Saving Account).
depending on the account you choose, you can follow the options you want : See Balance, Deposit, WithDraw.

