#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char nombre[100];
	int edad = 0;
	
	printf("Ingresa tu nombre: ");
	scanf("%s", nombre);
	printf("Ahora ingresa tu edad: ");
	scanf("%d", & edad);
	printf("Hola %s, usted tiene %d anios de edad", nombre, edad);
	
	return 0;
}
