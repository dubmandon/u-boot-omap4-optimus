/*
 * (C) Copyright 2004-2006
 * Texas Instruments, <www.ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef _OMAP34XX_I2C_H_
#define _OMAP34XX_I2C_H_

/* Get the i2c base addresses */
#include <asm/arch/cpu.h>

enum {
	I2C1	=	0,
	I2C2,
	I2C3,
	I2C4,
	I2C_MAX
};

#define I2C_DEFAULT_BASE I2C_BASE1
#ifdef CONFIG_DRIVER_OMAP44XX_I2C
#define I2C_REV                 (0x00)
#define I2C_IE                  (0x2C)
#define I2C_IE1                 (0x84)
#define I2C_IE_CLR              (0x30)
#define I2C_STAT1               (0x88)
#define I2C_STAT                (0x28)
#define I2C_IV                  (0x34)
#define I2C_BUF                 (0x94)
#define I2C_CNT                 (0x98)
#define I2C_DATA                (0x9c)
#define I2C_SYSC                (0x10)
#define I2C_CON                 (0xA4)
#define I2C_OA                  (0xA8)
#define I2C_SA                  (0xAc)
#define I2C_PSC                 (0xB0)
#define I2C_SCLL                (0xB4)
#define I2C_SCLH                (0xB8)
#define I2C_SYSTEST             (0xBc)
#define I2C_SYSS		(0x90)
#else
#define I2C_REV                 (0x00)
#define I2C_IE                  (0x04)
#define I2C_STAT                (0x08)
#define I2C_IV                  (0x0c)
#define I2C_BUF                 (0x14)
#define I2C_CNT                 (0x18)
#define I2C_DATA                (0x1c)
#define I2C_SYSC                (0x20)
#define I2C_CON                 (0x24)
#define I2C_OA                  (0x28)
#define I2C_SA                  (0x2c)
#define I2C_PSC                 (0x30)
#define I2C_SCLL                (0x34)
#define I2C_SCLH                (0x38)
#define I2C_SYSTEST             (0x3c)
#endif

/* I2C masks */

/* I2C Interrupt Enable Register (I2C_IE): */
#define I2C_IE_GC_IE    (1 << 5)
#define I2C_IE_XRDY_IE  (1 << 4)        /* Transmit data ready interrupt enable */
#define I2C_IE_RRDY_IE  (1 << 3)        /* Receive data ready interrupt enable */
#define I2C_IE_ARDY_IE  (1 << 2)        /* Register access ready interrupt enable */
#define I2C_IE_NACK_IE  (1 << 1)        /* No acknowledgment interrupt enable */
#define I2C_IE_AL_IE    (1 << 0)        /* Arbitration lost interrupt enable */

/* I2C Status Register (I2C_STAT): */

#define I2C_STAT_SBD    (1 << 15)       /* Single byte data */
#define I2C_STAT_BB     (1 << 12)       /* Bus busy */
#define I2C_STAT_ROVR   (1 << 11)       /* Receive overrun */
#define I2C_STAT_XUDF   (1 << 10)       /* Transmit underflow */
#define I2C_STAT_AAS    (1 << 9)        /* Address as slave */
#define I2C_STAT_GC     (1 << 5)
#define I2C_STAT_XRDY   (1 << 4)        /* Transmit data ready */
#define I2C_STAT_RRDY   (1 << 3)        /* Receive data ready */
#define I2C_STAT_ARDY   (1 << 2)        /* Register access ready */
#define I2C_STAT_NACK   (1 << 1)        /* No acknowledgment interrupt enable */
#define I2C_STAT_AL     (1 << 0)        /* Arbitration lost interrupt enable */


/* I2C Interrupt Code Register (I2C_INTCODE): */

#define I2C_INTCODE_MASK        7
#define I2C_INTCODE_NONE        0
#define I2C_INTCODE_AL          1       /* Arbitration lost */
#define I2C_INTCODE_NAK         2       /* No acknowledgement/general call */
#define I2C_INTCODE_ARDY        3       /* Register access ready */
#define I2C_INTCODE_RRDY        4       /* Rcv data ready */
#define I2C_INTCODE_XRDY        5       /* Xmit data ready */

/* I2C Buffer Configuration Register (I2C_BUF): */

#define I2C_BUF_RDMA_EN         (1 << 15)       /* Receive DMA channel enable */
#define I2C_BUF_XDMA_EN         (1 << 7)        /* Transmit DMA channel enable */

/* I2C Configuration Register (I2C_CON): */

#define I2C_CON_EN      (1 << 15)       /* I2C module enable */
#define I2C_CON_BE      (1 << 14)       /* Big endian mode */
#define I2C_CON_STB     (1 << 11)       /* Start byte mode (master mode only) */
#define I2C_CON_MST     (1 << 10)       /* Master/slave mode */
#define I2C_CON_TRX     (1 << 9)        /* Transmitter/receiver mode (master mode only) */
#define I2C_CON_XA      (1 << 8)        /* Expand address */
#define I2C_CON_STP     (1 << 1)        /* Stop condition (master mode only) */
#define I2C_CON_STT     (1 << 0)        /* Start condition (master mode only) */

/* I2C System Test Register (I2C_SYSTEST): */

#define I2C_SYSTEST_ST_EN       (1 << 15)       /* System test enable */
#define I2C_SYSTEST_FREE        (1 << 14)       /* Free running mode (on breakpoint) */
#define I2C_SYSTEST_TMODE_MASK  (3 << 12)       /* Test mode select */
#define I2C_SYSTEST_TMODE_SHIFT (12)            /* Test mode select */
#define I2C_SYSTEST_SCL_I       (1 << 3)        /* SCL line sense input value */
#define I2C_SYSTEST_SCL_O       (1 << 2)        /* SCL line drive output value */
#define I2C_SYSTEST_SDA_I       (1 << 1)        /* SDA line sense input value */
#define I2C_SYSTEST_SDA_O       (1 << 0)        /* SDA line drive output value */

/* I2C System Control Register (I2C_SYSC): */
#define I2C_SYSC_SRST           (1 << 1)        /* Software Reset */

/* I2C System Status Register (I2C_SYSS): */
#define I2C_SYSS_RDONE          (1 << 0)        /* Internel reset monitoring */

#define I2C_SCLL_SCLL        (0)
#define I2C_SCLL_SCLL_M      (0xFF)
#define I2C_SCLL_HSSCLL      (8)
#define I2C_SCLH_HSSCLL_M    (0xFF)
#define I2C_SCLH_SCLH        (0)
#define I2C_SCLH_SCLH_M      (0xFF)
#define I2C_SCLH_HSSCLH      (8)
#define I2C_SCLH_HSSCLH_M    (0xFF)

#define OMAP_I2C_STANDARD          100
#define OMAP_I2C_FAST_MODE         400
#define OMAP_I2C_HIGH_SPEED        3400

#define SYSTEM_CLOCK_12       12000
#define SYSTEM_CLOCK_13       13000
#define SYSTEM_CLOCK_192      19200
#define SYSTEM_CLOCK_96       96000

#define I2C_IP_CLK SYSTEM_CLOCK_96
#define I2C_PSC_MAX          (0x0f)
#define I2C_PSC_MIN          (0x00)

#endif