/*
 ============================================================================
 Author      : Mohamed Sarhan EL-hussieny
 Description : Vehicle Control System Project
 Date        : 04/08/2024
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum state
{
    OFF,ON
};

/**************************************Global_Variable*******************************/
unsigned char Engine_state=OFF;
unsigned char vehicle_speed =0;
unsigned char AC_state=OFF;
int  Temperature_room_value=35;
int  Temperature_engine_value=90;
unsigned char Engine_Temperature_Controller=OFF;



/*****************************current_vehicle_state_fun******************************/
 void current_vehicle_state(void)
 {

    if(30==vehicle_speed)
   {
       AC_state=ON;
      Temperature_room_value=(Temperature_room_value*5/4)+1;

      if(Engine_Temperature_Controller=OFF)
     {
         Engine_Temperature_Controller=ON;
     }
      Temperature_engine_value=(Temperature_engine_value*5/4)+1;

   }


Display_states();
 }


/*****************************engine_temperature_fun******************************/
void engine_temperature(void)
{
    char input ;

    printf(" engine temperature require:");
    scanf("%i",&input);

    Temperature_engine_value=input;

 if(Temperature_engine_value<100)
   {
       Engine_Temperature_Controller=ON;
       Temperature_engine_value=125;
   }

   else if(Temperature_engine_value>150)
    {
       Engine_Temperature_Controller=ON;
       Temperature_engine_value=125;
     }
    else if(100<Temperature_engine_value &&Temperature_engine_value<150)
    {
       Engine_Temperature_Controller=OFF;

     }

}

/***********************************room_temperature_fun******************************/
 void room_temperature(void)
{

      char input ;
    printf("room temperature require:");
    scanf("%i",&input);
    Temperature_room_value=input;
  if(Temperature_room_value<10)
   {
       AC_state=ON;
       Temperature_room_value=20;


   }

   else if(Temperature_room_value>30)
    {
       AC_state=ON;
       Temperature_room_value=20;


     }

    else if(10<Temperature_room_value &&Temperature_room_value<30)
    {
       AC_state=OFF;

   }
}


/***********************************traffic_light_data_fun******************************/
 void traffic_light_data(void)
 {
     char choose;
     printf("you have choice => ('G' , 'O' ,'R')\n ");

scanf("%s",&choose);
switch(choose)
{
case 'g':
case'G':
    vehicle_speed =100;
    break;

case 'o':
case'O':
    vehicle_speed =30;
    break;

case 'r':
case'R':
    vehicle_speed =0;
   break;

}

 }


/***************************************Sensors_set_menu_fun****************************/
void Sensors_set_menu(void)
{
char choose;

for(;;)
{
printf(" \
 a. Turn off the engine\n \
 b. Set the traffic light color.\n  \
c. Set the room temperature (Temperature Sensor).\n  \
d. Set the engine temperature (Engine Temperature Sensor).\n");

scanf("%s",&choose);

switch(choose)
{
case 'a':
case'A':
 main();
    break;

case 'b':
case 'B':
    traffic_light_data();
        break;

case 'c' :
case 'C':

    room_temperature();
break;

case 'd' :
case 'D':
    engine_temperature();

break;

default:
    printf("Please,choose from options :)\n\n ");
    break;
}
current_vehicle_state();
}
   }

/***************************************main_fun****************************/
int main()
{
    char choose;
    for(;;)
    {
    printf("\n Hello! \n\n");
    printf("welcome to Vehicle Control System \n\n");

    printf(" a.Turn on the vehicle engine\n \
b. Turn off the vehicle engine\n \
c. Quit the system\n \n");

scanf("%s",&choose);
switch(choose)
{
case 'a':
case'A':
    Engine_state=ON;
   Sensors_set_menu();
    break;

case 'b':
case 'B':
     printf("Turn off the vehicle engine\n ");
        break;

case 'c' :
case 'C':
 printf("Quit the system\n ");
    return 0;

break;

default:
     printf("Please,choose from options :) ");
    break;
}
    }
    return 0;
}



/*****************************Display_states_fun******************************/
void Display_states(void)
 {

     printf("Engine state:");
     Engine_state!=0 ? printf("ON"):printf("OFF");
    printf("\n");

     printf("AC:");
     AC_state!=0 ? printf("ON"):printf("OFF");
     printf("\n");

     printf("Vehicle Speed: %i Km/Hr",vehicle_speed);
     printf("\n");

     printf("Room Temperature: %i C",Temperature_room_value);
     printf("\n");

     printf("Engine Temperature Controller State ");
    Engine_Temperature_Controller!=0 ? printf("ON"):printf("OFF");
     printf("\n");

     printf("Engine Temperature: %i C",Temperature_engine_value);
     printf("\n");
     printf("\n");

 }
