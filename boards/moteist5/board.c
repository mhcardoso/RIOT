/*
 * board.c - Board initialization for the Zolertia Z1
 * Copyright (C) 2014 INRIA
 *
 * Author : Kévin Roussel <Kevin.Roussel@inria.fr>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_z1
 * @{
 *
 * @file
 * @brief       Board specific implementations for the Zolertia Z1
 *
 * @author      Kévin Roussel <Kevin.Roussel@inria.fr>
 *
 * @}
 */


#include "cpu.h"
#include "board.h"

static void moteist5_ports_init(void)
{
    /* Port 1:
     *  P1.0 is not assigned by default
     *  P1.1 is the bootstrap-loader (BSL) TX pin -> input, special function, default to GND
     *       THIS PIN MUST *NEVER* BE USED IN NORMAL EXECUTION, SINCE IT INTERFERES WITH UART0 !!!
     *  P1.2 receives the FIFOP interrupt from CC2420 -> input, GPIO, default to GND
     *  P1.3 receives the FIFO/GIO0 interrupt from CC2420 -> input, GPIO, default to GND
     *  P1.4 receives the CCA/GIO1 signal from CC2420 -> input, GPIO, default to GND
     *  P1.5 is wired to Vcc -> input, GPIO, default to Vcc
     *  P1.6 receives interrupt INT1 from accelerometer -> input, GPIO, default to GND
     *  P1.7 receives interrupt INT2 from accelerometer -> input, GPIO, default to GND
     */
    P1SEL = 0x00;    /* Port1 Select: 00000010 = 0x02 */
    P1OUT = 0x39/*0x00*/;    /* Port1 Output: 00100000 = 0x20 */
    P1DIR = 0x39/*0x00*/;    /* Port1 Direction: 00000000 = 0x00 */
    P1REN = 0xC6;

    /* Port 2:
     *  P2.0 is not assigned by default
     *  P2.1 is not assigned by default
     *  P2.2 is the bootstrap-loader (BSL) RX pin -> input, special function, default to GND
     *       THIS PIN MUST *NEVER* BE USED IN NORMAL EXECUTION, SINCE IT INTERFERES WITH UART0 !!!
     *  P2.3 is not assigned by default
     *  P2.4 is used as an active-low output to the BSL and USB interface -> output, GPIO, default to Vcc
     *  P2.5 is connected to the active-low "user interrupt" button -> input, GPIO, default to Vcc
     *  P2.6 is not assigned by default
     *  P2.7 receives the ALERT interrupt from TMP102 -> input, GPIO, default to Vcc
     */
    P2SEL = 0x4E;    /* Port2 Select: 00000100 = 0x04 */
    P2OUT = 0x00;    /* Port2 Output: 10110000 = 0xB0 */
    P2DIR = 0x4C;    /* Port2 Direction: 11010000 = 0xD0 */

    /* Port 3:
     *  P3.0 is the radio (CC2420) active-low chip select -> output, GPIO, default to Vcc
     *  P3.1 is SPI's MOSI pin -> output, special function, default to GND
     *  P3.2 is SPI's MISO pin -> input, special function, default to GND
     *  P3.3 is SPI's CLK pin -> output, special function, default to GND
     *  P3.4 is USCI0 UART TX pin -> output, special function, default to Vcc
     *  P3.5 is USCI0 UART RX pin -> input, special function, default to Vcc
     *  P3.6 is USCI1 UART TX pin -> output, special function, default to GND
     *  P3.7 is USCI1 UART RX pin -> input, special function, default to GND
     * NOTES :
     *  - Z1 only uses the USCI0 SPI channel
     *  - UART0 is connected to the micro-USB port (via the CP2102 chip)
     */
    P3SEL = 0xB0;    /* Port3 Select: 11111110 = 0xFE */
    P3OUT = 0x00;    /* Port3 Output: 00110001 = 0x31 */
    P3DIR = 0x10;    /* Port3 Direction: 01011011 = 0x5B */

    /* Port 4:
     *  P4.0 is not assigned by default (but controls a LED in Z1 "starter pack") -> output, GPIO, default to Vcc
     *  P4.1 receives the SFD interrupt from CC2420, that can be captured by TimerB -> input, special function, default to GND
     *  P4.2 is not assigned by default (but controls a LED in Z1 "starter pack") -> output, GPIO, default to Vcc
     *  P4.3 is not assigned by default (but controls a buzzer in Z1 "starter pack") -> output, GPIO, default to GND
     *  P4.4 is the Flash chip (M25P16) active-low chip select -> output, GPIO, default to Vcc
     *  P4.5 is the radio (CC2420) active-high VREG enable line -> output, GPIO, default to GND
     *  P4.6 is the radio (CC2420) active-low RESET line -> output, GPIO, default to Vcc
     *  P4.7 is not assigned by default (but controls a LED in Z1 "starter pack") -> output, GPIO, default to Vcc
     */
    P4SEL = 0x00;    /* Port4 Select: 00000010 = 0x02 */
    P4OUT = 0xE4;    /* Port4 Output: 11010101 = 0xD5 */
    P4DIR = 0xE0;    /* Port4 Direction: 11111101 = 0xFD */

    /* Port 5:
     *  I2C, and GPIO (LEDs, flash)
     *  P5.0 controls TMP102 power (active high) -> output, GPIO, default to GND
     *  P5.1 is I2C's SDA (data) pin -> input (by default/changeable), special function, default to GND
     *  P5.2 is I2C's SCL (clock) pin -> output, special function, default to GND
     *  P5.3 is not assigned by default
     *  P5.4 controls one of Z1's LEDs (active low) -> output, GPIO, default to Vcc
     *  P5.5 controls one of Z1's LEDs (active low) -> output, GPIO, default to Vcc
     *  P5.6 controls one of Z1's LEDs (active low) -> output, GPIO, default to Vcc
     *  P5.7 is the Flash chip (M25P16) active-low HOLD line -> output, GPIO, default to Vcc
     * NOTES :
     *  - Z1 only uses the USCI1 I2C channel
     *  - P5.3 controls the +5V aux. power regulator in Z1 "starter pack"
     */
    P5SEL = 0x1C/*0x10*/;    /* Port5 Select: 00000110 = 0x06 */
    P5OUT = 0x08;    /* Port5 Output: 11110000 = 0xF0 */
    P5DIR = 0x00;    /* Port5 Direction: 11110101 = 0xF5 */

    /* Port 6:
     *  All of the 8 lines are ADC inputs, none of them is assigned by default
     *   (but P6.4/AD4 is connected to a wheel potentiometer in Z1 "starter pack")
     *   -> put all lines to input, special function, default to GND
     */
    P6SEL = 0x00;    /* Port6 Select: 11111111 = 0xFF */
    P6OUT = 0x00;    /* Port6 Output: 00000000 = 0x00 */
    P6DIR = 0x00;    /* Port6 Direction: 00000000 = 0xFF */

    P7SEL = 0x03;
    P7OUT = 0x00;
    P7DIR = 0x00;

    P8SEL = 0x00;
    P8OUT = 0x00;
    P8DIR = 0x00;

    P9SEL = 0x00;
    P9OUT = 0xC0;
    P9DIR = 0xCC;

    P10SEL = 0x0E; /* 00001110*/
    P10OUT = 0xF1/*0x01*/; /* 00000001*/
    P10DIR = 0xFB/*0x0D*/; /* 00001101*/

    P11SEL = 0x00;
    P11OUT = 0x00;
    P11DIR = 0x00;

}

/*---------------------------------------------------------------------------*/
/* taken from Contiki code */
void msp430_init_dco(void)
{
   int multiplier, i;
   
   multiplier = F_CPU/32678U - 1; 
   /*maybe*/__bis_SR_register(SCG0);
   UCSCTL0 = 0x0000;
   UCSCTL1 = DCORSEL_5;
   UCSCTL2 = FLLD_1 + multiplier;
   /*maybe*/__bic_SR_register(SCG0);
   
   
  /*maybe*/UCSCTL6 &= ~(XT1OFF + XT2OFF);            // Set XT1 & XT2 On
  /*maybe*/UCSCTL6 |= XCAP_3;                        // Internal load cap

   do{
       UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);

       SFRIFG1 &= ~OFIFG;
       for(i = 1000; i > 0; i--) {
	 __nop();
       }
   }while(SFRIFG1 & OFIFG);
   
   UCSCTL6 &= ~XT2DRIVE0;
   
   UCSCTL3 |= SELREF_0;
   UCSCTL4 |= SELA_0 + SELS_4;
}

void activate_switches(void){
	P3SEL |= 0x80;                            // P3.7 - SDA - Assign I2C pins
	P5SEL |= 0x10;							  // P5.4 - SCL
                             
	UCB1CTL1 |= UCSWRST;                      // Enable SW reset
  
	UCB1CTL0 = UCMST + UCMODE_3 + UCSYNC;     // I2C Master, synchronous mode
	UCB1CTL1 = UCSSEL_2 + UCSWRST;            // Use SMCLK
	UCB1BR0 = 12;                             // fSCL = SMCLK/12 = ~100kHz
  	UCB1BR1 = 0;
  	UCB1I2CSA = 0x48;                         // Slave Address is 090h 1001 0000 -> address (7bit, A0=A1=0) + R/!W
  
  	UCB1CTL1 &= ~UCSWRST;                     // Clear SW reset*/

	while (UCB1CTL1 & UCTXSTP);               // Ensure stop condition got sent
    UCB1CTL1 |= UCTR + UCTXSTT;               // I2C start condition
  	UCB1TXBUF = 0xFF;  	                      // Send init data
  	while(UCB1CTL1 & UCTXSTT);                // Start condition sent?
  	UCB1CTL1 |= UCTXSTP;				      // I2C1 Stop Condition
}

/* "public" specific initialization function for the Zolertia Z1 hardware */

void board_init(void)
{
    /* init CPU core */
    /* msp430_cpu_init(); */

    /* disable watchdog timer */
    WDTCTL     =  WDTPW + WDTHOLD;

    /* init MCU pins as adequate for Z1 hardware */
    moteist5_ports_init();

    /* initializes DCO */
    msp430_init_dco();

    /* moteist5 specific code, activates the connectors */
    activate_switches();

    /* enable interrupts */
    __bis_SR_register(GIE);
}
