#include "EEPROM.h"

void EEPROM_init(void)
{
  
  SYSCTL_RCGCEEPROM_REG |= (1<<0);    // Enable Clock for EEPROM
  for(int i = 0; i < 6 ; i++)
  {
    // For delay 
  }
  
  while(BIT_IS_SET(EEPROM_EEDONE_REG , working)) {};
  while(BIT_IS_SET(EEPROM_EESUPP_REG , 3) || BIT_IS_SET(EEPROM_EESUPP_REG , 2)) {};  //RETRY
  
  SREEPROM &= ~(1<<0);            //Reset the EEPROM module using REEPROM register
  for(uint8 i = 0;i<6;i=i+1);   //delay for 6 clock cycles
  
  while(BIT_IS_SET(EEPROM_EEDONE_REG , working)) {};
  while(BIT_IS_SET(EEPROM_EESUPP_REG , 3) || BIT_IS_SET(EEPROM_EESUPP_REG , 2)) {};
  EEPROM_EEPROT_REG &= ~(1<<3);       
}
