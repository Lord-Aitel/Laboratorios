#include <stdio.h>
#include <stdlib.h>

struct jugador{
	char nombre[40];
	int vida;
};
typedef struct{
	
	char nombre[40];
	char tipo[20];
	int ataque;
	int defensa;
	int vida;
	
}Carta;
struct historial{
	
};

int main() {
	
	FILE *file;
	
	file = fopen("cartas.txt","r");
	
	if(file == NULL)
	{
		printf("no existe un archivo que leer");
		return 1;
	}
	
	
	Carta cartas[60];
	
	int leer = 0;
	int opcion;
	int datos = 0;
	do{
		leer = fscanf(file,
					"%39[^,],%19[^,],%d,%d,%d\n",
					cartas[datos].nombre,
					cartas[datos].tipo,
					&cartas[datos].vida,
					&cartas[datos].ataque,
					&cartas[datos].defensa);
		
		if(leer == 5) datos++;
		
		if(leer != 5 && !feof(file))
		{
			printf("Formato incorrecto");
		}
		if(ferror(file))
		{
			printf("error de lectura");
			return 1;
		}
		
	}while(!feof(file));
	
	fclose(file);
	
	printf("\n%d datos leer.\n\n",datos);
	
	int i;
	
	for(i = 0; i<datos; i++)
	{
		printf("%s,%s,%d,%d,%d",
				cartas[i].nombre,
				cartas[i].tipo,
				cartas[i].vida,
				cartas[i].ataque,
				cartas[i].defensa);
		printf("\n");
	}

    printf("Bienvenido al juego de The Clash of the Guardians\n");
	//utiliza while para que el jugador no ingrese valores fuera de las alternativas dadas, dado el caso se repetira el proceso
    /*while (1) {
    	
        printf("Escoje una opcion:\n");
        printf("1 para crear una carta\n");
        printf("2 para jugar\n");
        printf("3 para mostrar historial\n");
        printf("4 para salir\n");
        printf("Ingresa tu eleccion: ");
        scanf("%d", &opcion);
		
        if (opcion == 1) {
            printf("Has seleccionado la Opcion de crar una carta\n");
            // Código para la opción 1
            
            break; // Salir del bucle si la opción es válida
        } else if (opcion == 2) {
            printf("Has seleccionado la Opcion 2\n");
            printf("");
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
    }*/

    return 0;
}
