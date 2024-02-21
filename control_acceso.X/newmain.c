/*
 * File:   newmain.c
 * Author: jesus
 *
 */

#include <xc.h>
#include "stdio.h"

#include "config.h"
#include <pic16f877a.h>

#include "lcd.h"
#include "keypad.h"

#define _XTAL_FREQ 4000000 // Define la frecuencia del oscilador, necesaria para la funci�n __delay_ms()

void init(void){
    TRISA3 = 0; // Configura el pin RA3 como salida
    TRISD = 0x00; // Configura todos los pines del Puerto D como salidas
    TRISC = 0x00; // Configura todos los pines del Puerto C como salidas
}

void main(void) {
    init(); // Llama a la funci�n de inicializaci�n
    lcd_init(); // Inicializa el LCD
    keyboard_init(); // Inicializa el teclado

    // Imprime "Tutorial EC3083:" en la primera línea del LCD
    lcd_goto(0, 1); // Mueve el cursor a la primera posición de la primera línea
    lcd_puts("Tutorial EC3081:");

    // Lee una tecla presionada en el teclado
    unsigned char key = keyboard_get();

    // Convierte la tecla presionada a una cadena
    char key_str[2] = {key, '\0'};

    // Imprime la tecla presionada en la segunda línea del LCD
    lcd_goto(0, 2); // Mueve el cursor a la primera posición de la segunda línea
    lcd_puts(key_str);   

    while(1) {
        // Lee una nueva tecla presionada en el teclado
        unsigned char new_key = keyboard_get();

        // Si la nueva tecla es diferente de la tecla anterior
        if(new_key != key) {
            // Actualiza la tecla
            key = new_key;

            // Convierte la nueva tecla a una cadena
            key_str[0] = key;

            // Limpia la segunda línea del LCD
            lcd_goto(0, 2); // Mueve el cursor a la primera posición de la segunda línea
            lcd_puts("                ");

            // Imprime la nueva tecla en la segunda línea del LCD
            lcd_goto(0, 2); // Mueve el cursor a la primera posición de la segunda línea
            lcd_puts(key_str);
        }
    }
}
