/* 
 * File:   main.c
 * Author: Corey W hodge
 *
 * Created on November 23, 2019, 2:15 PM
 * 
 * 
 *  Startup Notes:
 * 
 *      When you create a new project you must :
 * 
 *      1. File -> New File -> C main -> Save
 *            This generates a workspace main file to code in
 * 
 *      2. Production -> Set Configuration Bits -> Generate Config Bits -> Copy and paste to main.c in Source Files Folder
 *              * OSC = INTIO7     // Oscillator Selection bits (Internal oscillator block, CLKO function on RA6, port function on RA7)
 *              * WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
 *              * LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
 *              * PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
 * 
 *      3. Define the Oscillator frequency for the chip
 *          // Crystal Oscillator Frequency for PIC18F4250
 *          #define _XTAL_FREQ 8000000
 * 
 *      4. Include the Compiler header file 
 *          // Compiler
 *          #include <xc.h>
 * 
 *      5. !!! Click regular hammer (build) for first build
 *         Then I can Run/Debug/Clean Build etc after first build
 * 
 *      6. DEBUGGER:
 *              - build hammer, build hammer, big green arrow, breakpoint w/ little arrow
 *              - build until successful ( usually 2x) 
 *              - then click the run arrow to program the device 
 *              - then click breakpoint w/ little arrow to restart program on device and run in debug mode
 *              - to select specific variables to keep in debugger window
 *                  > double click variable to highlight the whole word
 *                  > R.click the variable
 *                  > select  new watch     (or shift+command+F9)
 * 
 *      Template Organization:
 *          ConfigurationFile - contains pragma #config settings for chip
 *          Definitions       - contains define and re-definitions of ports
 *          Library's         - contains all compiler library's
 * 
 *      Auto Complete && Documentation 
 *          - type first few letters of function 
 *          - press control + space 
 *          - Auto Complete screen will appear
 * 
 *      Inject assembly code into embedded C file like this
 *           asm("CLRF PORTA");
 * 
 */

/**
 *  Custom Configuration File
*/
//#include "0ConfigurationFile.h"

/**
 * PIC18F4520 Configuration Bit Settings
 *  #pragma configuration statements should precede project file includes.
 */

// CONFIG1H
#pragma config OSC = INTIO7     // Oscillator Selection bits (Internal oscillator block, CLKO function on RA6, port function on RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

/**
 * Definitions
 *  should preceed includes
 */
//#include "1Definitions.h"

// Crystal Oscillator Frequency for PIC18F4250
#define _XTAL_FREQ 8000000

// Declarations
#define INPUT 0xFF
#define OUTPUT 0x00
#define ON  1
#define OFF 0

/**
 * Library's
 */
//#include "2Librarys.h"

// Compiler
#include <xc.h>

// C Standard Input Output
#include <stdio.h>

// C Standard Library
#include <stdlib.h>

// For booleans
#include <stdbool.h>
/**
 * Global Variables to share among system
 */
//#include "3GlobalVars.h"

// Global Static Variables
static const bool TRUE = true;

static const bool FALSE = false;

/**
 * General Functions to set up Chip and PORTS
 */
#include "4GeneralFunctions.h"

/**
 * Project Functions specific to program
 */


/*
 * 
 */
int main(int argc, char** argv) {
    
    // blink led on pin RD2
    setPinIO(PORTD, 2, OUTPUT);

    LATD = 0x00;
    
    while ( TRUE ) {
        
        //delay
        delay_sec(2);
        
        writePinHigh(PORTD, 2);
        
        delay_sec(2);
        
        writePinLow(PORTD, 2);
        
    }
    
    return (EXIT_SUCCESS);
}

