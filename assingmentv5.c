/*
Author: Denis Boyko (C22337741)
Date: 01/11/2022
IDE: VsCode
Compiler: GCC
OS: Windows 11

Program Description:
A program to enable bank customers to manage their Personal Identification Number (PIN) on an
Automated Teller Machine (ATM). The Pin is any 4-digit number. You can assume that the customer's
default PIN has been initially assigned the number: 1234

The program should be menu-driven and must display a simple menu when run. The
menu should display the following options:

1. Enter the PIN and verify correct
2. Change PIN
3. Display the number of times the PIN was entered (i) Successfully (ii) Incorrectly
4. Exit Program
*/

#include <stdio.h>
#define PINSIZE 4

int main() 
{//declaring all variables for the program
    int correctPin = 0;//declared when user enters the pin correctly
    int incorrectPin = 0;//declared when user enters the pin incorrectly
    int running = 1;//declared for looping the menu after a user enters an option
    int originalPin[PINSIZE] = {1,2,3,4};//declared for original pin
    int rePin = 0;//declares to check the new pin 
    int option = 0;//declared for the option menu
    int continueExit = 0;//declared for continuing or exiting the program
//this loops the menu until the user exits the program
    while (running == 1)
    {
//this is the menu
        printf("\n------------------------------------------------------------------------------------------------------\n");
        printf("ATM Machine\n");
        printf("Please enter an option:\n");
        printf("1.Verify Pin Number\n2.Change Pin Number\n3.Check the number of times pin has been entered correctly or incorrectly\n4.Exit Program\n");
        printf("------------------------------------------------------------------------------------------------------\n"); 
        printf("\nEnter option 1-4: ");
        scanf("%d", &option);
        while(getchar() != '\n');//this prevents "spacebar" from being a possible input
     

        switch(option)//switch statement to choose one of the options
        {
            case 1:;//case 1; pincheck, semicolon required becuase you cannot declare a variabel right after a label
                int pinCheck[PINSIZE] = {0,0,0,0};//declared to check wether the pin is correct or not
                printf("Please enter the PIN to check: ");
                scanf("%1d%1d%1d%1d", &pinCheck[0], &pinCheck[1], &pinCheck[2], &pinCheck[3]);//Using %1d to take 1 digit at a time
                while(getchar() != '\n');
                
                int isEqual = 1;//declaring a variable that tracks whether the 2 pins are equal which allows the incorrect and correct counters to be updated
                for(int i = 0; i < PINSIZE; i++)//
                {
                    if (pinCheck[i] != originalPin[i])
                    {
                        isEqual = 0;
                    }
                }// end for
              
                if (isEqual == 1)//confiriming pincheck is equal to the original pin
                {
                    printf("\nPin is Correct!\n\n");
                    correctPin++;//this updates the correct pin counter when entered correctly
                }// end if
                
                else //if not equal incorrect counter is updated
                {
                    printf("\nPin is Incorrect!!\n\n");
                    incorrectPin++;  
                }//end else if
                break;//break is just a statement
            
            case 2://case 2; newpin
                printf("Enter a new Pin (4 Digits): ");
                int newPin[4] ={0,0,0,0};//declared when user enters a new pin
                scanf("%1d%1d%1d%1d", &newPin[0], &newPin[1], &newPin[2], &newPin[3]);
                while(getchar() != '\n');
                
                printf("Re-Enter a new Pin (4 Digits): ");
                int ConfirmPin[4] = {0,0,0,0};//declared when user enters a new pin
                scanf("%1d%1d%1d%1d", &ConfirmPin[0], &ConfirmPin[1], &ConfirmPin[2], &ConfirmPin[3]);
                while(getchar() != '\n');

                int match = 1;//declaring a variable that tracks wether the confirmed pin is the same as the first pin
                for(int i = 0; i < PINSIZE; i++)
                {
                    if (newPin[i] != ConfirmPin[i])
                    match = 0;
                }// end for
                if(match != 1)//if the ConfirmPin is not the same as newPin then it prints the following statement
                {
                    printf("\nPin do not match, your Pin is still: ");
                    for (int i = 0; i < PINSIZE; i++)
                    {
                        printf("%d", originalPin[i]);
                    }    
                }//end if

                else//if rePin is the same as newPin
                {
                    printf("Pin changed successfully to ");
                    for (int i = 0; i < PINSIZE; i++)
                    {
                        printf("%d", newPin[i]);
                    }//end for
                    for(int i = 0; i < PINSIZE; i++)
                    {
                        originalPin[i] = newPin[i];
                    }//end for
                }//end else
                break;

            case 3://case 3; Pin counter for the correct and incorrect attempts
                printf("You have entered %d successful attempts to enter your Pin.\n", correctPin);//correctPin updates from case 1 when user enters the pin correctly
                printf("You have entered %d unsuccessful attempts to enter your Pin.\n", incorrectPin);//correctPin updates from case 1 when user enters the pin incorrectly
                break;

            case 4:
            
                printf("Program exiting");
                running = 0;
                break;
  

            default:
                printf("value:error\n\n");
                break;

        }//end switch
    }// end while

    return 0;
}//end main()