# Control_Acceso
Tutorial para EC3081 (Universidad Simon Bolivar) PIC16F877A – Programado en C

# Descripción del LCD

Un LCD (Liquid Crystal Display) es un tipo de pantalla que utiliza cristales líquidos para producir imágenes. Los LCD son comúnmente utilizados en una variedad de dispositivos electrónicos debido a su bajo consumo de energía y su capacidad para producir imágenes claras.

En el contexto de la programación de microcontroladores, un LCD es a menudo utilizado para mostrar información al usuario. Esto puede incluir datos de sensores, mensajes de estado, menús de usuario y más.

El LCD en este código es controlado a través de varios pines de un microcontrolador. Estos pines incluyen:

- **RS (Registro de Selección):** Este pin se utiliza para seleccionar entre el registro de datos (para enviar datos al LCD) y el registro de instrucciones (para enviar comandos al LCD).
- **EN (Enable):** Este pin se utiliza para habilitar el LCD. Cuando este pin es alto, el LCD procesará los datos o comandos que se le envíen.
- **DATA:** Estos pines se utilizan para enviar datos o comandos al LCD.

El código proporciona varias funciones para interactuar con el LCD, incluyendo la inicialización del LCD, el envío de datos y comandos, la limpieza de la pantalla, y la impresión de cadenas de caracteres.

# Descripción del Teclado

Un teclado en el contexto de la programación de microcontroladores es un dispositivo de entrada que permite al usuario interactuar con el sistema.

En este código, el teclado es leído a través de varios pines de un microcontrolador. Estos pines son configurados como entradas y salidas y se utilizan para detectar cuándo se presiona una tecla.

El código proporciona varias funciones para interactuar con el teclado, incluyendo la inicialización del teclado y la lectura de una tecla presionada. Cuando se llama a la función para leer una tecla, la función espera hasta que se presione una tecla y luego devuelve el valor de la tecla presionada.

# Función Main

La función `main` es la función principal del programa. Realiza las siguientes tareas:

1. Inicializa el teclado y el LCD.
2. Imprime "Tutorial EC3083:" en la primera línea del LCD.
3. Lee una tecla presionada en el teclado y la convierte a una cadena.
4. Imprime la tecla presionada en la segunda línea del LCD.
5. Entra en un bucle infinito, donde lee una nueva tecla presionada en el teclado. Si la nueva tecla es diferente de la tecla anterior, actualiza la tecla, convierte la nueva tecla a una cadena, limpia la segunda línea del LCD e imprime la nueva tecla en la segunda línea del LCD.