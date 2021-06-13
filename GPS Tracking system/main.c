#include "uart.h"
#include "lcd.h"
#include "Port.h"
#include "systick.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define MAX_POINTS 1000
#define x_dest_min 30.06850
#define y_dest_min 31.35490
#define x_dest_max 30.07098
#define y_dest_max 31.35572
#define pi 3.1415926535897932384
typedef struct
{
  double x;
  double y;
}point;

int number_of_points =0; // global variable increament with each point
point points[MAX_POINTS]; // array hold all the points which will recorded by GPS 
bool flag =FALSE;
bool flag_destination = FALSE;
bool flag_SW1 =FALSE;

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

void modify_points(char x_str[], char y_str[])
{
  char *ptr;
  char temp_x[20];
  char temp_y[20];
  double temp2;
  char first_2_char[3];
  ///////////////////////////// modify x /////////////////////////
  first_2_char[0]=x_str[0];
  first_2_char[1]=x_str[1];
  first_2_char[2]='\0';
  int counter =2;
  int index =0;
  while(x_str[counter]!='\0')
  {
    temp_x[index]=x_str[counter];
    counter++;
    index++;
  }
  temp_x[index] = '\0';
  temp2 = strtod(temp_x,&ptr);
  temp2 /= 60;
  temp2 = temp2 + strtod(first_2_char,&ptr);
  points[number_of_points].x = temp2;
  //////////////////////////// modify y ///////////////////////////
  first_2_char[0]=y_str[0];
  first_2_char[1]=y_str[1];
  first_2_char[2]='\0';
  counter =2 ;
  index =0;
  while(y_str[counter]!='\0')
  {
    temp_y[index]=y_str[counter];
    counter++;
    index++;
  }
  temp_y[index] = '\0';
  temp2 = strtod(temp_y,&ptr);
  temp2 /= 60;
  temp2 = temp2 + strtod(first_2_char,&ptr);
  points[number_of_points].y = temp2;
  /////////////////////////////////////////////////////////////////////////////
  if((points[number_of_points].x >= x_dest_min && points[number_of_points].x <= x_dest_max) && (points[number_of_points].y>=y_dest_min && points[number_of_points].y<=y_dest_max) )
      flag_destination =1;
  return; 
}
long double toRadians(const long double degree)
{
	// cmath library in C++
	// defines the constant
	// M_PI as the value of
	// pi accurate to 1e-30
	double one_deg = (pi) / 180;
	return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
	long double lat2, long double long2)
{
	// Convert the latitudes
	// and longitudes
	// from degree to radians.
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);

	// Haversine Formula
	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
		cos(lat1) * cos(lat2) *
		pow(sin(dlong / 2), 2);

	ans = 2 * asin(sqrt(ans));

	// Radius of Earth in
	// Kilometers, R = 6371
	// Use R = 3956 for miles
	long double R = 6371;

	// Calculate the result
	ans = ans * R;

	return ans * 1000;
}


void readGPSModule(void)
{
	char x_str[20];
	char y_str[20];
	char y_str_modified[20];
	char c0;
	int i_x = 0;
	int i_y = 0;
	while (1)
	{
		c0 = (char)UART5_ReceiveByte();
		//gelen data $GPRMC mi?
		if (c0 == '$')
		{
			char c1 = (char)UART5_ReceiveByte();
			if (c1 == 'G')
			{
				char c2 = (char)UART5_ReceiveByte();
				if (c2 == 'P')
				{
					char c3 = (char)UART5_ReceiveByte();
					if (c3 == 'R')
					{
						char c4 = (char)UART5_ReceiveByte();
						if (c4 == 'M')
						{
							char c5 = (char)UART5_ReceiveByte();
							if (c5 == 'C')
							{
								char c6 = (char)UART5_ReceiveByte();
								if (c6 == ',')
								{
									while (1)
									{
										char temp = (char)UART5_ReceiveByte();
										if (temp == 'A')
											break;
									}
									char temp = (char)UART5_ReceiveByte();

									if (temp == ',') // store the latitude in x_str
									{
										while (1)
										{
											char c7 = UART5_ReceiveByte();
											if (c7 == ',')
												break;
											x_str[i_x] = c7;
											i_x++;
											x_str[i_x] = '\0';
										}
									}
									char c8 = (char)UART5_ReceiveByte();
									if (c8 == 'N')
									{
										char c9 = (char)UART5_ReceiveByte();
										if (c9 == ',')
										{
											while (1) // store the longitude
											{
												char c10 = (char)UART5_ReceiveByte();
												if (c10 == ',')
													break;
												y_str[i_y] = c10;
												i_y++;
												y_str[i_y] = '\0';
											}
											// the next block to cut the first zeroes from longitude 
											/////////////////////////////////////////////////////////////////////
											int counter = 0;
											while (y_str[counter] == '0')
												counter++; // output here is number of zeroes in longitude
											int index = 0;
											while (y_str[counter] != '\0')
											{
												y_str_modified[index] = y_str[counter];
												counter++;
												index++;
											}
											y_str_modified[index] = '\0';
											//////////////////////////////////////////////////////////////////                                         
											modify_points(x_str, y_str_modified);
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

void GPIOPORTF_Handler(void)
{
  GPIO_PORTF_ICR_REG   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
  flag_SW1 = TRUE;
  SET_BIT(GPIO_PORTF_DATA_REG,2);  // bright the led
}
void main()
{ 
  int i=0;
  double global_distance = 0.0;
  lcd_and_led_init();
  LCD_init(); 
  SW1_Init();
  UART0_init();
  UART5_init();
  sysTick_init();
  Enable_Interrupts();
  while(1)
  {  
      for(int j=0;j<1;j++)
      {
       while(!(SYSTICK_CTRL_REG & (1<<16)));  
      }
      readGPSModule();
      LCD_clearScreen();
      number_of_points++; 
      if(number_of_points>=2)
      {
         global_distance += distance(points[i].x,points[i].y,points[i+1].x,points[i+1].y);
         i++;
         char dist [20];
         snprintf(dist,15,"%f",global_distance); // display the global distance continously
         LCD_displayString(dist);
         _delay_ms(4000);
         LCD_clearScreen();
      }
      if(global_distance>=100 || flag_SW1 == TRUE || flag_destination ==1)
      {
          SET_BIT(GPIO_PORTF_DATA_REG,2);  // bright the led
          char dist [20];
          snprintf(dist,10,"%f",global_distance); // display the global distace when ome from  thre condition occur
          LCD_displayString(dist);
          while(1)
          {
            ;
          }
      }     
   }  
}