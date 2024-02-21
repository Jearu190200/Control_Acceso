/*
 * File:   lcd.c
 * Author: Jesus
 *
 */

// lcd.c
#include <xc.h>
#include "lcd.h"

// Define los pines del LCD
#define LCD_RS RC1 // Pin RS del LCD a RC1
#define LCD_EN RC0 // PIN E a RC0
#define LCD_DATA PORTD // La Data sera enviada por el Puerto D

// Define la frecuencia del oscilador
#define _XTAL_FREQ 20000000

// Función para enviar un comando al LCD
void lcd_cmd(unsigned char cmd) {
    LCD_RS = 0; // Modo comando
    LCD_DATA = cmd; // Carga el comando
    LCD_EN = 1; // Habilita el LCD
    __delay_ms(1); // Espera un poco
    LCD_EN = 0; // Deshabilita el LCD
}

// Función para enviar datos al LCD
void lcd_data(unsigned char data) {
    LCD_RS = 1; // Modo datos
    LCD_DATA = data; // Carga los datos
    LCD_EN = 1; // Habilita el LCD
    __delay_ms(2); // Espera un poco
    LCD_EN = 0; // Deshabilita el LCD
}

// Función para inicializar el LCD
void lcd_init(void) {
    TRISC &= 0b11111100; // Configura RC1 y RC0 como salidas
    TRISD = 0x00; // Configura todos los pines del Puerto D como salidas
    lcd_cmd(0x38); // Function set: 2 Line, 8-bit, 5x7 dots
    lcd_cmd(0x0C); // Display on, cursor off
    lcd_cmd(0x06); // Entry mode, auto increment with no shift
    lcd_cmd(0x01); // Clear display
}

// Función para limpiar el LCD
void lcd_clear(void) {
    lcd_cmd(0x01); // Clear display
}

// Función para mover el cursor a una posición específica
void lcd_goto(unsigned char pos, unsigned char line) {
    pos = pos & 0x0F; // Ensure within 16 column limit
    if(line == 1) {
        lcd_cmd(0x80 + pos); // 1st line
    } else {
        lcd_cmd(0xC0 + pos); // 2nd line
    }
}

// Función para imprimir una cadena de caracteres en el LCD
void lcd_puts(const char * s) {
    while(*s) {
        lcd_data(*s++); // Envía cada carácter de la cadena al LCD
    }
}