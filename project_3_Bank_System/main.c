#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_STRUCT 5            //number of customer
#define SIZE_OF_PASSWORD 5

unsigned char i;
unsigned char j;
unsigned int array_chech_pass; // global var to Check the password


void check_password(int value_check); // Function to check the password

void transaction_fun(void); // Function for transaction

void Update_account(void); // Function to update account information

void create_account(void); // Function to create a new account

void Check_account(void); // Function to check existing account details

void removing_exist_account(void); // Function to remove an existing account

void view_accounts(void); // Function to view all customer accounts


struct customer
{
     int account_num;
    char frist_name[50];
    char second_name[50];
    char address[50];
    int age;
    int password;
    long long phone;
    long long money;
    struct date
{
    int day;
    int month;
    int year;
}birthday,day_date;


}array[SIZE_OF_STRUCT];

struct customer *ptr=array;


int main()
{

    int choice,input;

do
   {
    printf("\n\t\t**********Customer Account Bank Mangment************\n");
      printf("\n\t\t************ Welcome To Main Menu ************\n\n");
            printf("1.Create Account\n2.Update information for exist account\n\
3.For transaction\n4.Check the details of exist account\n5.removing exist account\n\
6.View customer list\n7.Exit\n");
      printf("\nEnter your choice:");
     scanf("%i",&choice);

    switch(choice)
       {
         case 1:
                create_account();
         break;

        case 2:
               Update_account();
         break;

         case 3:
              transaction_fun();
         break;

         case 4:
             Check_account();
           break;

        case 5:
            removing_exist_account();
          break;

          case 6:
             view_accounts();
           break;

        case 7:
            return 0;
         break;
         default:
    printf("\nchoice num not valid\n");

      }
 printf("Enter 1 if you need another service: ");
        scanf("%i", &input);


    } while (input == 1);


    return 0;
}



/********************************************************************/
void check_password(int value_check) {
    int input_password; // Variable to store the user input password

    // Iterate through the array of accounts to find the specified account number
    for ( i = 0; i < SIZE_OF_PASSWORD; i++)
    {
        if (array[i].account_num == value_check)
         {
            // Prompt the user to enter the account password
            printf("Enter account password: ");
            scanf("%d", &input_password);

            // Check if the entered password matches the password associated with the account
            if (input_password != array[i].password)
                {
                // If passwords do not match, inform the user and terminate the program
                printf("Incorrect password. Program terminated.\n");
                while(1){};

                }
            // If passwords match, return from the function
            return;
        }
    }

    // If the account number is not found in the array, inform the user
    printf("Account number not found.\n");
}


/*******************************************************************/
void transaction_fun(void) {
    int account_num;
    int choice;
    int amount;

    // Prompt user for account number
    printf("Enter account number: ");
    scanf("%d", &account_num);
    printf("\n");

    // Check password associated with the account
    check_password(account_num);

    // Iterate through the array of accounts to find the specified account
    for ( i = 0; i < SIZE_OF_STRUCT; i++) {
        if (account_num == array[i].account_num) {
            // Prompt user for the type of transaction
            printf("Which operation do you want to perform:\n1. Deposit\n2. Withdraw\n");
            scanf("%d", &choice);

            // Process user's choice
            switch (choice) {
                case 1:
                    // Deposit operation
                    printf("Enter the amount you want to deposit: $ ");
                    scanf("%d", &amount);
                    // Update account balance
                    array[i].money += amount;
                    // Print updated balance
                    printf("\nYour new balance is: $%d\n", array[i].money);
                    // Inform user that deposit is completed
                    printf("\nDeposit completed.\n");
                    return;

                case 2:
                    // Withdrawal operation
                    printf("Enter the amount you want to withdraw: $ ");
                    scanf("%d", &amount);
                    if (amount <= array[i].money) {
                        // Withdrawal amount does not exceed balance, proceed with withdrawal
                        // Update account balance
                        array[i].money -= amount;
                        // Print updated balance
                        printf("\nYour new balance is: $%d\n", array[i].money);
                        // Inform user that withdrawal is completed
                        printf("\nWithdrawal completed.\n");
                    } else {
                        // Insufficient funds for withdrawal
                        printf("\nInsufficient funds for withdrawal.\n");
                    }
                    return;

                default:
                    // Invalid choice
                    printf("Invalid choice.\n");
                    return;
            }
        }
    }

    // Account number not found
    printf("Account number not found.\n");
}

/******************************************************************/
void Update_account(void) {
    int account_num;
    printf("Enter account number: ");
    scanf("%d", &account_num);
    printf("\n");

    check_password(account_num);

    for (i = 0; i < SIZE_OF_STRUCT; i++) {
        if (account_num == array[i].account_num) {
            int choice;
            printf("Which information do you need to update:\n1. Phone number\n2. Password\n3. Address\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new phone number: ");
                    scanf("%lld", &array[i].phone);
                    break;

                case 2:
                    printf("Enter new password: ");
                    scanf("%d", array[i].password); // Assuming password is a string
                    break;

                case 3:
                    printf("Enter new address: ");
                    scanf("%s", array[i].address);
                    break;

                default:
                    printf("Invalid choice.\n");
                    return;
            }

            printf("Update done...\n");
            return;
        }
    }

    printf("Account number not valid.\n");
}


/*********************************************************************/
 void create_account(void)
 {

printf("Enter today's date (dd/mm/yyyy):\n");
printf("day:");
scanf("%d",&ptr->day_date.day);
printf("month:");
scanf("%d",&ptr->day_date.month);
printf("year:");
scanf("%d",&ptr->day_date.year);
printf("\n");

printf("Enter account number:");
scanf("%d",&ptr->account_num);
printf("\n");

printf("Enter frist  name :");
scanf("%s",ptr->frist_name);
printf("\n");

printf("Enter second  name :");
scanf("%s",ptr->second_name);
printf("\n");

printf("Enter the amount to deposit:$");
scanf("%lld",&ptr->money);
printf("\n");

/********************************************************************/

printf("Enter account password ( only 4 (number) ):\n");
scanf("%d",&ptr->password);

printf("Enter account password agian :\n");
scanf("%d",&array_chech_pass);

 if(array_chech_pass!=ptr->password)
    {
        printf("\n\nOPS!! Try again\n\n");
        return 0;
    }



printf("\n");


/**********************************************************************/


printf("Enter your birthday (dd/mm/yyyy):\n");
printf("day:");
scanf("%d",&ptr->birthday.day);
printf("month:");
scanf("%d",&ptr->birthday.month);
printf("year:");
scanf("%d",&ptr->birthday.year);
printf("\n");

printf("Enter the age :");
scanf("%d",&ptr->age);
printf("\n");

printf("Enter your address (ex:ismailia) :");
scanf("%s",ptr->address);
printf("\n");

printf("Enter your phone(+20 ):");
scanf("%lld",&ptr->phone);
printf("\n");

ptr++;

printf("Create account successfully!!\n\n");

 }


/*********************************************************************************/
 void Check_account(void) {
    int input;
    printf("Enter your account number: ");
    scanf("%d", &input);
    printf("\n");

    // Call a function to check the password associated with the account
    check_password(input);

    // Loop through the array to find the account with the entered account number
    for (i = 0; i < SIZE_OF_STRUCT; i++) {
        if (input == array[i].account_num) {
            printf("Account Number: %d\n", array[i].account_num);
            printf("Name: %s %s\n", array[i].frist_name, array[i].second_name);
            printf("Phone: %d\n", array[i].phone);
            printf("Address: %s\n", array[i].address);
            printf("Amount of Deposit: $%d\n", array[i].money);
            printf("Birthday: %d/%d/%d\n", array[i].birthday.day, array[i].birthday.month, array[i].birthday.year);
            printf("Done...\n");
            return;
        }
    }

    // If the account number is not found, print an error message
    printf("Account number not found.\n");
}


/*********************************************************************************/
void removing_exist_account(void) {
    int input;
    printf("Enter account number: ");
    scanf("%d", &input);
    printf("\n");

    // Check password associated with the account
    check_password(input);

    int found = 0; // Flag to indicate if the account was found

    for (i = 0; i < SIZE_OF_STRUCT; i++) {
        if (input == array[i].account_num) {
            // Shift elements to remove the account
            for ( j = i; j < SIZE_OF_STRUCT - 1; j++) {
                array[j] = array[j + 1];
            }
            found = 1; // Set flag to indicate account was found
            break; // Exit loop after removing the account
        }
    }

    if (found) {
        printf("Account %d removed.\n", input);
    } else {
        printf("Account number not found.\n");
    }
}


/*********************************************************************************/
void view_accounts(void)
{
     printf("\n**** View all coustomers *****\n*************************\n");

    // Loop through the array of accounts and print details
    for ( i = 0; i < SIZE_OF_STRUCT; i++)
     {
        printf("Account Number: %d\n", array[i].account_num);
        printf("Name: %s %s\n", array[i].frist_name, array[i].second_name);
        printf("Phone: %d\n", array[i].phone);
        printf("Address: %s\n", array[i].address);
        printf("Amount of Deposit: $%d\n", array[i].money);
        printf("Birthday: %d/%d/%d\n", array[i].birthday.day, array[i].birthday.month, array[i].birthday.year);
        printf("\n");
    }
}

