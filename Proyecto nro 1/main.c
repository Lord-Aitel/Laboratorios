#include <stdio.h>
#include <stdlib.h>

struct jugador{
	char nombre[40];
	int vida;
};
typedef struct{
	
	char nombre[40];
	int ataque;
	int defensa;
	int vida;
	
}carta;
struct historial{
	
};

int main() {
	
	FILE *file;
	
	file = fopen("file.txt","r");
	Carta cartas[60];
	
	int read = 0;
	int opcion;
	int records = 0;
	do{
		read=fscan(file
		"%c,%d,%d\n",
		&carta)
	}

    printf("Bienvenido al juego de The Clash of the Guardians\n");
	//utiliza while para que el jugador no ingrese valores fuera de las alternativas dadas, dado el caso se repetira el proceso
    while (1) {
    	
        printf("Escoje una opcion:\n");
        printf("1 para crear una carta\n");
        printf("2 para jugar\n");
        printf("3 para mostrar historial\n");
        printf("4 para salir\n");
        printf("Ingresa tu eleccion: ");
        scanf("%d", &opcion);
		
        if (opcion == 1) {
            printf("Has seleccionado la Opcion 1\n");
            printf("continuacion se te mostraran las reglas del juego por mientras se revuelven las cartas\n");
            // Código para la opción 1
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 2) {
            printf("Has seleccionado la Opcion 2\n");
            printf("",)
            // Código para la opción 2
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 3) {
            printf("Has seleccionado la Opcion 3\n");
            // Código para la opción 3
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 4) {
            printf("Saliendo del programa\n");
            break; // Salir del bucle si la opción es válida
        } else {
            printf("Opcion no valida, por favor, selecciona una opcion valida\n");
        }
    }

    return 0;
}
