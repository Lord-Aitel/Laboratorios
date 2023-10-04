#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar la información de una compañía
struct Compania {
    char nombre[100];       // Nombre de la compañía (asumimos un máximo de 100 caracteres)
    int empleados[5];       // Cantidad de empleados para cada año (2018-2022)
};

// Función para agregar datos de empleados a la estructura
void add_employee_data(struct Compania *compania, int year, int numEmployees) {
    // Verificar si el año está dentro del rango válido (2018-2022)
    if (year >= 2018 && year <= 2022) {
        // Actualizar la cantidad de empleados para el año correspondiente en el arreglo
        compania->empleados[year - 2018] = numEmployees;
    } else {
        printf("Año no válido. El año debe estar entre 2018 y 2022.\n");
    }
}

// Función para eliminar datos de empleados de un año específico
void delete_employee_data(struct Compania *compania, int year) {
    // Verificar si el año está dentro del rango válido (2018-2022)
    if (year >= 2018 && year <= 2022) {
        // Eliminar la cantidad de empleados para el año correspondiente
        compania->empleados[year - 2018] = 0;
    } else {
        printf("Año no válido. El año debe estar entre 2018 y 2022.\n");
    }
}

// Función para calcular el promedio de empleados de la compañía
float calculate_average_employees(const struct Compania *compania) {
    int totalEmpleados = 0;
    int i;
    // Calcular la suma total de empleados para los años 2018-2022
    for (i = 0; i < 5; i++) {
        totalEmpleados += compania->empleados[i];
    }
    
    // Calcular el promedio
    return (float)totalEmpleados / 5;
}

// Función para calcular el promedio de empleados de un año en todas las compañías
float general_average_employees(const struct Compania companias[], int numCompanias, int year) {
    int totalEmpleados = 0;
    int totalCompanias = 0;
    int i;
    // Recorrer todas las compañías
    for (i = 0; i < numCompanias; i++) {
        // Verificar si el año está dentro del rango válido (2018-2022)
        if (year >= 2018 && year <= 2022) {
            totalEmpleados += companias[i].empleados[year - 2018];
            totalCompanias++;
        } else {
            printf("Año no válido. El año debe estar entre 2018 y 2022.\n");
            return -1.0f; // Valor de retorno inválido para indicar un error
        }
    }
    
    // Calcular el promedio
    if (totalCompanias > 0) {
        return (float)totalEmpleados / totalCompanias;
    } else {
        return 0.0f; // Si no hay compañías con datos válidos para ese año, el promedio es 0
    }
}

int main(int argc, char *argv[]) {
    int i;
    int j;
    FILE *archivo;
    char linea[100];
	archivo = fopen("companiasprueba.txt", "r");

    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer la información de las compañías desde el archivo
    int numCompanias;
    fscanf(archivo, "%d", &numCompanias);
    struct Compania *companias = malloc(numCompanias * sizeof(struct Compania));
	
    for (i = 0; i < numCompanias; i++) {
        fscanf(archivo, "%s", companias[i].nombre);
        for (j = 0; j < 5; j++) {
            fscanf(archivo, "%d", &companias[i].empleados[j]);
        }
    }

    // Calcular el promedio de empleados para un año específico (por ejemplo, 2020)
    int yearToCalculate = 2020;
    float promedioEmpleados = general_average_employees(companias, numCompanias, yearToCalculate);
    
    // Mostrar el promedio
    if (promedioEmpleados != -1.0f) {
        printf("Promedio de empleados en todas las compañías para el año %d: %.2f\n", yearToCalculate, promedioEmpleados);
    }
    
    for(i = 0; i < numCompanias; i++)
    {
    	printf("%d", companias[i].nombre);
	}

    // Liberar la memoria y cerrar el archivo
    free(companias);
    fclose(archivo);

    return 0;
}
