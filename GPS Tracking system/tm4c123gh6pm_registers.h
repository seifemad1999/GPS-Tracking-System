#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile unsigned long *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile unsigned long *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile unsigned long *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile unsigned long *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile unsigned long *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile unsigned long *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile unsigned long *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile unsigned long *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile unsigned long *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile unsigned long *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile unsigned long *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile unsigned long *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile unsigned long *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile unsigned long *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile unsigned long *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile unsigned long *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile unsigned long *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile unsigned long *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile unsigned long *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile unsigned long *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile unsigned long *)0x4002541C))

#define SYSCTL_REGCGC2_REG        (*((volatile unsigned long *)0x400FE108))


/*****************************************************************************
Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile unsigned long *)0xE000E018))

/*****************************************************************************
PLL Registers
*****************************************************************************/
#define SYSCTL_RIS_REG            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RCC_REG            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_REG           (*((volatile unsigned long *)0x400FE070))

/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define NVIC_PRI0_REG             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile unsigned long *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))

//*****************************************************************************
//
// UART registers (UART0)
//
//*****************************************************************************
#define UART0_DR_REG              (*((volatile uint32_t *)0x4000C000))
#define UART0_RSR_REG             (*((volatile uint32_t *)0x4000C004))
#define UART0_ECR_REG             (*((volatile uint32_t *)0x4000C004))
#define UART0_FR_REG              (*((volatile uint32_t *)0x4000C018))
#define UART0_ILPR_REG            (*((volatile uint32_t *)0x4000C020))
#define UART0_IBRD_REG            (*((volatile uint32_t *)0x4000C024))
#define UART0_FBRD_REG            (*((volatile uint32_t *)0x4000C028))
#define UART0_LCRH_REG            (*((volatile uint32_t *)0x4000C02C))
#define UART0_CTL_REG             (*((volatile uint32_t *)0x4000C030))
#define UART0_IFLS_REG            (*((volatile uint32_t *)0x4000C034))
#define UART0_IM_REG              (*((volatile uint32_t *)0x4000C038))
#define UART0_RIS_REG             (*((volatile uint32_t *)0x4000C03C))
#define UART0_MIS_REG             (*((volatile uint32_t *)0x4000C040))
#define UART0_ICR_REG             (*((volatile uint32_t *)0x4000C044))
#define UART0_DMACTL_REG          (*((volatile uint32_t *)0x4000C048))
#define UART0_9BITADDR_REG        (*((volatile uint32_t *)0x4000C0A4))
#define UART0_9BITAMASK_REG       (*((volatile uint32_t *)0x4000C0A8))
#define UART0_PP_REG              (*((volatile uint32_t *)0x4000CFC0))
#define UART0_CC_REG              (*((volatile uint32_t *)0x4000CFC8))

//*****************************************************************************
//
// UART registers (UART1)
//
//*****************************************************************************
#define UART1_DR_REG              (*((volatile uint32_t *)0x4000D000))
#define UART1_RSR_REG             (*((volatile uint32_t *)0x4000D004))
#define UART1_ECR_REG             (*((volatile uint32_t *)0x4000D004))
#define UART1_FR_REG              (*((volatile uint32_t *)0x4000D018))
#define UART1_ILPR_REG            (*((volatile uint32_t *)0x4000D020))
#define UART1_IBRD_REG            (*((volatile uint32_t *)0x4000D024))
#define UART1_FBRD_REG            (*((volatile uint32_t *)0x4000D028))
#define UART1_LCRH_REG            (*((volatile uint32_t *)0x4000D02C))
#define UART1_CTL_REG             (*((volatile uint32_t *)0x4000D030))
#define UART1_IFLS_REG            (*((volatile uint32_t *)0x4000D034))
#define UART1_IM_REG              (*((volatile uint32_t *)0x4000D038))
#define UART1_RIS_REG             (*((volatile uint32_t *)0x4000D03C))
#define UART1_MIS_REG             (*((volatile uint32_t *)0x4000D040))
#define UART1_ICR_REG             (*((volatile uint32_t *)0x4000D044))
#define UART1_DMACTL_REG          (*((volatile uint32_t *)0x4000D048))
#define UART1_9BITADDR_REG        (*((volatile uint32_t *)0x4000D0A4))
#define UART1_9BITAMASK_REG       (*((volatile uint32_t *)0x4000D0A8))
#define UART1_PP_REG              (*((volatile uint32_t *)0x4000DFC0))
#define UART1_CC_REG              (*((volatile uint32_t *)0x4000DFC8))

//*****************************************************************************
//
// UART registers (UART2)
//
//*****************************************************************************
#define UART2_DR_REG              (*((volatile uint32_t *)0x4000E000))
#define UART2_RSR_REG             (*((volatile uint32_t *)0x4000E004))
#define UART2_ECR_REG             (*((volatile uint32_t *)0x4000E004))
#define UART2_FR_REG              (*((volatile uint32_t *)0x4000E018))
#define UART2_ILPR_REG            (*((volatile uint32_t *)0x4000E020))
#define UART2_IBRD_REG            (*((volatile uint32_t *)0x4000E024))
#define UART2_FBRD_REG            (*((volatile uint32_t *)0x4000E028))
#define UART2_LCRH_REG            (*((volatile uint32_t *)0x4000E02C))
#define UART2_CTL_REG             (*((volatile uint32_t *)0x4000E030))
#define UART2_IFLS_REG            (*((volatile uint32_t *)0x4000E034))
#define UART2_IM_REG              (*((volatile uint32_t *)0x4000E038))
#define UART2_RIS_REG             (*((volatile uint32_t *)0x4000E03C))
#define UART2_MIS_REG             (*((volatile uint32_t *)0x4000E040))
#define UART2_ICR_REG             (*((volatile uint32_t *)0x4000E044))
#define UART2_DMACTL_REG          (*((volatile uint32_t *)0x4000E048))
#define UART2_9BITADDR_REG        (*((volatile uint32_t *)0x4000E0A4))
#define UART2_9BITAMASK_REG       (*((volatile uint32_t *)0x4000E0A8))
#define UART2_PP_REG              (*((volatile uint32_t *)0x4000EFC0))
#define UART2_CC_REG              (*((volatile uint32_t *)0x4000EFC8))

//*****************************************************************************
//
// UART registers (UART5)
//
//*****************************************************************************
#define UART5_DR_REG              (*((volatile uint32_t *)0x40011000))
#define UART5_RSR_REG             (*((volatile uint32_t *)0x40011004))
#define UART5_ECR_REG             (*((volatile uint32_t *)0x40011004))
#define UART5_FR_REG              (*((volatile uint32_t *)0x40011018))
#define UART5_ILPR_REG            (*((volatile uint32_t *)0x40011020))
#define UART5_IBRD_REG            (*((volatile uint32_t *)0x40011024))
#define UART5_FBRD_REG            (*((volatile uint32_t *)0x40011028))
#define UART5_LCRH_REG            (*((volatile uint32_t *)0x4001102C))
#define UART5_CTL_REG             (*((volatile uint32_t *)0x40011030))
#define UART5_IFLS_REG            (*((volatile uint32_t *)0x40011034))
#define UART5_IM_REG              (*((volatile uint32_t *)0x40011038))
#define UART5_RIS_REG             (*((volatile uint32_t *)0x4001103C))
#define UART5_MIS_REG             (*((volatile uint32_t *)0x40011040))
#define UART5_ICR_REG             (*((volatile uint32_t *)0x40011044))
#define UART5_DMACTL_REG          (*((volatile uint32_t *)0x40011048))
#define UART5_9BITADDR_REG        (*((volatile uint32_t *)0x400110A4))
#define UART5_9BITAMASK_REG       (*((volatile uint32_t *)0x400110A8))
#define UART5_PP_REG              (*((volatile uint32_t *)0x40011FC0))
#define UART5_CC_REG              (*((volatile uint32_t *)0x40011FC8))

/************************************************************************/
#define SYSCTL_RCGCUART_REG       (*((volatile uint32_t *)0x400FE618))


// EEPROM registers (EEPROM)
//
//*****************************************************************************
#define EEPROM_EESIZE_REG         (*((volatile uint32_t *)0x400AF000))
#define EEPROM_EEBLOCK_REG        (*((volatile uint32_t *)0x400AF004))
#define EEPROM_EEOFFSET_REG       (*((volatile uint32_t *)0x400AF008))
#define EEPROM_EERDWR_REG         (*((volatile uint32_t *)0x400AF010))
#define EEPROM_EERDWRINC_REG      (*((volatile uint32_t *)0x400AF014))
#define EEPROM_EEDONE_REG         (*((volatile uint32_t *)0x400AF018))
#define EEPROM_EESUPP_REG         (*((volatile uint32_t *)0x400AF01C))
#define EEPROM_EEUNLOCK_REG       (*((volatile uint32_t *)0x400AF020))
#define EEPROM_EEPROT_REG         (*((volatile uint32_t *)0x400AF030))
#define EEPROM_EEPASS0_REG        (*((volatile uint32_t *)0x400AF034))
#define EEPROM_EEPASS1_REG        (*((volatile uint32_t *)0x400AF038))
#define EEPROM_EEPASS2_REG        (*((volatile uint32_t *)0x400AF03C))
#define EEPROM_EEINT_REG          (*((volatile uint32_t *)0x400AF040))
#define EEPROM_EEHIDE_REG         (*((volatile uint32_t *)0x400AF050))
#define EEPROM_EEDBGME_REG        (*((volatile uint32_t *)0x400AF080))
#define EEPROM_PP_REG             (*((volatile uint32_t *)0x400AFFC0))

#define SYSCTL_RCGCEEPROM_REG     (*((volatile uint32_t *)0x400FE658))
#define SREEPROM                  (*((volatile uint32_t *)0x400FE558))

#endif
