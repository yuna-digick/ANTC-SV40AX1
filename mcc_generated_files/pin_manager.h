/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F24K50
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BCD_2 aliases
#define BCD_2_TRIS                 TRISAbits.TRISA0
#define BCD_2_LAT                  LATAbits.LATA0
#define BCD_2_PORT                 PORTAbits.RA0
#define BCD_2_ANS                  ANSELAbits.ANSA0
#define BCD_2_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define BCD_2_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define BCD_2_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define BCD_2_GetValue()           PORTAbits.RA0
#define BCD_2_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define BCD_2_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define BCD_2_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define BCD_2_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set BCD_1 aliases
#define BCD_1_TRIS                 TRISAbits.TRISA1
#define BCD_1_LAT                  LATAbits.LATA1
#define BCD_1_PORT                 PORTAbits.RA1
#define BCD_1_ANS                  ANSELAbits.ANSA1
#define BCD_1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BCD_1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BCD_1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BCD_1_GetValue()           PORTAbits.RA1
#define BCD_1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BCD_1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BCD_1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BCD_1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BCD_3 aliases
#define BCD_3_TRIS                 TRISAbits.TRISA2
#define BCD_3_LAT                  LATAbits.LATA2
#define BCD_3_PORT                 PORTAbits.RA2
#define BCD_3_ANS                  ANSELAbits.ANSA2
#define BCD_3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BCD_3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BCD_3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BCD_3_GetValue()           PORTAbits.RA2
#define BCD_3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BCD_3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BCD_3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define BCD_3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set BCD_0 aliases
#define BCD_0_TRIS                 TRISAbits.TRISA3
#define BCD_0_LAT                  LATAbits.LATA3
#define BCD_0_PORT                 PORTAbits.RA3
#define BCD_0_ANS                  ANSELAbits.ANSA3
#define BCD_0_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BCD_0_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BCD_0_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BCD_0_GetValue()           PORTAbits.RA3
#define BCD_0_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BCD_0_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BCD_0_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define BCD_0_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set DOT aliases
#define DOT_TRIS                 TRISAbits.TRISA4
#define DOT_LAT                  LATAbits.LATA4
#define DOT_PORT                 PORTAbits.RA4
#define DOT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DOT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DOT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DOT_GetValue()           PORTAbits.RA4
#define DOT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DOT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA6
#define LED_LAT                  LATAbits.LATA6
#define LED_PORT                 PORTAbits.RA6
#define LED_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED_GetValue()           PORTAbits.RA6
#define LED_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set I2C_RST aliases
#define I2C_RST_TRIS                 TRISBbits.TRISB3
#define I2C_RST_LAT                  LATBbits.LATB3
#define I2C_RST_PORT                 PORTBbits.RB3
#define I2C_RST_WPU                  WPUBbits.WPUB3
#define I2C_RST_ANS                  ANSELBbits.ANSB3
#define I2C_RST_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define I2C_RST_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define I2C_RST_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define I2C_RST_GetValue()           PORTBbits.RB3
#define I2C_RST_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define I2C_RST_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define I2C_RST_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define I2C_RST_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define I2C_RST_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define I2C_RST_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set ANODE aliases
#define ANODE_TRIS                 TRISBbits.TRISB4
#define ANODE_LAT                  LATBbits.LATB4
#define ANODE_PORT                 PORTBbits.RB4
#define ANODE_WPU                  WPUBbits.WPUB4
#define ANODE_ANS                  ANSELBbits.ANSB4
#define ANODE_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define ANODE_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define ANODE_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define ANODE_GetValue()           PORTBbits.RB4
#define ANODE_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define ANODE_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define ANODE_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define ANODE_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define ANODE_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define ANODE_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SW_1 aliases
#define SW_1_TRIS                 TRISCbits.TRISC0
#define SW_1_LAT                  LATCbits.LATC0
#define SW_1_PORT                 PORTCbits.RC0
#define SW_1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SW_1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SW_1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SW_1_GetValue()           PORTCbits.RC0
#define SW_1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SW_1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set SW_2 aliases
#define SW_2_TRIS                 TRISCbits.TRISC1
#define SW_2_LAT                  LATCbits.LATC1
#define SW_2_PORT                 PORTCbits.RC1
#define SW_2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SW_2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SW_2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SW_2_GetValue()           PORTCbits.RC1
#define SW_2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SW_2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set SW_3 aliases
#define SW_3_TRIS                 TRISCbits.TRISC2
#define SW_3_LAT                  LATCbits.LATC2
#define SW_3_PORT                 PORTCbits.RC2
#define SW_3_ANS                  ANSELCbits.ANSC2
#define SW_3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SW_3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SW_3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SW_3_GetValue()           PORTCbits.RC2
#define SW_3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SW_3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SW_3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SW_3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/