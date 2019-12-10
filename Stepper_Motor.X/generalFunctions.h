/* 
 * File:   GeneralFunctions.h
 * Author: Cory W. Hodge
 * Comments: 
 * Revision history: 12/12/19
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GENERAL_FUNCTIONS
#define	GENERAL_FUNCTIONS

/**
 * Returns binary mask for values 0:7
 * @param pin : <0:7>
 * @return mask for pins <0:7>
 */
int getPinMask( int pin ) {
    
    if ( pin == 0 )
        return 0b00000001;
    
    if ( pin == 1 )
        return 0b00000010;
    
    if ( pin == 2 )
        return 0b00000100;
    
    if ( pin == 3 )
        return 0b00001000;
    
    if ( pin == 4 )
        return 0b00010000;
    
    if ( pin == 5 )
        return 0b00100000;
    
    if ( pin == 6 )
        return 0b01000000;
    
    if ( pin == 7 )
        return 0b10000000;
    
    // else error
    return -1;
}

/**
 * Set relative (0:7) pin to corosponding direction
 * @param port : PORTA, PORTB, .. , E
 * @param relativePin   : <0:7>
 * @param direction : INPUT, OUTPUT
 */
void setPinIO( volatile unsigned int port , int relativePin, int direction ) {
    
    /**
     * git a mask for corosponding pin number
     */
    int pinMask = getPinMask(relativePin);
    
    // PORT A PINs
    if ( port == PORTA ) {
        
        // if current TRIS[pinMask] is INPUT and desired is OUTPUT
        if ( (TRISA & pinMask) && (direction == OUTPUT)) {
            TRISA &= ( ~pinMask );
        }
        
        // if current TRIS[pinMask] is OUTPUT and desired is INPUT
        if ( (~TRISA & pinMask) && (direction == INPUT) ) {
                TRISA |= ( pinMask );
        }
    }
    
    // PORT B PINs
    if ( port == PORTB ) {
        
        // if current TRIS[pinMask] is INPUT and desired is OUTPUT
        if ( (TRISB & pinMask) && (direction == OUTPUT)) {
            TRISB &= ( ~pinMask );
        }
        
        // if current TRIS[pinMask] is OUTPUT and desired is INPUT
        if ( (~TRISB & pinMask) && (direction == INPUT) ) {
                TRISB |= ( pinMask );
        }
    }
    
    // PORT C PINs
    if ( port == PORTC ) {
        
        // if current TRIS[pinMask] is INPUT and desired is OUTPUT
        if ( (TRISC & pinMask) && (direction == OUTPUT)) {
            TRISC &= ( ~pinMask );
        }
        
        // if current TRIS[pinMask] is OUTPUT and desired is INPUT
        if ( (~TRISC & pinMask) && (direction == INPUT) ) {
                TRISC |= ( pinMask );
        }
    }
    
    // PORT D PINs
    if ( port == PORTD ) {
        
        // if current TRIS[pinMask] is INPUT and desired is OUTPUT
        if ( (TRISD & pinMask) && (direction == OUTPUT)) {
            TRISD &= ( ~pinMask );
        }
        
        // if current TRIS[pinMask] is OUTPUT and desired is INPUT
        if ( (~TRISD & pinMask) && (direction == INPUT) ) {
                TRISD |= ( pinMask );
        }
    }
    
    // PORT E PINs
     if ( port == PORTE ) {
        
        // if current TRIS[pinMask] is INPUT and desired is OUTPUT
        if ( (TRISE & pinMask) && (direction == OUTPUT)) {
            TRISE &= ( ~pinMask );
        }
        
        // if current TRIS[pinMask] is OUTPUT and desired is INPUT
        if ( (~TRISE & pinMask) && (direction == INPUT) ) {
                TRISE |= ( pinMask );
        }
    }
}

/**
 * Sets all pins on port to direction specified with direction argument
 * @param port : PORTA, PORTB, .. , E
 * @param direction : INPUT, OUTPUT
 */
void setPortIO( volatile unsigned int port , int direction ) {
    
    // PORT A
    if ( port == PORTA ) {
        
        // set IO for each pin in port A to match 'direction'
        for ( int i = 0 ; i < 8 ; i++)
            setPinIO( PORTA , i, direction );
    }
    
    // PORT B
    if ( port == PORTB ) {
        // set IO for each pin in port A to match 'direction'
        for ( int i = 0 ; i < 8 ; i++)
            setPinIO( PORTB , i, direction );
    }
    
    // PORT C
    if ( port == PORTC ) {
        // set IO for each pin in port A to match 'direction'
        for ( int i = 0 ; i < 8 ; i++)
            setPinIO( PORTC , i, direction );
    }
    
    // PORT D
    if ( port == PORTD ) {
        // set IO for each pin in port A to match 'direction'
        for ( int i = 0 ; i < 8 ; i++)
            setPinIO( PORTD , i, direction );    
    }
    
    // PORT E
    if ( port == PORTE ) {
        // set IO for each pin in port A to match 'direction'
        // port E pins <0:2>
        for ( int i = 0 ; i < 3 ; i++)
            setPinIO( PORTE , i, direction );    
    }
}

/**
 * Write a logic HIGH to passed pin
 * @param port : PORTA, PORTB, .. , E
 * @param pin  : <0:7>
 */
void writePinHigh( volatile unsigned int port, int pin){
    
    // get relative pin mask
    int pinMask = getPinMask(pin);
    
    // PORT A
    if ( port == PORTA ) {
        LATA |=  pinMask;
    }
    
    // PORT B
    if ( port == PORTB ) {
        LATB |=  pinMask;
    }
    
    // PORT C
    if ( port == PORTC ) {
        LATC |=  pinMask;
    }
    
    // PORT D 
    if ( port == PORTD ) {
        LATD |=  pinMask;
    }
     // PORT E 
    if ( port == PORTE ) {
        LATE |=  pinMask;
    }
    
    
}

/**
 * Write a logic LOW to passed pin
 * @param port : PORTA, PORTB, .. , E
 * @param pin  : <0:7>
 */
void writePinLow( volatile unsigned int port, int pin ) {
    
    // get pinMask
    int pinMask = getPinMask(pin);
    
    // PORTA
    if ( port == PORTA ) {
        LATA &= ~pinMask;
    }
    
    // PORTB
    if ( port == PORTB ) {
        LATB &= ~pinMask;
    }
    
    // PORTC
    if ( port == PORTC ) {
        LATC &= ~pinMask;
    }
    
    // PORTD
    if ( port == PORTD ) {
        LATD &= ~pinMask;
    }
    
    // PORTE
    if ( port == PORTE ) {
        LATE &= ~pinMask;
    }
}

void delay_sec( int seconds ) {
    
    while ( seconds > 0){
        
        // decrement seconds counter
        seconds--;
        
        // delay one second
        for ( int i = 0 ; i < 1000 ; i++ ) {
            // 1000 ms = 1 second
        }
    }
}
#endif	/* GENERAL_FUNCTIONS */

