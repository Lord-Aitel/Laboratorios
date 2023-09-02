#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int x, y;
	
	printf("Ingrese 2 valores para comenzar\n");
	printf("Valor nro1: \n");
	scanf("%d", & x);
	printf("\nValor nro2: \n");
	scanf("%d", & y);
	
	int suma = x + y;
    int resta = x - y;
    int multiplicacion = x * y;
    int division = x / y;
    
	return 0;
}
