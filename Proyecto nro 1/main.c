#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nombreCarta[40];
    char tipo[20];
    int ataque;
    int defensa;
    int vida;
} Carta;

typedef struct {
    char nombre[30];
    Carta mano[3];
    Carta mazo[12];
    int puntosVida;
} Jugador;

// Función para barajar las cartas
void barajarCartas(Carta cartas[], int n) {
    int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }
}

// Función para repartir cartas al jugador y a la computadora
void repartirCartas(Carta cartas[], Jugador *jugador, Jugador *oponente, int n) {
    int i;
    if (n < 15) {
        printf("No hay suficientes cartas para repartir.\n");
        return;
    }

    // Repartir 3 cartas a la mano del jugador y 3 cartas al oponente
    for (i = 0; i < 3; i++) {
        jugador->mano[i] = cartas[i];
        oponente->mano[i] = cartas[i + 3];
    }

    // Colocar las cartas restantes en el mazo del jugador y el oponente
    for (i = 6; i < n; i++) {
        jugador->mazo[i - 6] = cartas[i];
        oponente->mazo[i - 6] = cartas[i + 3];
    }
}

void atacarComputadora(Jugador *computadora, Jugador *jugador) {
    // Selecciona una carta de la computadora para atacar (aleatoriamente)
    int cartaAtacante = rand() % 3; // Genera un número aleatorio entre 0 y 2

    // Encuentra una carta válida en la mano de la computadora
    while (computadora->mano[cartaAtacante].nombreCarta[0] == '\0') {
        cartaAtacante = rand() % 3;
    }

    // El jugador selecciona una carta aleatoria para defender (solo para este ejemplo)
    int cartaDefensora = rand() % 3;

    // Realiza el ataque
    Carta atacanteCarta = computadora->mano[cartaAtacante];
    Carta defensoraCarta = jugador->mano[cartaDefensora];

    // Calcula el daño neto
    int danoNeto = atacanteCarta.ataque - defensoraCarta.defensa;

    // Resta vida a la carta defensora
    defensoraCarta.vida -= danoNeto;

    // Elimina la carta del jugador si su vida llega a 0 o menos
    if (defensoraCarta.vida <= 0) {
        printf("La carta del jugador ha muerto!\n");
        defensoraCarta.vida = 0;
        jugador->mano[cartaDefensora].nombreCarta[0] = '\0'; // Elimina la carta del jugador
        // Reduce un punto de vida al jugador
        jugador->puntosVida--;
    }

    // Muestra el resultado del ataque
    printf("La computadora ha atacado con %s y causó %d puntos de daño.\n", atacanteCarta.nombreCarta, danoNeto);
    printf("Puntos de vida del jugador: %d\n", jugador->puntosVida);
}

void atacarOponente(Jugador *jugador, Jugador *oponente) {
    // Selecciona una carta del jugador para atacar
    int cartaAtacante;
    do {
        printf("Selecciona una carta para atacar (1-3): ");
        scanf("%d", &cartaAtacante);
        if (cartaAtacante < 1 || cartaAtacante > 3 || jugador->mano[cartaAtacante - 1].nombreCarta[0] == '\0') {
            printf("Opción no válida. Por favor, selecciona una carta válida.\n");
        }
    } while (cartaAtacante < 1 || cartaAtacante > 3 || jugador->mano[cartaAtacante - 1].nombreCarta[0] == '\0');

    // La computadora elige una carta del oponente (puedes implementar tu lógica aquí)
    int cartaOponente = rand() % 3; // Aquí asumimos que la computadora siempre ataca con su primera carta

    // Realiza el ataque
    Carta atacanteCarta = jugador->mano[cartaAtacante - 1];
    Carta oponenteCarta = oponente->mano[cartaOponente - 1];

    // Calcula el daño neto
    int danoNeto = atacanteCarta.ataque - oponenteCarta.defensa;

    // Resta vida a la carta oponente
    oponenteCarta.vida -= danoNeto;

    // Elimina la carta del oponente si su vida llega a 0 o menos
    if (oponenteCarta.vida <= 0) {
        printf("La carta del oponente ha muerto!\n");
        oponenteCarta.vida = 0;
        oponente->mano[cartaOponente - 1].nombreCarta[0] = '\0'; // Elimina la carta del oponente
    }

    // Muestra el resultado del ataque
    printf("%s ha atacado al oponente con %s y causó %d puntos de daño.\n", jugador->nombre, atacanteCarta.nombreCarta, danoNeto);
    printf("Puntos de vida del oponente: %d\n", oponente->puntosVida);
}

void sacarCartaDeMano(Jugador *jugador) {
    // Verifica si la mano del jugador está llena (3 cartas en la mano)
    int cartasEnMano = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (jugador->mano[i].nombreCarta[0] != '\0') {
            cartasEnMano++;
        }
    }

    if (cartasEnMano >= 3) {
        printf("La mano del jugador está llena. No se pueden sacar más cartas.\n");
        return;
    }

    // Encuentra la primera carta disponible en el mazo y colócala en la mano
    for (i = 0; i < 12; i++) {
        if (jugador->mazo[i].nombreCarta[0] != '\0') {
            jugador->mano[cartasEnMano] = jugador->mazo[i];
            jugador->mazo[i].nombreCarta[0] = '\0'; // Elimina la carta del mazo
            break;
        }
    }
}

void turnoComputadora(Jugador *computadora, Jugador *jugador) {
    int accion = rand() % 2; // Genera un número aleatorio (0 o 1) para decidir la acción

    if (accion == 0) {
        // La computadora decide atacar al jugador
        atacarComputadora(computadora, jugador);
    } else {
        // La computadora decide sacar una carta de su mazo
        sacarCartaDeMano(computadora);
    }
}

void turnoJugador(Jugador *jugador, Jugador *oponente) {
    // Mostrar las cartas en mano del jugador
    int i;
    printf("Cartas en tu mano:\n");
    for (i = 0; i < 3; i++) {
        if (jugador->mano[i].nombreCarta[0] != '\0') {
            printf("%d. Nombre: %s, Tipo: %s, Ataque: %d, Defensa: %d, Vida: %d\n",
                   i + 1,
                   jugador->mano[i].nombreCarta,
                   jugador->mano[i].tipo,
                   jugador->mano[i].ataque,
                   jugador->mano[i].defensa,
                   jugador->mano[i].vida);
        }
    }

    int opcion;
    printf("Escoje una opcion:\n");
    printf("1 para sacar una carta\n");
    printf("2 para atacar al oponente\n");
    printf("Ingresa tu elección: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            sacarCartaDeMano(jugador);
            break;
        case 2:
            atacarOponente(jugador, oponente);
            break;
        default:
            printf("Opción no válida. Por favor, selecciona una opción válida.\n");
    }
}

void crearCarta(Carta cartas[], int *datos) {
    if (*datos >= 60) { // Corregido el límite
        printf("La lista de cartas está llena. No se puede agregar más cartas.\n");
        return;
    }

    printf("Ingrese el nombre de la carta: ");
    scanf("%s", cartas[*datos].nombreCarta);

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
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    Carta cartasOriginales[60]; // Array para almacenar cartas originales
    int datos = 0;
    int i;
    Jugador jugador;
    Jugador oponente;

    jugador.puntosVida = 5; // Establecer la vida inicial del jugador
    oponente.puntosVida = 5; // Establecer la vida inicial del oponente

    while (datos < 60 && fscanf(file, " %39[^,],%19[^,],%d,%d,%d\n",
                       cartasOriginales[datos].nombreCarta,
                       cartasOriginales[datos].tipo,
                       &cartasOriginales[datos].vida,
                       &cartasOriginales[datos].ataque,
                       &cartasOriginales[datos].defensa) == 5) {
        datos++;
    }

    fclose(file);

    printf("%d datos leídos.\n\n", datos);

    printf("Bienvenido al juego de The Clash of the Guardians\n");
    printf("Ingresa tu nombre: ");
    scanf("%s", jugador.nombre);

    // Copiar las cartas originales al mazo de jugador y oponente
    for (i = 0; i < 12; i++) {
        jugador.mazo[i] = cartasOriginales[i];
        oponente.mazo[i] = cartasOriginales[i + 3];
    }

    while (1) {
        int turno = 1;
        int opcion;
        printf("Escoje una opcion:\n");
        printf("1 para crear una carta\n");
        printf("2 para jugar\n");
        printf("3 para mostrar historial\n");
        printf("4 para salir\n");
        printf("Ingresa tu elección: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Has seleccionado la Opción de crear una carta\n");
            crearCarta(cartasOriginales, &datos);
        } else if (opcion == 2) {
            printf("Has seleccionado la Opción 2\n");
            barajarCartas(cartasOriginales, datos);
            repartirCartas(cartasOriginales, &jugador, &oponente, datos);
            while (jugador.puntosVida > 0 && oponente.puntosVida > 0) {
                if (turno == 1) {
                    turnoJugador(&jugador, &oponente);
                    turno = 2;
                } else {
                    turnoComputadora(&oponente, &jugador);
                    turno = 1;
                }
            }
        } else if (opcion == 3) {
            printf("Has seleccionado la Opción 3\n");
            // Código para mostrar el historial
        } else if (opcion == 4) {
            printf("Saliendo del programa\n");
            break;
        } else {
            printf("Opción no válida, por favor, selecciona una opción válida\n");
        }
    }

    return 0;
}

