 /******************************************************************************
 *
 * Module: EEPROM
 *
 * File Name: EEPROM.h
 *
 * Description: types for ARM
 *
 * Author: Seif Emad
 *
 *******************************************************************************/

#ifndef EEPROM_H_
#define EEPROM_H_

#include "tm4c123gh6pm_registers.h"
#include "common_macros.h"
#include "std_types.h"

#define working 0

void EEPROM_init(void);

void EEPROM_WriteData(uint16 currentBlock, uint8 currentOffset,sint32 data);
sint32 EEPROM_ReadData(uint16 currentBlock, uint8 currentOffset);




#endif /* EEPROM_H_ */
