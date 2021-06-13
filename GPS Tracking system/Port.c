#include "Port.h"
#include "tm4c123gh6pm_registers.h"
void lcd_and_led_init(void)
{
	volatile unsigned long delay = 0;
	SYSCTL_REGCGC2_REG |= 0x0000003F;
	delay = SYSCTL_REGCGC2_REG;
	//config of lcd bins
	GPIO_PORTB_DIR_REG |= 0x000000FF;
	GPIO_PORTB_DEN_REG |= 0x000000FF;
	GPIO_PORTB_AFSEL_REG &= ~(0x000000FF);
	GPIO_PORTB_AMSEL_REG &= ~(0x000000FF);
	GPIO_PORTB_PCTL_REG = 0x00000000;


	GPIO_PORTE_DIR_REG |= 0x00000007;
	GPIO_PORTE_AFSEL_REG &= ~(0x00000007);
	GPIO_PORTE_DEN_REG |= 0x00000007;
	GPIO_PORTE_AMSEL_REG &= ~(0x00000007);
	GPIO_PORTE_PCTL_REG = 0x00000000;


	//configurtion of blue lead pf2
	GPIO_PORTF_AMSEL_REG &= ~(1 << 2);
	GPIO_PORTF_PCTL_REG &= 0xFFFFF0FF;
	GPIO_PORTF_DIR_REG |= (1 << 2);
	GPIO_PORTF_AFSEL_REG &= ~(1 << 2);
	GPIO_PORTF_DEN_REG |= (1 << 2);
	GPIO_PORTF_DATA_REG &= ~(1 << 2);


	// PA5
	GPIO_PORTA_AMSEL_REG &= ~(1 << 5);
	GPIO_PORTA_PCTL_REG &= 0xFF0FFFFF;
	GPIO_PORTA_DIR_REG |= (1 << 5);
	GPIO_PORTA_AFSEL_REG &= ~(1 << 5);
	GPIO_PORTA_DEN_REG |= (1 << 5);
	GPIO_PORTA_DATA_REG |= (1 << 5);



}
void SW1_Init(void)
{
	GPIO_PORTF_AMSEL_REG &= ~(1 << 4);      /* Disable Analog on PF4 */
	GPIO_PORTF_PCTL_REG &= 0xFFF0FFFF;   /* Clear PMCx bits for PF4 to use it as GPIO pin */
	GPIO_PORTF_DIR_REG &= ~(1 << 4);      /* Configure PF4 as input pin */
	GPIO_PORTF_AFSEL_REG &= ~(1 << 4);      /* Disable alternative function on PF4 */
	GPIO_PORTF_PUR_REG |= (1 << 4);       /* Enable pull-up on PF4 */
	GPIO_PORTF_DEN_REG |= (1 << 4);       /* Enable Digital I/O on PF4 */
	GPIO_PORTF_IS_REG &= ~0x10;
	GPIO_PORTF_IBE_REG &= ~0x10;
	GPIO_PORTF_IEV_REG &= ~0x10;
	GPIO_PORTF_ICR_REG = 0x10;
	GPIO_PORTF_IM_REG |= 0x10;
	NVIC_PRI7_REG = (NVIC_PRI7_REG & 0xFF00FFFF) | 0xA00000;
	NVIC_EN0_REG = 0x40000000;
}
    
    
    