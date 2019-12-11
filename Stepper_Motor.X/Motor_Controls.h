
/* 
 * File:   
 * Author: 
 * Comments:    Method for moving conveyor 
 * Revision history: 
 */


#ifndef XC_HEADER_Move_Conveyor
#define	XC_HEADER_Move_Conveyor

#include <xc.h> // include processor files - each processor file is guarded.  


/**
 * Stepper Required @global vars
 * int curr_position    :   curr_position of stepper motor, initialize to 0
 *                          as HOME base for conveyor positioning.
 * 
 * // Enable : High , Low to send signal
 * #define STEPPER_EN    LATXbits.LATXx
 * 
 * // Direction : High forward, Low reverse
 * #define STEPPER_DIR   LATXbits.LATXx
 * 
 * // Pulse: each pulse received is one step 
 * #define STEPPER_PUL   LATXbits.LATXx
 * 
 */







/**
 * Stepper Setup
 */
void Stepper_Init(){
    
    // Prepare port E to send signals DIO
    ADCON0bits.ADON = 0; // turn off A/D Conversion
    ADCON1bits.PCFG3 = 1;   //  set all Analog pins as DIO
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 1;
    
    // Set 3 Ports of I/O as output 
    //      to control driver
    TRISE = 0x00; // output to stepper driver
    
    // Initialize port values
    // LEDS ATTACHED SHOWS Pins working 
//      STEPPER_EN = 1;
//    __delay_ms(50);
//    STEPPER_DIR = 1;
//    __delay_ms(50);
//    STEPPER_PUL = 1;
//    __delay_ms(50);
//    STEPPER_EN = 0;
//    __delay_ms(50);
//    STEPPER_DIR = 0;
//    __delay_ms(50);
//    STEPPER_PUL = 0;
//    __delay_ms(50);
    
    // initialize global variable
    curr_position = 0;
}


/**
 *  Function to step the motor in reverse direction
 * 
 * @param next_position
 * 
 * @param #global curr_position
 * 
 * @return 
 */
void Move_Conveyor_Reverse( int next_position ) {
    
    // Set Direction of Motor spin to high for reverse
    STEPPER_DIR = 1;
    
    // turn on movement
    STEPPER_EN = 1;
    
    for (int i = STEPPER_FULL_STEP; i > 0; i--){
            
        STEPPER_PUL = 1;
            
        __delay_us(5);
            
        STEPPER_PUL = 0;
            
        __delay_us(5);
    }
    
    // turn off movement
    STEPPER_EN = 0;
    
    // adjust current position by one step
    curr_position--;
}

/**
 *  Function to step the motor in reverse direction
 * 
 * @param next_position
 * 
 * @global curr_position
 * 
 * @return 
 */
void Move_Conveyor_Forward( int next_position ) {
    
    // Set Direction of Motor spin to low for forward
    STEPPER_DIR = 0;
    
    // turn on movement
    STEPPER_EN = 1;
    
    for (int i = STEPPER_FULL_STEP; i > 0; i--){
            
        STEPPER_PUL = 1;
            
        __delay_us(5);
            
        STEPPER_PUL = 0;
            
        __delay_us(5);
    }
    
    // turn off movement
    STEPPER_EN = 0;
    
    // adjust current position by one step
    curr_position++;
}
#endif	/* XC_HEADER_TEMPLATE_H */