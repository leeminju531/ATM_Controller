#pragma once
#ifndef DB_H
#define DB_H

#define PIN_NUMBER 0
#define CHECKING_ACCOUNT_BALANCE 1
#define SAVING_ACCOUNT_BALANCE 2

// DB = {  {PIN Number1 , Checking Accoung Balance1 , Saving Account Balance1} , 
//		   {PIN Number2 , Checking Accoung Balance2 , Saving Account Balance2} ....}

int DB[][3] = { { 1234,100,200 },{2453,200,100},{2413,120,520},{1235,200,100} };
int DB_Count = sizeof(DB) / sizeof(DB[0]);

#endif