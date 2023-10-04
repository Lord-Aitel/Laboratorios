#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct jugador{
	char nombre[40];
	int vida;
};
struct carta{
	char nombre[40];
	int ataque;
	int defensa;
	int vida;
};
struct historial{
	
};

int main() {
	
	int opcion;

    printf("Bienvenido al juego de The Clash of the Guardians\n");

    while (1) {
        printf("Escoje una opcion:\n");
        printf("1. Crear una carta\n");
        printf("2. Jugar\n");
        printf("3. Mostrar historial\n");
        printf("4. Salir\n");
        printf("Ingresa tu eleccion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Has seleccionado la Opcion 1.\n");
            // Código para la opción 1
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 2) {
            printf("Has seleccionado la Opcion 2.\n");
            // Código para la opción 2
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 3) {
            printf("Has seleccionado la Opcion 3.\n");
            // Código para la opción 3
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 4) {
            printf("Saliendo del programa.\n");
            break; // Salir del bucle si la opción es válida
        } else {
            printf("Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
    }

    return 0;
}
