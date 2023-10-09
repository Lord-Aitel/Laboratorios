#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[40];
    char tipo[20];
    int ataque;
    int defensa;
    int vida;
} Carta;

typedef struct {
	char nombre[30];//nombre del jugador
    Carta mano[3]; // Mano del jugador, con un máximo de 3 cartas
    int puntosVida; // Puntos de vida del jugador
} Jugador;


/*
void sacarCartaDeMano(Jugador *jugador) {
    // Verifica si la mano del jugador no está vacía
    if (jugador->mano[0].nombre[0] == '\0') {
        printf("La mano del jugador está vacía. No se pueden sacar más cartas.\n");
        return;
    }
	int i;
    printf("Cartas en tu mano:\n");
    for (i = 0; i < 3; i++) {
        if (jugador->mano[i].nombre[0] != '\0') {
            printf("%d. %s\n", i + 1, jugador->mano[i].nombre);
        }
    }

    int opcion;
    printf("Selecciona una carta para sacar (1-3): ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 3 || jugador->mano[opcion - 1].nombre[0] == '\0') {
        printf("Opción no válida. Por favor, selecciona una carta válida.\n");
        return;
    }

    // Mueve la carta seleccionada al campo de batalla
    Carta cartaSacada = jugador->mano[opcion - 1];
    jugador->mano[opcion - 1].nombre[0] = '\0'; // Borra la carta de la mano
    // Implementa aquí la lógica para agregar la carta al campo de batalla
}

void atacarOponente(Jugador *jugador, Jugador *oponente) {
    // Verifica si hay una carta en el campo de batalla del jugador
    int cartaEnCampo = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (jugador->mano[i].nombre[0] != '\0') {
            cartaEnCampo = 1;
            break;
        }
    }

    if (!cartaEnCampo) {
        printf("No tienes cartas en el campo de batalla para atacar.\n");
        return;
    }
    printf("Cartas en tu campo de batalla:\n");
    for (i = 0; i < 3; i++) {
        if (jugador->mano[i].nombre[0] != '\0') {
            printf("%d. %s\n", i + 1, jugador->mano[i].nombre);
        }
    }

    int opcion;
    printf("Selecciona una carta para atacar (1-3): ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 3 || jugador->mano[opcion - 1].nombre[0] == '\0') {
        printf("Opción no válida. Por favor, selecciona una carta válida para atacar.\n");
        return;
    }

    // Verifica si el oponente tiene cartas en su campo de batalla
    int oponenteTieneCartas = 0;
    for (i = 0; i < 3; i++) {
        if (oponente->mano[i].nombre[0] != '\0') {
            oponenteTieneCartas = 1;
            break;
        }
    }

    if (oponenteTieneCartas) {
        // Si el oponente tiene cartas en su campo de batalla, el jugador debe seleccionar una carta objetivo
        printf("Cartas en el campo de batalla del oponente:\n");
        for ( i = 0; i < 3; i++) {
            if (oponente->mano[i].nombre[0] != '\0') {
                printf("%d. %s\n", i + 1, oponente->mano[i].nombre);
            }
        }

        int cartaObjetivo;
        printf("Selecciona una carta objetivo para atacar (1-3): ");
        scanf("%d", &cartaObjetivo);

        if (cartaObjetivo < 1 || cartaObjetivo > 3 || oponente->mano[cartaObjetivo - 1].nombre[0] == '\0') {
            printf("Opción no válida. Por favor, selecciona una carta objetivo válida para atacar.\n");
            return;
        }

        // Calcula el daño del ataque y réstalo a la vida de la carta objetivo del oponente
        int danio = calcularDanio(jugador->mano[opcion - 1], oponente->mano[cartaObjetivo - 1]);
        oponente->mano[cartaObjetivo - 1].vida -= danio;

        // Verifica si la carta objetivo ha sido derrotada
        if (oponente->mano[cartaObjetivo - 1].vida <= 0) {
            oponente->mano[cartaObjetivo - 1].nombre[0] = '\0'; // Borra la carta objetivo
        }
    } else {
        // Si el oponente no tiene cartas en su campo de batalla, el ataque se dirige directamente a los puntos de vida del oponente
        int danio = calcularDanio(jugador->mano[opcion - 1], oponente->mano[0]);
        oponente->puntosVida -= danio;

        // Verifica si el oponente ha sido derrotado
        if (oponente->puntosVida <= 0) {
            printf("¡Has derrotado al oponente!\n");
            // Aquí puedes implementar la lógica para determinar el ganador
        }
    }
}

void turnoJugador(Jugador *jugador, Jugador *oponente) {
    int opcion;
    printf("Escoje una opcion:\n");
    printf("1 para sacar una carta\n");
    printf("2 para atacar al oponente\n");
    printf("Ingresa tu eleccion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            //sacarCartaDeMano(jugador);
            break;
        case 2:
            //atacarOponente(jugador, oponente);
            break;
        default:
            printf("Opción no válida. Por favor, selecciona una opción válida.\n");
    }
}
*/
void crearCarta(Carta cartas[], int *datos) {
    if (*datos >= 100) {
        printf("La lista de cartas está llena. No se puede agregar más cartas.\n");
        return;
    }

    printf("Ingrese el nombre de la carta: ");
    scanf("%s", cartas[*datos].nombre);

    // Validación del tipo de carta
    int tipoValido = 0;
    int i;
    
    do {
        printf("Ingrese el tipo de la carta (Mago, Vikingo, Nigromante o Bestia): ");
        scanf("%s", cartas[*datos].tipo);
        // Convierte el tipo ingresado a minúsculas para facilitar la comparación
        for (i = 0; cartas[*datos].tipo[i]; i++) {
            cartas[*datos].tipo[i] = tolower(cartas[*datos].tipo[i]);
        }
        if (strcmp(cartas[*datos].tipo, "mago") == 0 ||
            strcmp(cartas[*datos].tipo, "vikingo") == 0 ||
            strcmp(cartas[*datos].tipo, "nigromante") == 0 ||
            strcmp(cartas[*datos].tipo, "bestia") == 0) {
            tipoValido = 1;
        } else {
            printf("Tipo de carta no válido. Por favor, ingrese un tipo válido.\n");
        }
    } while (!tipoValido);

    printf("Ingrese la vida de la carta: ");
    scanf("%d", &cartas[*datos].vida);
    printf("Ingrese el ataque de la carta: ");
    scanf("%d", &cartas[*datos].ataque);
    printf("Ingrese la defensa de la carta: ");
    scanf("%d", &cartas[*datos].defensa);

    (*datos)++; // Incrementa el contador de datos
    printf("La carta ha sido creada y agregada a la lista.\n");
}

int main() {
	
	srand(time(NULL));
	
    FILE *file;

    file = fopen("cartas.txt", "r");

    if (file == NULL) {
        printf("No existe un archivo que leer.\n");
        return 1;
    }

    Carta cartas[60]; // Array para almacenar cartas
    int datos = 0; 
	
    do {
        int leer = fscanf(file,
                          "%39[^,],%19[^,],%d,%d,%d\n",
                          cartas[datos].nombre,
                          cartas[datos].tipo,
                          &cartas[datos].vida,
                          &cartas[datos].ataque,
                          &cartas[datos].defensa);

        if (leer == 5) {
            datos++;
        }

        if (leer != 5 && !feof(file)) {
            printf("Formato incorrecto\n");
        }
        if (ferror(file)) {
            printf("Error de lectura\n");
            return 1;
        }

    } while (!feof(file) && datos < 60); // Se detiene si llega al final del archivo o se alcanza el límite de cartas (60)

    fclose(file);

    printf("%d datos leidos.\n\n", datos);

	printf("\n");
	printf("\n");
    printf("Bienvenido al juego de The Clash of the Guardians\n");
	//utiliza while para que el jugador no ingrese valores fuera de las alternativas dadas, dado el caso se repetira el proceso
    while (1) {
    	
		int turno = 1; // Indicador de turno (1 para jugador1, 2 para jugador2)
    	int opcion;
        printf("Escoje una opcion:\n");
        printf("1 para crear una carta\n");
        printf("2 para jugar\n");
        printf("3 para mostrar historial\n");
        printf("4 para salir\n");
        printf("Ingresa tu eleccion: ");
        scanf("%d", &opcion);
		
        if (opcion == 1) {
            printf("Has seleccionado la Opcion de crear una carta\n");
            crearCarta(cartas, &datos);
            break; 
        } else if (opcion == 2) {
            printf("Has seleccionado la Opcion 2\n");
            
            	Jugador jugador;
            	Jugador computadora;
            	
            	while (jugador.puntosVida > 0 && computadora.puntosVida > 0) {
                // Turno del jugador
                printf("Turno del jugador:\n");
                // Implementa la lógica para sacar una carta y tomar una decisión

                // Verifica si el juego ha terminado
                /*int resultado = determinarGanador(jugador, computadora);
               if (resultado != 0) {
                    // El juego ha terminado, muestra el resultado y sale del bucle
                    printf("El juego ha terminado. %s\n", (resultado == 1) ? "¡Ganaste!" : "La computadora ganó.");
                    break;
                }

                // Turno de la computadora
                printf("Turno de la computadora:\n");
                // Implementa la lógica para que la computadora juegue (por ejemplo, ataque aleatorio)

                // Verifica si el juego ha terminado
                resultado = determinarGanador(jugador, computadora);
                if (resultado != 0) {
                    // El juego ha terminado, muestra el resultado y sale del bucle
                    printf("El juego ha terminado. %s\n", (resultado == 1) ? "¡Ganaste!" : "La computadora ganó.");
                    break;
                }*/
            }
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
