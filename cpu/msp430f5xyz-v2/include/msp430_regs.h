/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_msp430fxyz
 * @{
 *
 * @file
 * @brief       Cortex CMSIS style definition of MSP430 registers
 *
 * @todo        This file is incomplete, not all registers are listed. Further
 *              There are probably some inconsistencies throughout the MSP430
 *              family which need to be addressed.
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef MSP430_REGS_H
#define MSP430_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Shortcut to specify 8-bit wide registers
 */
#define REG8                volatile uint8_t

/**
 * @brief   Shortcut to specify 16-bit wide registers
 */
#define REG16               volatile uint16_t

/**
 * @brief   Special function registers
 */
typedef struct {
    REG8    IE1;            /**< interrupt enable 1 */
    REG8    IE2;            /**< interrupt enable 2 */
    REG8    IFG1;           /**< interrupt flag 1 */
    REG8    IFG2;           /**< interrupt flag 2 */
    REG8    RPCR1;          /** */
    REG8    RPCR2;          /** */
} msp_sfr_t;

/**
 * @brief   Digital I/O Port w/o interrupt functionality (P3-P6)
 */
typedef struct {
    REG8    IN;         /**< input data */
    REG8    reserved_a;
    REG8    OD;         /**< output data */
    REG8    reserved_b;
    REG8    DIR;        /**< pin direction */
    REG8    reserved_c;
    REG8    REN;        /**< alternative function select */
    REG8    reserved_d;
    REG8    DS;        /** */
    REG8    reserved_e;
    REG8    SEL;         /** */
} msp_port_t;

/**
 * @brief   Digital I/O Port with interrupt functionality (P1 & P2)
 */
typedef struct {
    REG8    IN;         /**< input data  0x00 */
    REG8    reserved_a; /** 0x01 */
    REG8    OD;         /**< output data 0x02 */
    REG8    reserved_b; /** 0x03 */
    REG8    DIR;        /**< pin direction 0x04 */
    REG8    reserved_c; /** 0x05 */
    REG8    REN;        /** 0x06 */
    REG8    reserved_d; /** 0x07 */
    REG8    DS;         /** 0x08 */
    REG8    reserved_e; /** 0x09 */
    REG8    SEL;        /**< alternative function select 0x0a */
    REG8    reserved_f; /** 0x0b */
    REG8    reserved_g; /** 0x0c */
    REG8    reserved_h; /** 0x0d */
    REG16   IV; /** 0x0e */
    REG8    reserved_j; /** 0x10*/
    REG8    reserved_l; /** 0x11*/
    REG8    reserved_m; /** 0x12*/
    REG8    reserved_n; /** 0x13*/
    REG8    reserved_o; /** 0x14*/
    REG8    reserved_p; /** 0x15*/
    REG8    reserved_q; /** 0x16*/
    REG8    reserved_r; /** 0x17*/
    REG8    IES; /** 0x18*/
    REG8    reserved_s; /** 0x19*/
    REG8    IE; /** 0x1a*/
    REG8    reserved_t; /** 0x1b*/
    REG8    IFG; /** 0x1c */
} msp_port_isr_t;
/**
 * @brief   USART (UART, SPI and I2C) registers
 */
typedef struct {
    REG8    CTL;        /**< USART control */
    REG8    TCTL;       /**< transmit control */
    REG8    RCTL;       /**< receive control */
    REG8    MCTL;       /**< modulation control */
    REG8    BR0;        /**< baud rate control 0 */
    REG8    BR1;        /**< baud rate control 1 */
    REG8    RXBUF;      /**< receive buffer */
    REG8    TXBUF;      /**< transmit buffer */
} msp_usart_t;

/**
 * @brief   USCI universal serial control interface registers
 */
typedef struct {
    REG8    ACTL1;      /**< A control 0 0x00*/ 
    REG8    ACTL0;      /**< A control 1 0x01*/
    REG8    reserved_a;
    REG8    reserved_b;
    REG8    reserved_c;
    REG8    reserved_d;
    REG8    ABR0;       /**< A baud rate control 0  0x06*/
    REG8    ABR1;       /**< A baud rate control 1 0x07*/
    REG8    AMCTL;      /**< A modulation control 0x08*/
    REG8    reserved_e;
    REG8    ASTAT;      /**< A status 0x0A*/
    REG8    reserved_f;
    REG8    ARXBUF;     /**< A receive buffer 0x0C*/
    REG8    reserved_g;
    REG8    ATXBUF;     /**< A transmit buffer 0x0E*/
    REG8    reserved_h;
    REG8    ABCTL0;      /**< auto baud rate control 0x10*/
    REG8    reserved_i;
    REG8    IRTCTL;     /**< IrDA transmit control 0x12*/
    REG8    IRRCTL;     /**< IrDA receive control 0x13*/
    REG8    reserved_j;
    REG8    reserved_k;
    REG8    reserved_l;
    REG8    reserved_m;
    REG8    reserved_n;
    REG8    reserved_o;
    REG8    reserved_p;
    REG8    reserved_q;
    REG8    AIE;        /** 0x1C*/
    REG8    AIFG;       /** 0x1D*/
    REG8    AIV;        /** 0x1E*/
} msp_usci_t;


/**
 * @brief   USCI SPI specific registers
 */
typedef struct {
    REG8    CTL1;      /**< control 1 0x00*/
    REG8    CTL0;      /**< control 0 0x01*/
    REG8    reserved_a; /* 02 */
    REG8    reserved_b; /* 03 */
    REG8    reserved_c; /* 04 */
    REG8    reserved_d; /* 05 */
    REG8    BR0;       /**< bit rate 0 0x06 */
    REG8    BR1;       /**< bit rate 1 0x07*/
    REG8    reserved_e;  /**< reserved 0x08 */
    REG8    reserved_f; /* 09*/
    REG8    STAT;      /**< status 0x0A*/
    REG8    reserved_g; /* 0B*/
    REG8    RXBUF;     /**< receive buffer 0x0C*/
    REG8    reserved_h; /* 0D*/
    REG8    TXBUF;     /**< transmit buffer 0x0E*/
    REG8    reserved_i /* 0F*/;
    REG8    reserved_j /* 10*/;
    REG8    reserved_k /* 11*/;
    REG8    reserved_l /* 12*/;
    REG8    reserved_m /* 13*/;
    REG8    reserved_n /* 14*/;
    REG8    reserved_o /* 15*/;
    REG8    reserved_p /* 16*/;
    REG8    reserved_q /* 17*/;
    REG8    reserved_r /* 18*/;
    REG8    reserved_s /* 19*/;
    REG8    reserved_t /* 1a*/;
    REG8    reserved_u /* 1b*/;
    REG8    IE;         /** 0x1C*/
    REG8    IFG;        /** 0x1D*/
    REG8    IV;         /** 0x1E*/
} msp_usci_spi_t;

/**
 * @brief   Timer interrupt status registers
 */
typedef struct {
    REG16   TAIV;       /**< TIMER_A interrupt status */
    REG16   reserved[7];    /**< reserved */
    REG16   TBIV;       /**< TIMER_B interrupt status */
} msp_timer_ivec_t;

/**
 * @brief   Timer module registers
 */
typedef struct {
    REG16   CTL;        /**< timer control */
    REG16   CCTL[7];    /**< capture compare channel control */
    REG16   R;          /**< current counter value */
    REG16   CCR[7];     /**< capture compare channel values */
} msp_timer_t;

/**
 * @brief   SFR interrupt enable 1 register bitmap
 * @{
 */
#define SFR_IE1_OFIE                (0x02)
#define SFR_IE1_URXIE0              (0x40)
#define SFR_IE1_UTXIE0              (0x80)
/** @} */

/**
 * @brief   SFR interrupt enable 2 register bitmap
 * @{
 */
#define SFR_IE2_UCA0RXIE            (0x01)
#define SFR_IE2_UCA0TXIE            (0x02)
#define SFR_IE2_URXIE2              (0x10)
#define SFR_IE2_UTXIE2              (0x20)
/** @} */

/**
 * @brief   SFR interrupt flag 1 register bitmap
 * @{
 */
#define SFR_IFG1_OFIFG              (0x02)
#define SFR_IFG1_URXIFG0            (0x40)
#define SFR_IFG1_UTXIFG0            (0x80)
/** @} */

/**
 * @brief   SFR interrupt flag 2 register bitmap
 * @{
 */
#define SFR_IFG2_UCA0RXIFG          (0x01)
#define SFR_IFG2_UCA0TXIFG          (0x02)
#define SFR_IFG2_URXIFG1            (0x10)
#define SFR_IFG2_UTXIFG1            (0x20)
/** @} */

/**
 * @brief   SFR module enable register 1
 * @{
 */
#define SFR_ME1_USPIE0              (0x40)
/** @} */

/**
 * @brief   SFR module enable register 2
 * @{
 */
#define SFR_ME2_USPIE1              (0x10)
/** @} */

/**
 * @brief   USART control register bitmap
 * @{
 */
#define USART_CTL_SWRST             (0x01)
#define USART_CTL_MM                (0x02)
#define USART_CTL_SYNC              (0x04)
#define USART_CTL_LISTEN            (0x08)
#define USART_CTL_CHAR              (0x10)
#define USART_CTL_SPB               (0x20)
#define USART_CTL_PEV               (0x40)
#define USART_CTL_PENA              (0x80)
/** @} */

/**
 * @brief   USART transmit control register bitmap
 * @{
 */
#define USART_TCTL_TXEPT            (0x01)
#define USART_TCTL_STC              (0x02)
#define USART_TCTL_TXWAKE           (0x04)
#define USART_TCTL_URXSE            (0x08)
#define USART_TCTL_SSEL_MASK        (0x30)
#define USART_TCTL_SSEL_UCLKI       (0x00)
#define USART_TCTL_SSEL_ACLK        (0x10)
#define USART_TCTL_SSEL_SMCLK       (0x20)
#define USART_TCTL_CKPL             (0x40)
#define USART_TCTL_CKPH             (0x80)
/** @} */

/**
 * @brief   USART receive control register bitmap
 * @{
 */
#define USART_RCTL_RXERR            (0x01)
#define USART_RCTL_RXWAKE           (0x02)
#define USART_RCTL_URXWIE           (0x04)
#define USART_RCTL_URXEIE           (0x08)
#define USART_RCTL_BRK              (0x10)
#define USART_RCTL_OE               (0x20)
#define USART_RCTL_PE               (0x40)
#define USART_RCTL_FE               (0x80)
/** @} */

/**
 * @brief   USCI control A register 0 bitmap
 * @{
 */
#define USCI_ACTL0_UCSYNC           (0x01)
#define USCI_ACTL0_MODE_MASK        (0x06)
#define USCI_ACTL0_MODE_UART        (0x00)
#define USCI_ACTL0_MODE_ILMM        (0x02)
#define USCI_ACTL0_MODE_ABMM        (0x04)
#define USCI_ACTL0_MODE_UART_ABR    (0x06)
#define USCI_ACTL0_SPB              (0x08)
#define USCI_ACTL0_7BIT             (0x10)
#define USCI_ACTL0_MSB              (0x20)
#define USCI_ACTL0_PAR              (0x40)
#define USCI_ACTL0_PEN              (0x80)
/** @} */

/**
 * @brief   USCI control register 0 bitmap SPI mode
 * @{
 */
#define USCI_SPI_CTL0_UCSYNC        (0x01)
#define USCI_SPI_CTL0_MODE_3        (0x06)
#define USCI_SPI_CTL0_MODE_0        (0x00)
#define USCI_SPI_CTL0_MODE_1        (0x02)
#define USCI_SPI_CTL0_MODE_2        (0x04)
#define USCI_SPI_CTL0_MST           (0x08)
#define USCI_SPI_CTL0_7BIT          (0x10)
#define USCI_SPI_CTL0_MSB           (0x20)
#define USCI_SPI_CTL0_CKPL          (0x40)
#define USCI_SPI_CTL0_CKPH          (0x80)
/** @} */

/**
 * @brief   USCI status register bitmap SPI mode
 * @{
 */
#define USCI_SPI_STAT_UCBUSY        (0x01)
#define USCI_SPI_STAT_UCOE          (0x20)
#define USCI_SPI_STAT_UCFE          (0x40)
#define USCI_SPI_STAT_UCLISTEN      (0x80)
/** @} */

/**
 * @brief   USCI control A register 1 bitmap
 * @{
 */
#define USCI_ACTL1_SWRST            (0x01)
#define USCI_ACTL1_TXBRK            (0x02)
#define USCI_ACTL1_TXADDR           (0x04)
#define USCI_ACTL1_DORM             (0x08)
#define USCI_ACTL1_BRKIE            (0x10)
#define USCI_ACTL1_RXEIE            (0x20)
#define USCI_ACTL1_SSEL_MASK        (0xc0)
#define USCI_ACTL1_SSEL_UCLK        (0x00)
#define USCI_ACTL1_SSEL_ACLK        (0x40)
#define USCI_ACTL1_SSEL_SMCLK_0     (0x80)
#define USCI_ACTL1_SSEL_SMCLK       (0xc0)
/** @} */

/**
 * @brief   USCI control register 1 bitmap SPI mode
 * @{
 */
#define USCI_SPI_CTL1_SWRST            (0x01)
#define USCI_SPI_CTL1_SSEL_MASK        (0xc0)
#define USCI_SPI_CTL1_SSEL_NA          (0x00)
#define USCI_SPI_CTL1_SSEL_ACLK        (0x40)
#define USCI_SPI_CTL1_SSEL_SMCLK       (0xc0)
/** @} */

/**
 * @brief   USCI modulation A control register
 * @{
 */
#define USCI_AMCTL_OS16             (0x01)
#define USCI_AMCTL_BRS_MASK         (0xe0)
#define USCI_AMCTL_BRS_SHIFT        (1U)
#define USCI_AMCTL_BRF_MASK         (0xf0)
#define USCI_AMCTL_BRF_SHIFT        (4U)
/** @} */

/**
 * @brief   USCI status A register bitmap
 * @{
 */
#define USCI_ASTAT_BUSY             (0x01)
#define USCI_ASTAT_IDLE             (0x02)
#define USCI_ASTAT_ADDR             (0x02)
#define USCI_ASTAT_RXERR            (0x04)
#define USCI_ASTAT_BRK              (0x08)
#define USCI_ASTAT_PE               (0x10)
#define USCI_ASTAT_OE               (0x20)
#define USCI_ASTAT_FE               (0x40)
#define USCI_ASTAT_LISTEN           (0x80)
/** @} */

/**
 * @brief   Timer Control register bitmap
 * @{
 */
#define TIMER_CTL_IFG                 (0x0001)
#define TIMER_CTL_IE                  (0x0002)
#define TIMER_CTL_CLR                 (0x0004)
#define TIMER_CTL_MC_MASK             (0x0030)
#define TIMER_CTL_MC_STOP             (0x0000)
#define TIMER_CTL_MC_UP               (0x0010)
#define TIMER_CTL_MC_CONT             (0x0020)
#define TIMER_CTL_MC_UPDOWN           (0x0030)
#define TIMER_CTL_ID_MASK             (0x00c0)
#define TIMER_CTL_ID_DIV1             (0x0000)
#define TIMER_CTL_ID_DIV2             (0x0040)
#define TIMER_CTL_ID_DIV4             (0x0080)
#define TIMER_CTL_ID_DIV8             (0x00c0)
#define TIMER_CTL_TASSEL_MASK         (0x0300)
#define TIMER_CTL_TASSEL_TCLK         (0x0000)
#define TIMER_CTL_TASSEL_ACLK         (0x0100)
#define TIMER_CTL_TASSEL_SMCLK        (0x0200)
#define TIMER_CTL_TASSEL_INV_TCLK     (0x0300)
/** @} */

/**
 * @brief   Timer Channel Control register bitmap
 * @{
 */
#define TIMER_CCTL_CCIFG              (0x0001)
#define TIMER_CCTL_COV                (0x0002)
#define TIMER_CCTL_OUT                (0x0004)
#define TIMER_CCTL_CCI                (0x0008)
#define TIMER_CCTL_CCIE               (0x0010)
#define TIMER_CCTL_OUTMOD_MASK        (0x00e0)
#define TIMER_CCTL_OUTMOD_OUTVAL      (0x0000)
#define TIMER_CCTL_OUTMOD_SET         (0x0020)
#define TIMER_CCTL_OUTMOD_TOG_RESET   (0x0040)
#define TIMER_CCTL_OUTMOD_SET_RESET   (0x0060)
#define TIMER_CCTL_OUTMOD_TOGGLE      (0x0080)
#define TIMER_CCTL_OUTMOD_RESET       (0x00a0)
#define TIMER_CCTL_OUTMOD_TOG_SET     (0x00c0)
#define TIMER_CCTL_OUTMOD_RESET_SET   (0x00e0)
#define TIMER_CCTL_CAP                (0x0100)
#define TIMER_CCTL_CLLD_MASK          (0x0600)
#define TIMER_CCTL_SCS                (0x0800)
#define TIMER_CCTL_CCIS_MASK          (0x3000)
#define TIMER_CCTL_CM_MASK            (0xc000)
/** @} */

/**
 * @brief   Base register address definitions
 * @{
 */
#ifndef SFR_BASE
#define SFR_BASE                ((uint16_t)0x0000)
#endif
#define PORT_1_BASE             ((uint16_t)0x0200)
#define PORT_2_BASE             ((uint16_t)0x0201)
#define PORT_3_BASE             ((uint16_t)0x0220)
#define PORT_4_BASE             ((uint16_t)0x0221)
#define PORT_5_BASE             ((uint16_t)0x0240)
#define PORT_6_BASE             ((uint16_t)0x0241)
#define PORT_7_BASE             ((uint16_t)0x0260)
#define PORT_8_BASE             ((uint16_t)0x0261)
#define PORT_9_BASE             ((uint16_t)0x0280)
#define PORT_10_BASE            ((uint16_t)0x0281)
#define PORT_11_BASE            ((uint16_t)0x02a0)
#define PORT_J_BASE             ((uint16_t)0x0320)
#define CLK_BASE                ((uint16_t)0x04a0)
#define USART_0_BASE            ((uint16_t)0x0070)
#define USART_1_BASE            ((uint16_t)0x0078)
#define TIMER_IVEC_BASE         ((uint16_t)0x036e)
#define TIMER_A_BASE            ((uint16_t)0x0340)
#define TIMER_B_BASE            ((uint16_t)0x03c0)
#define WD_BASE                 ((uint16_t)0x015c)
#define USCI_0_BASE             ((uint16_t)0x05c0)
#define USCI_0_A_BASE           ((uint16_t)0x05c0)
#define USCI_0_B_BASE           ((uint16_t)0x05e0)
#define USCI_1_BASE             ((uint16_t)0x0600)
#define USCI_1_A_BASE           ((uint16_t)0x0600)
#define USCI_1_B_BASE           ((uint16_t)0x0620)
#define USCI_3_B_BASE		((uint16_t)0x06a0)
/** @} */

/**
 * @brief   Typing of base register objects
 * @{
 */
#define SFR                     ((msp_sfr_t *)SFR_BASE)
#define PORT_1                  ((msp_port_t *)PORT_1_BASE)
#define PORT_2                  ((msp_port_t *)PORT_2_BASE)
#define PORT_3                  ((msp_port_t *)PORT_3_BASE)
#define PORT_4                  ((msp_port_t *)PORT_4_BASE)
#define PORT_5                  ((msp_port_t *)PORT_5_BASE)
#define PORT_6                  ((msp_port_t *)PORT_6_BASE)
#define PORT_7                  ((msp_port_t *)PORT_7_BASE)
#define PORT_8                  ((msp_port_t *)PORT_8_BASE)
#define PORT_9                  ((msp_port_t *)PORT_9_BASE)
#define PORT_10                 ((msp_port_t *)PORT_10_BASE)
#define PORT_11                 ((msp_port_t *)PORT_11_BASE)
#define PORT_J                  ((msp_port_t *)PORT_J_BASE)
#define CLK                     ((msp_clk_t *)CLK_BASE)
#define USART_0                 ((msp_usart_t *)USART_0_BASE)
#define USART_1                 ((msp_usart_t *)USART_1_BASE)
#define TIMER_IVEC              ((msp_timer_ivec_t *)TIMER_IVEC_BASE)
#define TIMER_A                 ((msp_timer_t *)TIMER_A_BASE)
#define TIMER_B                 ((msp_timer_t *)TIMER_B_BASE)
#define WD                      ((msp_wd_t *)WD_BASE)
#define USCI_0                  ((msp_usci_t *)USCI_0_BASE)
#define USCI_1                  ((msp_usci_t *)USCI_1_BASE)
#define USCI_0_A_SPI            ((msp_usci_spi_t *)USCI_0_A_BASE)
#define USCI_0_B_SPI            ((msp_usci_spi_t *)USCI_0_B_BASE)
#define USCI_1_A                ((msp_usci_t *)USCI_1_A_BASE)
#define USCI_1_B                ((msp_usci_t *)USCI_1_B_BASE)
#define USCI_3_B_SPI		((msp_usci_spi_t *)USCI_3_B_BASE)
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* MSP430_REGS_H */
/** @} */
