
/* 
 * File:  lcd.h 
 * Author: Jesus
 * Comments: Header para controlar el LDC
 * Revision history: 
 */

// lcd.h
#ifndef LCD_H
#define LCD_H

// Esta función inicializa el LCD. Configura los pines del LCD como salidas y envía comandos al LCD para configurar el modo de operación.
void lcd_init(void);

// Esta función limpia el display del LCD. Envía un comando al LCD para borrar todos los caracteres que se muestran.
void lcd_clear(void);

// Esta función mueve el cursor del LCD a una posición específica. 'pos' es la posición del cursor y 'line' es la línea del LCD (1 o 2).
void lcd_goto(unsigned char pos, unsigned char line);

// Esta función imprime una cadena de caracteres en el LCD. 's' es un puntero a la cadena de caracteres que se va a imprimir.
void lcd_puts(const char * s);

// Esta función envía un dato al LCD. 'data' es el dato que se va a enviar. Esta función se utiliza para enviar caracteres individuales al LCD.
void lcd_data(unsigned char data);

#endif // LCD_H