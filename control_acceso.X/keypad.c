/*
 * File:   keypad.c
 * Author: Jesus
 *
 */

// keypad.h
#include "keypad.h"

void keyboard_init()
{
    // Configura los primeros 4 bits de PORTB como salidas (R0-R3) y los últimos 4 bits como entradas (C0-C3)
    TRISB = 0XF0;
    // Habilita las resistencias pull-up internas del microcontrolador PIC
    OPTION_REG &= 0X7F;
}

// Lee una tecla presionada en el teclado
unsigned char keyboard_get()
{
    // Inicializa el puerto B a 0
    PORTB = 0X00;

    // Espera hasta que se presione una tecla
    while (C1 && C2 && C3 && C4);

    // Se ejecuta mientras se presiona una tecla
    while (!C1 || !C2 || !C3 || !C4)
    {
        // Verifica qué fila del teclado está activa
        R2 = R3 = R4 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 0;
            break;
        }
        R2 = 0;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 1;
            break;
        }
        R3 = 0;
        R2 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 2;
            break;
        }
        R4 = 0;
        R3 = 1;
        if (!C1 || !C2 || !C3 || !C4)
        {
            rowloc = 3;
            break;
        }
    }

    // Determina qué columna está activa
    if (C1 == 0 && C2 != 0 && C3 != 0 && C4 != 0)
        colloc = 0;
    else if (C1 != 0 && C2 == 0 && C3 != 0 && C4 != 0)
        colloc = 1;
    else if (C1 != 0 && C2 != 0 && C3 == 0 && C4 != 0)
        colloc = 2;
    else if (C1 != 0 && C2 != 0 && C3 != 0 && C4 == 0)
        colloc = 3;

    // Espera hasta que se suelte la tecla
    while (C1 == 0 || C2 == 0 || C3 == 0 || C4 == 0);

    // Devuelve el carácter correspondiente a la tecla presionada
    return (keypad[rowloc][colloc]);
};
