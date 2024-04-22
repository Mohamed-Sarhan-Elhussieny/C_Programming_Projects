#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_STRUCT 10

unsigned char i;    // glabal variable for arrays
unsigned char j;


struct family_member
{
    char name[20];
    int year;
    int month;
    int day;

}array[SIZE_OF_STRUCT];

/*********************************** MAIN ***********************************/
int main()
{
     int i,j;
     int choose,input,input2;
    struct family_member*ptr=array;


for(;;)
{

    printf("\t\n\n Hello %c%c\n\n",3,3);
    for(i=0;i<3;i++)
    {
        for(j=0;j<30;j++)
        {
            printf("*");
            if(i==1 && j==5)
            {
                printf(" Brithday List ");
                 j=20;
            }
        }
    printf("\n");
    }

   printf(" 1-View all family \n 2-Add new member %c\n 3-Search :)\n 4-Delet Someone :( \n 5-Exit \n",2);
  scanf("%i",&choose);

switch(choose)
{
/***********************************************************************************/
    case 1:
          printf("\n**** View all family *****\n*************************\n");
        for(i=0;i<SIZE_OF_STRUCT;i++)
     {
         printf("%i-Name:%s \t brithday:(%d/%d/%d) \n",(i+1),array[i].name,array[i].day,array[i].month,array[i].year);


     }
     break;






/**************************************************************************************/
 case 2:
     printf("\n**** Add new member *****\n*************************\n");
     printf("how many person u will add\n");
      scanf("%i",&input);
     for(i=0;i<input;i++)
     {
         printf("Enter name:");
         scanf("%s",ptr->name);
          printf("\n");
           printf("Enter the brithday year:");
        scanf("%d",&ptr->year);
        printf("\n");
        printf("Enter the brithday month:");
        scanf("%d",&ptr->month);
        printf("\n");
        printf("Enter the brithday day:");
        scanf("%d" ,&ptr->day);
          printf("\n");
          ptr++;
     }
     printf("\nAdd Done");
     break;



/*****************************************************************************************/
  case 3:

    printf("\n**** Search *****\n*************************\n");
    printf("Enter month to search\n");
    scanf("%i",&input2);

       ptr=array;                               //to make pointer have frist struct address

     for(i=0;i<SIZE_OF_STRUCT;i++)
    {

      if(input2==(ptr[i].month))
       {
            printf("%i-Name:%s \t brithday:(%d/%d/%d) \n",(i+1),array[i].name,array[i].day,array[i].month,array[i].year);
      }
    }
     break;




/********************************************************************************************/
  case 4:
      printf("\n**** Delet *****\n*************************\n");
printf("Enter num the person u need delet:\n");
for(i=0;i<SIZE_OF_STRUCT;i++)
     {
         printf("%i-Name:%s \t brithday:(%d/%d/%d) \n",i+1,array[i].name,array[i].day,array[i].month,array[i].year);


     }
 scanf("%i",&input);


     if((input-1)>=0 && input<=SIZE_OF_STRUCT)
     {
         for(i=input-1;i<SIZE_OF_STRUCT-1;i++)
         {


         array[i]=array[i+1] ;


         }
          printf("Deleted Done");
     }
     else
         printf("Invalid choice. Please choose again.\n");

     break;
/*************************************************************************************************/
   case 5:
     break;

 default:
        printf("Invalid choice. Please choose again.\n");
        break;
}


}

    return 0;
}
