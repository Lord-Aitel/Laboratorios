#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int numeroDeLista;
    int promedioFinal;
};

struct Libro {
	char titulo[50]; 
	char autor[50];
	char isbn[13];
	int precio;
};

struct Producto {
    char nombre[50];
    int ID;
    float precio;
    int cantidad;
};

void ejer12()
{
	struct Estudiante lista_alumnos[5];
	
	strcpy(lista_alumnos[0].nombre,("Queso"));
	lista_alumnos[0].promedioFinal = 89;
		
	strcpy(lista_alumnos[1].nombre,("Pan"));
	lista_alumnos[1].promedioFinal = 65;
	
	strcpy(lista_alumnos[2].nombre,("Leche"));
	lista_alumnos[2].promedioFinal = 93;
	
	strcpy(lista_alumnos[3].nombre,("Manjar"));
	lista_alumnos[3].promedioFinal = 68;
	
	strcpy(lista_alumnos[4].nombre,("Cilantro"));
	lista_alumnos[4].promedioFinal = 72;

	int i;
    int promedioMayor = 0;
    int indice = 0;
    int arreglo_cuadro_honor[5];
    
    for ( i = 0 ; i < 5 ; i++){
        arreglo_cuadro_honor[i] = -1;
    }
    
    for ( i = 0 ; i < 5 ; i++){
        if ( promedioMayor < lista_alumnos[i].promedioFinal){
            promedioMayor = lista_alumnos[i].promedioFinal;
            indice = i;
        }
        printf("El promedio de %s corresponde a %d\n",lista_alumnos[i].nombre,lista_alumnos[i].promedioFinal);
    }
    
    int contador_cuadro_honor = 0;
    for ( i = 0 ; i < 5 ; i++){
        if ( promedioMayor == lista_alumnos[i].promedioFinal){
            arreglo_cuadro_honor[contador_cuadro_honor] = i;
            contador_cuadro_honor = contador_cuadro_honor + 1;
        }
    }
    printf("El promedio mas alto corresponde a: %d\n",promedioMayor);
	printf("Existe %d estudiantes en el cuadro de honor\n",contador_cuadro_honor);
    for ( i = 0 ; i < contador_cuadro_honor ; i++){
        if (arreglo_cuadro_honor[i] != -1 )
        printf("%s\n",lista_alumnos[arreglo_cuadro_honor[i]].nombre);
    }
}

void ejer34()
{
	struct Libro lista_libros[5];
	
	strcpy(lista_libros[0].titulo,("tintin"));
	strcpy(lista_libros[0].autor,("Herge"));
	strcpy(lista_libros[0].isbn,("1-4089-9352-12831"));
	lista_libros[0].precio = 60;
	
	strcpy(lista_libros[1].titulo,("El senior de los anillos"));
	strcpy(lista_libros[1].autor,("J. R. R. Tolkien"));
	strcpy(lista_libros[1].isbn,("1-7889-6352-70000"));
	lista_libros[1].precio = 70;
	
	strcpy(lista_libros[2].titulo,("Harry Potter"));
	strcpy(lista_libros[2].autor,("J. K. Rowling"));
	strcpy(lista_libros[2].isbn,("5-8439-0322-58030"));
	lista_libros[2].precio = 50;
	
	strcpy(lista_libros[3].titulo,("La metamorfosis"));
	strcpy(lista_libros[3].autor,("Franz Kafka"));
	strcpy(lista_libros[3].isbn,("9-3856-6352-20370"));
	lista_libros[3].precio = 2;
	
	strcpy(lista_libros[4].titulo,("Metro 2033"));
	strcpy(lista_libros[4].autor,("Dmitri Glujovski"));
	strcpy(lista_libros[4].isbn,("0-4881-8322-12063"));
	lista_libros[4].precio = 100;
	
	int i;
    int precioMayor = 0;
    int indice = 0;
    int librostop[5]; 
    
    for ( i = 0 ; i < 5 ; i++){
        librostop[i] = -1;
    }
    
    for ( i = 0 ; i < 5 ; i++){
        if (precioMayor < lista_libros[i].precio){
            precioMayor = lista_libros[i].precio;
            indice = i;
        }
        printf("El precio del libro de %s es: %d , su autor es: %s y su ISBM es: %s\n",lista_libros[i].titulo,lista_libros[i].precio,lista_libros[i].autor,lista_libros[i].isbn);
    }
    
    int contadorlibrostop = 0;
    for ( i = 0 ; i < 5 ; i++){
        if (precioMayor == lista_libros[i].precio){
            librostop[contadorlibrostop] = i;
            contadorlibrostop = contadorlibrostop + 1;
        }
    }
    printf("El precio mas alto corresponde a: %d\n",precioMayor);
	printf("el/los libro(s) mas caro(s) son/es: ",contadorlibrostop);
    for ( i = 0 ; i < contadorlibrostop ; i++){
        if (librostop[i] != -1 )
        printf("%s\n",lista_libros[librostop[i]].titulo);
    }
}

void ejer5 ()
{
	struct Producto productos[50];
    int contadorProductos = 0;
    int opcion;
	int i;
	do {
        printf("\nMenú:\n");
        printf("1. Agregar un producto\n");
        printf("2. Mostrar el producto de mayor valor\n");
        printf("3. Mostrar el stock actual de productos\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                if (contadorProductos < 50) {
                    struct Producto nuevoProducto;
                    printf("Ingrese el nombre del producto: ");
                    scanf("%s", nuevoProducto.nombre);
                    printf("Ingrese el ID del producto: ");
                    scanf("%d", &nuevoProducto.ID);
                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &nuevoProducto.precio);
                    printf("Ingrese la cantidad en stock: ");
                    scanf("%d", &nuevoProducto.cantidad);

                    productos[contadorProductos] = nuevoProducto;
                    contadorProductos++;
                    printf("Producto agregado correctamente.\n");
                } else {
                    printf("No se pueden agregar más productos. Límite alcanzado.\n");
                }
                break;
            }
            case 2: {
                if (contadorProductos == 0) {
                    printf("No hay productos en la lista.\n");
                } else {
                    int indiceMax = 0;
                    float maxValor = productos[0].precio * productos[0].cantidad;

                    for (i = 1; i < contadorProductos; i++) {
                        float valorActual = productos[i].precio * productos[i].cantidad;
                        if (valorActual > maxValor) {
                            maxValor = valorActual;
                            indiceMax = i;
                        }
                    }

                    printf("Producto de mayor valor:\n");
                    printf("Nombre: %s\n", productos[indiceMax].nombre);
                    printf("ID: %d\n", productos[indiceMax].ID);
                    printf("Precio: %.2f\n", productos[indiceMax].precio);
                    printf("Cantidad en stock: %d\n", productos[indiceMax].cantidad);
                    printf("Valor total: %.2f\n", maxValor);
                }
                break;
            }
            case 3: {
                printf("Stock actual de productos:\n");
                for ( i = 0; i < contadorProductos; i++) {
                    printf("Nombre: %s\n", productos[i].nombre);
                    printf("ID: %d\n", productos[i].ID);
                    printf("Precio: %.2f\n", productos[i].precio);
                    printf("Cantidad en stock: %d\n", productos[i].cantidad);
                    printf("======================================\n");
                }
                break;
            }
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);
}

int main() {
    int opcion;

    do {
        // Mostrar el menú
        printf("\nMenu:\n");
        printf("1. Ejecutar ejer12()\n");
        printf("2. Ejecutar ejer34()\n");
        printf("3. Ejecutar ejer5()\n");
        printf("4. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
            case 1:
                printf("Ejecutando ejer12()...\n");
                ejer12();
                break;
            case 2:
                printf("Ejecutando ejer34()...\n");
                ejer34();
                break;
            case 3:
                printf("Ejecutando ejer5()...\n");
                ejer5();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
