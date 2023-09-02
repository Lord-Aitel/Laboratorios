#include <stdio.h>
#include <stdlib.h>

void parOimpar()
{
	int x;
	
	printf("Hola ingresa un valor entero para comprobar si es par o impar \n");
	scanf("%d", & x);
	
	if(x%2==0)
	{
		printf("el residuo del valor al dividirlo entre dos es 0 por lo tanto es par \n");
	}else
	{
		printf("el residuo del valor al dividirlo entre dos no es 0 por lo tanto no es par \n");
	}
}
void primos()
{
int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("%d no es un numero primo.\n", num);
    } else if (num == 2) {
        printf("%d es un numero primo.\n", num);
    } else if (num % 2 == 0) {
        printf("%d no es un numero primo.\n", num);
    } else {
        int div = 3;
        int esPrimo = 1; 

        while (div * div <= num) {
            if (num % div == 0) {
                esPrimo = 0; 
            }
            div += 2; 
        }

        if (esPrimo) {
            printf("%d es un numero primo.\n", num);
        } else {
            printf("%d no es un numero primo.\n", num);
        }
    }
}
void promedio()
{
	int longitud, i;

    printf("Ingrese la longitud del arreglo: ");
    scanf("%d", &longitud);

    if (longitud <= 0) {
        printf("La longitud del arreglo debe ser mayor que cero.\n");
    }

    int arreglo[longitud];

    printf("Ingrese %d elementos del arreglo:\n", longitud);
    for (i = 0; i < longitud; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }

    float promedio;
    int maximo, minimo;

    if (longitud > 0) {
        maximo = minimo = arreglo[0];
        promedio = arreglo[0];
    }

    for (
	
	i = 1; i < longitud; i++) {
        promedio += arreglo[i];

        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }

        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }

    promedio /= longitud;

    printf("Promedio: %.2f\n", promedio);
    printf("Valor Maximo: %d\n", maximo);
    printf("Valor Minimo: %d\n", minimo);

	
} 
void indice()
{
	int i;
	int arreglo[] = {12, 5, 23, 8, 19, 3, 41};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    int numeroBuscado1 = 0;
    int numeroBuscado2 = 0;
    printf("Ahora tienes que ingresar 2 valores para saber si existen dentro de un arreglo \n");
	printf("ingresa un valor para saber si esta dentro del arreglo\n");
	scanf("%d", &numeroBuscado1);
	printf("\ningresa un segundo valor para saber si esta dentro del arreglo\n");
	scanf("%d", &numeroBuscado2);
    int indice1 = -1;
    int indice2 = -1;

    for (i = 0; i < longitud; i++) {
        if (arreglo[i] == numeroBuscado1) {
            indice1 = i;
        }
    }

    for (i = 0; i < longitud; i++) {
        if (arreglo[i] == numeroBuscado2) {
            indice2 = i;
        }
    }

    if (indice1 != -1) {
        printf("El numero %d se encuentra en el indice %d del arreglo.\n", numeroBuscado1, indice1);
    } else {
        printf("El numero %d no se encuentra en el arreglo.\n", numeroBuscado1);
    }

    if (indice2 != -1) {
        printf("El numero %d se encuentra en el indice %d del arreglo.\n", numeroBuscado2, indice2);
    } else {
        printf("El numero %d no se encuentra en el arreglo.\n", numeroBuscado2);
    }
}

void valoresduplicados()
{
	int i, j;
	int longitud;

    
    printf("Ingrese la longitud del arreglo: ");
    scanf("%d", &longitud);

    if (longitud <= 0) {
        printf("La longitud del arreglo debe ser mayor que cero.\n");
         
    }

    int arreglo[longitud];

    printf("Ingrese %d elementos del arreglo:\n", longitud);
    for (i = 0; i < longitud; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }

    int nuevoLongitud = 0; 

    for (i = 0; i < longitud; i++) {
        int esDuplicado = 0; 

        for (j = 0; j < nuevoLongitud; j++) {
            if (arreglo[i] == arreglo[j]) {
                esDuplicado = 1;
            }
        }


        if (!esDuplicado) {
            arreglo[nuevoLongitud] = arreglo[i];
            nuevoLongitud++;
        }
    }

    // Mostrar el arreglo sin duplicados
    printf("Arreglo sin duplicados: ");
    for (i = 0; i < nuevoLongitud; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\nNuevo tamanio del arreglo: %d\n", nuevoLongitud);
}
int main() 
{
	parOimpar();
	printf("ingresa un valor para saber si es primo \n");
	primos();
	printf("ahora ingresa valores para sacar el promedio de un arreglo\n");
	promedio();
	indice();
	printf("ingresa valores para saber si son duplicados");
	valoresduplicados();
	
	return 0;
}
