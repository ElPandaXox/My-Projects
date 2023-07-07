#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define checkingButton 1
#define savingsButton 2
#define addButton 1
#define subtractButton 2
#define restartButton 8
#define exitButton 9

bool exitProgram = false;

void manageCheckingAccount(int);
void manageSavingsAccount(int);

double checkingBalance = 100;
double *pCheckingBalance = &checkingBalance;

double savingsBalance = 200;
double *pSavingsBalance = &savingsBalance;

double add, subtract;


void intro(int userChoice){
    printf("\nHello welcome to the Bank of Money\nPlease choose a option\n1.Checking 2.Savings\nPRESS '9' TO EXIT PROGRAM\n");
    scanf("%d", &userChoice);
    switch(userChoice){
        case checkingButton:
            printf("You chosen your Checkings account.\nYour current balances is\n%.2f\n", *pCheckingBalance);
            printf("What will you like to do?\n1.Add money on Account 2.Remove money on Account\nIf you would like to go back/exit please press '8'\n");
            scanf("%d", &userChoice);
            if(userChoice == restartButton){
                intro(userChoice);
            } else {
                manageCheckingAccount(userChoice);
            }
            break;

        case savingsButton:
            printf("You chosen your Savings account.\nYour current balances is\n%.2f\n", *pSavingsBalance);
            printf("What will you like to do?\n1.Add money on Account 2.Remove money on Account\nIf you would like to go back/exit please press '8'\n");
            scanf("%d", &userChoice);
            if(userChoice == restartButton){
                intro(userChoice);
            } else{
                manageSavingsAccount(userChoice);
            }
            break;
        
        case exitButton:
            exitProgram = true;
            break;

        default:
            printf("Invalid Input\n");
            break;
            
            }
}

void manageCheckingAccount(int userChoice){
    switch (userChoice){
    case addButton:
        printf("How much do you want to add?\nFrom your Checking Account\n");
        scanf("%lf", &add);
        *pCheckingBalance = *pCheckingBalance + add;
        printf("Your current balance is\n%.2f", *pCheckingBalance);
        break;

    case subtractButton:
        printf("How much do you want to subtract?\nFrom your Checking Account\n");
        scanf("%lf", &subtract);
        if(subtract > *pCheckingBalance){
            printf("Cannot remove money that you don't have\n");
        } else {
            *pCheckingBalance = *pCheckingBalance - subtract;
            printf("Your current balance is\n%.2f", *pCheckingBalance);
        }
        break;

    default:
        printf("Invalid Input\n");
        break;
    }
}

void manageSavingsAccount(int userChoice){
    switch (userChoice){
    case addButton:
        printf("How much do you want to add?\nFrom your Savings Account\n");
        scanf("%lf", &add);
        *pSavingsBalance = *pSavingsBalance + add;
        printf("Your current balance is\n%.2f\n", *pSavingsBalance);
        break;

    case subtractButton:
        printf("How much do you want to subtract?\nFrom your Savings Account\n");
        scanf("%lf", &subtract);
        if(subtract > *pSavingsBalance){
            printf("Cannot remove money that you don't have\n");
        } else {
            *pSavingsBalance = *pSavingsBalance - subtract;
            printf("Your current balance is\n%.2f\n", *pSavingsBalance);
        }
        break;

    default:
        printf("Invalid Input\n");
        break;
    }
}



int main(void){
    int userChoice;
    while(exitProgram != true){
        intro(userChoice);
    }
    

    return 0;
}