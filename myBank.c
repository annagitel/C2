#include <stdio.h>
#include "myBank.h"
double MATRIX[ROW][COL]={0};			//initing the bank matrix

//openAccount function gets the place of the last bank account that was open
//will change the firs place in the row to 1, and the secont place to the scaned deposit 
void openAccount(int counter){
    double amount;
    printf("Enter Initial deposit: \n");
    scanf("%lf",&amount);
    MATRIX[counter][0] = 1;
    MATRIX[counter][1] = amount;
}

//prints the balance of the accout number was scanned 
void checkBalance(){
    int account_number;
    printf("Enter account number: \n");
    scanf("%d",&account_number);
    if (MATRIX[account_number-901][0]==1)
        printf("your account balance is %0.2lf \n", MATRIX[account_number-901][1]);
    else
        printf("account is not open \n");
}


//add the given deposit to the given bank number account 
void depositing(){
    int account_number;
    double amount;
    printf("Enter account number: \n");
    scanf("%d",&account_number);
    printf("Enter deposit: \n");
    scanf("%lf",&amount);

    if (MATRIX[account_number-901][0]==1){
        MATRIX[account_number-901][1]=MATRIX[account_number+901][1]+amount;
        printf("new account balance is: %0.2lf \n", MATRIX[account_number+901][1]);
    }
    else
        printf("account is not open");
}

//substruct the given deposit from the given bank account number
void withrawal(){
    int account_number;
    double amount;
    printf("Enter account number: \n");
    scanf("%d", &account_number);
    printf("Enter deposit: \n");
    scanf("%lf", &amount);

    if (MATRIX[account_number-901][0] == 1) {
	if (MATRIX[account_number-901][1]<amount){
		printf("You dont have anough money in your account");
	}
	else{
        	MATRIX[account_number-901][1] = MATRIX[account_number-901][1] - amount;
        	printf("new account balance is: %0.2lf \n", MATRIX[account_number-901][1]);
	}
    }
    else
        printf("account is not open \n");
}

//will change the firs place in the row to 0, and the secont place to 0 
void closeAccount(){
    int account_number;
    printf("Enter account number: \n");
    scanf("%d", &account_number);

    if (MATRIX[account_number-901][0] == 1){
        MATRIX[account_number-901][0] = 0;
	MATRIX[account_number-901][1] = 0;
        printf("account has been closed. \n");
    }
    else
        printf("account is not open \n");
}

//add a given % interest rate to all the open accounts
void interest(){
    double interest;
    printf("Enter interest rate: \n");
    scanf("%lf", &interest);
    for(int i; i<50; i++){
        if (MATRIX[i-901][0] == 1){
            MATRIX[i-901][1] = MATRIX[i-901][1]*(interest+100)/100;
        }
    }
}

//prints current deposit on all open accounts
void printAllOpen(){
    for(int i;i<50;i++){
        if (MATRIX[i-901][0]==1){
            printf("account number is: %d and current balance is: %0.2lf \n", i+901, MATRIX[i+901][1]);
        }
    }
}

//closes all accounts
void exitallprogram(){
    for(int i;i<50;i++){
        MATRIX[i-901][0] = 0;
	MATRIX[i-901][1] = 0;
    }
}


