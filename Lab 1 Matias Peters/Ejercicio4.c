#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int x = 0;
	
	printf("Ingresa un anio para saber si es bisiesto: ");
	scanf("%d", & x);
	
	if((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0 && x % 100 == 0))
	{
		printf("El anio es bisiesto");
	}else{
		printf("El anio no es bisiesto");
	}
	return 0;
}
