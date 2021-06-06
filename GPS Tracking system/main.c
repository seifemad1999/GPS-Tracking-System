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


double degtorad(double deg) {
	return (deg * pi / 180);
}


double radtodeg(double rad) {
	return (rad * 180 / pi);
}

float distance(float lat1, float lon1, float lat2, float lon2, char unit) {
	double theta, dist;
	if ((lat1 == lat2) && (lon1 == lon2)) {
		return 0;
	}
	else {
		theta = lon1 - lon2;
		dist = sin(degtorad(lat1)) * sin(degtorad(lat2)) + cos(degtorad(lat1)) * cos(degtorad(lat2)) * cos(degtorad(theta));
		dist = acos(dist);
		dist = radtodeg(dist);
		dist = dist * 60 * 1.1515;
		switch (unit) {
		case 'M':
			break;
		case 'K':
			dist = dist * 1.609344;
			break;
		case 'N':
			dist = dist * 0.8684;
		case 'm':
			dist = (dist * 1.609344) / 1000;
			break;
		}
		return (dist);
	}
}


void readGPSModule(void)
{
	char x_str[15];
	char y_str[15];
	char c0;//GPSValues[100],parseValue[12][20],*token;
			//double latitude=0.0,longitude=0.0,seconds=0.0,minutes=0.0;
			//const char comma[2] = ",";
			//  int index=0,degrees;
	int i_x = 0;
	int i_y = 0;
	while (1)
	{
		c0 = (char)UART5_ReceiveByte();
		LCD_displayCharacter(c0);
		//gelen data $GPRMC mi?
		if (c0 == '$')
		{
			char c1 = (char)UART5_ReceiveByte();
			LCD_displayCharacter(c1);
			if (c1 == 'G')
			{
				char c2 = (char)UART5_ReceiveByte();
				LCD_displayCharacter(c2);
				if (c2 == 'P')
				{
					char c3 = (char)UART5_ReceiveByte();
					LCD_displayCharacter(c3);
					if (c3 == 'R')
					{
						char c4 = (char)UART5_ReceiveByte();
						LCD_displayCharacter(c4);
						if (c4 == 'M')
						{
							char c5 = (char)UART5_ReceiveByte();
							LCD_displayCharacter(c5);
							if (c5 == 'C')
							{
								char c6 = (char)UART5_ReceiveByte();
								LCD_displayCharacter(c6);
								if (c6 == ',')
								{
									// char c7=(char)UART5_ReceiveByte();
									//  LCD_displayCharacter(c7);
									//reading
									LCD_clearScreen();
									while (1)
									{
										char temp = (char)UART5_ReceiveByte();
										LCD_displayCharacter(temp);
										if (temp == 'A')
											break;
										// x_str[i] = UART5_ReceiveByte();
										//i++;
									}
									char temp = (char)UART5_ReceiveByte();
									LCD_displayCharacter(temp);
									if (temp == ',') // store the latitude in x_str
									{
										LCD_clearScreen();

										while (1)
										{
											char c7 = UART5_ReceiveByte();
											if (c7 == ',')
												break;
											x_str[i_x] = c7;
											i_x++;
										}
									}
									char c8 = (char)UART5_ReceiveByte();
									LCD_displayCharacter(c8);

									if (c8 == 'N')
									{
										char c9 = (char)UART5_ReceiveByte();
										LCD_displayCharacter(c9);
										if (c9 == ',')
										{

											LCD_clearScreen();
											while (1) // store the longitude
											{
												char c10 = (char)UART5_ReceiveByte();
												LCD_displayCharacter(c10);
												if (c10 == ',')
													break;
												y_str[i_y] = c10;
												i_y++;
											}
											LCD_clearScreen();
											LCD_displayString(x_str);
											LCD_clearScreen();
											LCD_displayString(y_str);
											//_delay_ms(1000);
											points[number_of_points].x = atof(x_str);
											points[number_of_points].y = atof(y_str);
											if ((points[number_of_points].x >= x_dest_min && points[number_of_points].x <= x_dest_max) && (points[number_of_points].y >= y_dest_min && points[number_of_points].y <= y_dest_max))
												flag_destination = 1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

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