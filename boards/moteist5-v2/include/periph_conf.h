/*
 * Copyright (C) 2014 INRIA
 *               2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_z1
 * @{
 *
 * @file
 * @brief       Zolertia Z1 peripheral configuration
 *
 * @author      Oliver Hahm <oliver.hahm@inria.fr>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Clock configuration
 * @{
 */
/** @todo   Move all clock configuration code here from the board.h */
#define CLOCK_CORECLOCK     (16000000U)

#define CLOCK_CMCLK         CLOCK_CORECLOCK     /* no divider programmed */
/** @} */

/**
 * @name    Timer configuration
 * @{
 */
#define TIMER_NUMOF         (1U)
#define TIMER_BASE          (TIMER_A)
#define TIMER_CHAN          (3)
#define TIMER_ISR_CC0       (TIMER0_A0_VECTOR)
#define TIMER_ISR_CCX       (TIMER0_A1_VECTOR)
/** @} */

/**
 * @name    UART configuration
 * @{
 */
#define UART_NUMOF          (1U)

#define UART_USE_USCI
#define UART_BASE           (USCI_0)
#define UART_IE             (USCI_0->AIE)
#define UART_IF             (USCI_0->AIFG)
#define UART_IE_RX_BIT      (1 << 0)
#define UART_IE_TX_BIT      (1 << 1)
#define UART_RX_PORT        ((msp_port_t *)PORT_3)
#define UART_RX_PIN         (1 << 5)
#define UART_TX_PORT        ((msp_port_t *)PORT_3)
#define UART_TX_PIN         (1 << 4)
#define UART_RX_ISR         (USCI_A0_VECTOR)
#define UART_TX_ISR         (USCI_A0_VECTOR)
/** @} */

 /**
 * @name    SPI configuration
 * @{
 */
#define SPI_NUMOF           (1U)

/* SPI configuration */
#define SPI_USE_USCI
#define SPI_BASE            (USCI_3_B_SPI)
#define SPI_IE              (USCI_3_B_SPI->IE)
#define SPI_IF              (USCI_3_B_SPI->IFG)
#define SPI_IE_RX_BIT       (1 << 0)
#define SPI_IE_TX_BIT       (1 << 1)
#define SPI_PIN_MISO        GPIO_PIN(P10, 2) 
#define SPI_PIN_MOSI        GPIO_PIN(P10, 1) 
#define SPI_PIN_CLK         GPIO_PIN(P10, 3) //was 3
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
