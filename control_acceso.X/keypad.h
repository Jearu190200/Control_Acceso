
/* 
 * File:   Keypad.h
 * Author: Jesus 
 * Comments: Header para controlar el Keypad
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  

// keypad.h
#ifndef _KEYPAD_H
#define _KEYPAD_H

#include <xc.h>
#include "config.h"

// Define las filas del teclado como RB1, RB2 y RB3
#define R2 RB1
#define R3 RB2
#define R4 RB3

// Define las columnas del teclado como RB4, RB5, RB6 y RB7
#define C1 RB4
#define C2 RB5
#define C3 RB6
#define C4 RB7

// Define el puerto del teclado como PORTB
#define Keypad_PORT PORTB

// Define la dirección del puerto del teclado como TRISB
#define Keypad_PORT_Direction TRISB

// Declara la función keyboard_get que devuelve un carácter sin signo
unsigned char keyboard_get();

// Declara la función keyboard_init que no devuelve nada
void keyboard_init();

// Define la matriz del teclado, que mapea las posiciones de las teclas a los caracteres correspondientes
unsigned char keypad[4][4] = {{'0', '0', '0','0'},{'1', '4', '7','*'}, {'2', '5', '8','0'},{'3', '6', '9','#'}};

// Declara las variables rowloc y colloc que almacenan la ubicación de la tecla presionada
unsigned char rowloc, colloc;
#endif

