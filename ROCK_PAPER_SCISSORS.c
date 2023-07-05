#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

void calculateChoices(int user_choice, int comp_choice){
    switch(user_choice){
        case 1:
            printf("Your choice was Rock.\ncalculating...\n");
            Sleep(1000);
            if(user_choice == comp_choice){
                printf("DRAW\nBoth of u chosen rock\n");
            } else if(user_choice != comp_choice && comp_choice == 2){
                printf("You lost computer choosen paper\n");
            } else{
                printf("You WON computer chossen scissors\n");
            }
            break;
        case 2:
            printf("Your choice was Paper.\ncalculating...\n");
            Sleep(1000);
            if(user_choice == comp_choice){
                printf("DRAW\nBoth of u chosen paper\n");
            } else if(user_choice != comp_choice && comp_choice == 3){
                printf("You lost computer choosen scissors\n");
            } else{
                printf("You WON computer chossen rock\n");
            }
            break;
        case 3:
            printf("Your choice was Scissors.\ncalculating...\n");
            Sleep(1000);
            if(user_choice == comp_choice){
                printf("DRAW\nBoth of u chosen scissors\n");
            } else if(user_choice != comp_choice && comp_choice == 1){
                printf("You lost computer choosen rock\n");
            } else{
                printf("You WON computer chossen paper\n");
            }
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
}

int main(void){
    int user_choice;
    time_t t;
    srand((unsigned) time(&t));
    int retry;
    while(retry != 1){
        int comp_choice = rand()%3+1;
        printf("Rock, Paper, Scissors Game\nPlease Input your choice.\n1.Rock 2.Paper 3.Scissors\n");
        scanf("%d", &user_choice);
        calculateChoices(user_choice, comp_choice);
        printf("\nRETRY?\n1.NO 2.YES\n");
        scanf("%d", &retry);
    }


    return 0;
}