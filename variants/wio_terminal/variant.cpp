/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/*
 * Pins descriptions
 * TCC0 IOSET4
 * TCC1 IOSET2
 * TCC2 IOSET1
 * TCC3 IOSET1
 * TCC4 IOSET1
 */

const PinDescription g_APinDescription[] =
    {
        // 0..8 -  Raspberry pi Digital & AD pins
        {PORTB, 8, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), ADC_Channel2, TC4_CH0, TC4_CH0, EXTERNAL_INT_8}, // 0/RPI_D0/RPI_A0
        {PORTB, 9, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), ADC_Channel3, TC4_CH1, TC4_CH1, EXTERNAL_INT_9}, // 1/RPI_D1/RPI_A1
        {PORTA, 7, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7},
        {PORTB, 4, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel6, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4},
        {PORTB, 5, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel7, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5},
        {PORTB, 6, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel8, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6},
        {PORTA, 4, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4}, // 2/RPI_D2/RPI_A2
        {PORTB, 7, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel9, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7},
        {PORTA, 6, PIO_ANALOG, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6},

        //9..10 DAC0 DAC1
        {PORTA, 2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2}, //DAC0
        {PORTA, 5, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5}, //DAC1

        //11  RTL8720D IRQ
        {PORTC, 20, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4}, // RTL8720D_PA12/SPI_IRQ

        //12 BUZZER_CTR
        {PORTD, 11, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH4, TCC0_CH4, EXTERNAL_INT_6},

        // 13 (LED)
        {PORTA, 15, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH1, TCC2_CH1, EXTERNAL_INT_15},

        //14 WIO_IR
        {PORTB, 31, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC0_CH1, TC0_CH1, EXTERNAL_INT_15},
        {PORTA, 20, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH0, TCC0_CH0, EXTERNAL_INT_4},
        {PORTB, 15, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC4_CH1, TCC4_CH1, EXTERNAL_INT_15},

        //17..26 FPC Digital & AD pins
        {PORTB, 28, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH4, TCC0_CH4, EXTERNAL_INT_14},
        {PORTB, 17, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC3_CH1, TCC3_CH1, EXTERNAL_INT_1},
        {PORTB, 29, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC1_CH5, TCC1_CH5, EXTERNAL_INT_15},
        {PORTA, 14, PIO_DIGITAL, PIN_ATTR_PWM_E, No_ADC_Channel, TC3_CH0, TC3_CH0, EXTERNAL_INT_14},
        {PORTC, 1, PIO_DIGITAL, PIN_ATTR_ANALOG_ALT, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1},
        {PORTC, 2, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},
        {PORTC, 3, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3},
        {PORTC, 4, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH0, TCC0_CH0, EXTERNAL_INT_4},
        {PORTC, 31, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel13, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15},
        {PORTD, 0, PIO_DIGITAL, PIN_ATTR_ANALOG_ALT, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0},

        //27 WIO_LIGHT
        {PORTD, 1, PIO_DIGITAL, PIN_ATTR_ANALOG_ALT, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1},

        //28..30 USER_BUTTON
        {PORTC, 26, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10}, //BUTTON_1
        {PORTC, 27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11}, //BUTTON_2
        {PORTC, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12}, //BUTTON_3

        //31..35 SWITCH
        {PORTD, 20, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10}, // SWITCH_U UP
        {PORTD, 12, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7},  // SWITCH_B  LEFT
        {PORTD, 9, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4},   // SWITCH_Y  RIGHT
        {PORTD, 8, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3},   // SWITCH_X  DOWN
        {PORTD, 10, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5},  // SWITCH_Z  PRESS

        //36..38 GCLK
        {PORTB, 14, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC4_CH0, NOT_ON_TIMER, EXTERNAL_INT_14}, //GCLK0
        {PORTB, 12, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC3_CH0, NOT_ON_TIMER, EXTERNAL_INT_12}, //GCLK1
        {PORTB, 13, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC3_CH1, NOT_ON_TIMER, EXTERNAL_INT_13}, //GCLK2

        //39 MIC INPUT
        {PORTC, 30, PIO_ANALOG, PIN_ATTR_ANALOG_ALT, ADC_Channel12, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14}, //MIC_INPUT

//40..41 UART Serial1
#if ROLE
        {PORTB, 26, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F), No_ADC_Channel, TCC1_CH2, NOT_ON_TIMER, EXTERNAL_INT_12}, //UART1_TX, SERCOM4.1
        {PORTB, 27, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F), No_ADC_Channel, TCC1_CH3, NOT_ON_TIMER, EXTERNAL_INT_13}, //UART1_RX, SERCOM4.0
#else
        {PORTB, 26, PIO_SERCOM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F), No_ADC_Channel, TCC1_CH2, NOT_ON_TIMER, EXTERNAL_INT_12}, //UART1_TX, SERCOM2.0//SERCOM4.1
        {PORTB, 27, PIO_SERCOM, (PIN_ATTR_DIGITAL | PIN_ATTR_PWM_F), No_ADC_Channel, TCC1_CH3, NOT_ON_TIMER, EXTERNAL_INT_13}, //UART1_RX, SERCOM2.1//SERCOM4.0
#endif
        // 42..44 - USB
        {PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8},     // USB_D-
        {PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9},     // USB_D+
        {PORTA, 27, PIO_COM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11}, // USB _HOST_EN

        //45..46 I2C Wire2
        {PORTA, 16, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, TCC1_CH1, EXTERNAL_INT_0}, // SCL
        {PORTA, 17, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, TCC1_CH0, EXTERNAL_INT_1}, // SDA

        //47..50 SPI
        //PB00 PB02 PB03 PB01 (MISO:PAD2, MOSI:PAD0, SCK:PAD1, SS:PAD3)
        {PORTB, 0, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), No_ADC_Channel, TC7_CH0, TC7_CH0, EXTERNAL_INT_0},
        {PORTB, 2, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), No_ADC_Channel, TC6_CH0, TC6_CH0, EXTERNAL_INT_2},
        {PORTB, 3, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), No_ADC_Channel, TC6_CH1, TC6_CH1, EXTERNAL_INT_3},
        {PORTB, 1, PIO_SERCOM_ALT, (PIN_ATTR_ANALOG | PIN_ATTR_PWM_E), No_ADC_Channel, TC7_CH1, TC7_CH1, EXTERNAL_INT_1},

        //51..54 I2S
        //PA23 PB16 PA22 PA21 (FS SCK SDI SDO);
        {PORTA, 20, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH0, TCC0_CH0, EXTERNAL_INT_7},
        {PORTB, 16, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
        {PORTA, 22, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH2, NOT_ON_TIMER, EXTERNAL_INT_6},
        {PORTA, 21, PIO_DIGITAL, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH1, NOT_ON_TIMER, EXTERNAL_INT_5},

        //55..60 QSPI (SCK, CS, IO0, IO1, IO2, IO3)
        {PORTA, 8, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI},
        {PORTA, 9, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9},
        {PORTA, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10},
        {PORTA, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11},
        {PORTB, 10, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10},
        {PORTB, 11, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11},

        //61..65   SPI2  SD_SPI
        //PC18 PC16 PC17 PC19 PD21(MISO:PAD2, MOSI:PAD0, SCK:PAD1, SS:PAD3; SD_DET)
        {PORTC, 18, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},
        {PORTC, 16, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0},
        {PORTC, 17, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1},
        {PORTC, 19, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3},
        {PORTD, 21, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, NOT_ON_TIMER, EXTERNAL_INT_11},

        //66..76   SPI3 LCD_SPI
        //PB8 PB19 PB20 PB21 (MISO PAD2, MOSI PAD3 SCK:PAD1 SS:PAD0)
        {PORTB, 18, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2},
        {PORTB, 19, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3},
        {PORTB, 20, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4},
        {PORTB, 21, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5},

        {PORTC, 6, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6}, //LCD_D/C
        {PORTC, 7, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5}, //LCD_RESET
        {PORTC, 5, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5}, //LCD_BACKLIGHT

        //4 WIRE LCD TOUCH
        {PORTC, 10, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10}, //LCD_XL
        {PORTC, 11, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11}, //LCD_YU
        {PORTC, 12, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH2, NOT_ON_TIMER, EXTERNAL_INT_12},  //LCD_XR
        {PORTC, 13, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH2, NOT_ON_TIMER, EXTERNAL_INT_13},  //LCD_YD

        //GYROSCOPE
        //................................................
        //77..78 I2C Wire1
        {PORTA, 12, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_12}, // GYROSCOPE_SCL
        {PORTA, 13, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_13}, // GYROSCOPE_SDA

        //79 GYROSCOPE_INT1
        {PORTC, 21, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5},

        // RTL8720D
        //................................................
        //80..81
        {PORTA, 18, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2}, //RTL8720D_CHIP_PU
        {PORTA, 19, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3}, //RTL8720D_PA13/SPI_SYNC

        //82..83 RTL8720D UART Serial2
        {PORTC, 22, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6}, // SERCOM1.0
        {PORTC, 23, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7}, // SERCOM1.1

        //84..87 SPI1 RTL8720D_SPI
        //PC24/S0.2 PB24/S0.0 PB25/S0.1 PC25/S0.3 (MISO:PAD2, MOSI:PAD0, SCK:PAD1, SS:PAD3)
        {PORTC, 24, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8},
        {PORTB, 24, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8},
        {PORTB, 25, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
        {PORTC, 25, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9},

        //88..90 SWD
        {PORTA, 30, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
        {PORTA, 31, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},
        {PORTB, 30, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},

        //91..92 OUTPUT_CTR
        {PORTC, 14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14},
        {PORTC, 15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15},
};

const void *g_apTCInstances[TCC_INST_NUM + TC_INST_NUM] = {TCC0, TCC1, TCC2, TCC3, TCC4, TC0, TC1, TC2, TC3, TC4, TC5, TC6, TC7};
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM + TC_INST_NUM] = {TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TCC3_GCLK_ID, TCC4_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID, TC4_GCLK_ID, TC5_GCLK_ID, TC6_GCLK_ID, TC7_GCLK_ID};

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);
SERCOM sercom4(SERCOM4);
SERCOM sercom5(SERCOM5);
SERCOM sercom6(SERCOM6);
SERCOM sercom7(SERCOM7);

Uart Serial1(&SERCOM_SERIAL1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);

Uart Serial2(&SERCOM_SERIAL2, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX);

void SERCOM1_0_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM1_1_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM1_2_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM1_3_Handler()
{
  Serial2.IrqHandler();
}

#if ROLE
void SERCOM4_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM4_3_Handler()
{
  Serial1.IrqHandler();
}
#else
void SERCOM2_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM2_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM2_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM2_3_Handler()
{
  Serial1.IrqHandler();
}
#endif