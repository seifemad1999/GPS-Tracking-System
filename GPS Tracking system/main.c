#include "uart.h"
#include "lcd.h"
#include "Port.h"
#include "systick.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define MAX_POINTS 1000
#define x_dest_min 20
#define y_dest_min 20
#define x_dest_max 21 
#define y_dest_max 21
#define pi 3.1415926535897932384
int number_of_points =0; // global variable increament with each point
typedef struct
{
  float x;
  float y;
}point;

point points[MAX_POINTS]; // array hold all the points which will recorded by GPS 

float global_distance=0.0;
bool flag =0;
bool flag_destination = 0;
point min_destination = {x_dest_min,y_dest_min};
point max_destination = {x_dest_max,y_dest_max};


/* SysTick Timer ISR ... No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
void sysTick_Handler(void)
{
    //flag = 1;
  GPIO_PORTF_AMSEL_REG &= ~(1<<3);      
    GPIO_PORTF_PCTL_REG  &= 0xFFFF0FFF;   
    GPIO_PORTF_DIR_REG   |= (1<<3);       
    GPIO_PORTF_AFSEL_REG &= ~(1<<3);     
    GPIO_PORTF_DEN_REG   |= (1<<3);       
    GPIO_PORTF_DATA_REG  |= (1<<3);      

}

//void LCD_floatToString(float data)
//{
   //char buff[16]; /* String to hold the ascii result 
   //ftoa(data, buff, 3); /* 10 for decimal 
   //LCD_displayString(buff);
//}

void main()
{ 
  int i=0;
  //while(!(SYSTICK_CTRL_REG & (1<<16)));
  //SW1_Init();
  //UART0_init ();
  
  lcd_and_led_init();
  LCD_init();
  UART5_init();
  sysTick_init();
  //Enable_Exceptions();
  //Enable_Interrupts();
  while(1)
  {
     // char s;
     //s = UART5_ReceiveByte();
     //LCD_displayCharacter(s);
      //while(!(SYSTICK_CTRL_REG & (1<<16)));      
      //str_to_points();
      readGPSModule();
      number_of_points++;
      if(number_of_points>=2)
      {
       global_distance += distance(points[i].x,points[i].y,points[i+1].x,points[i+1].y,'m');
       i++;
      }
       if(global_distance>=100 || BIT_IS_CLEAR(GPIO_PORTF_DATA_REG,4) || flag_destination ==1)
      {
      //Disable_Interrupts(); // stop recieving points from GPS
      SET_BIT(GPIO_PORTF_DATA_REG,2);  // bright the led
      LCD_clearScreen();
      void LCD_floatToString(float data) ;// display on lcd
      }     
   }  
}