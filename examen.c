#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, adicionales; // Número inicial de estudiantes, contador y adicionales
    float *calificaciones = NULL;
    float suma = 0.0, promedio = 0.0;

    //  Pedimos al usuario cuántos estudiantes desea registrar inicialmente
    printf("--¿Cuántos estudiantes deseas registrar--? ");
    scanf("%d", &n);

    //  Reservamos memoria dinamica con malloc
    calificaciones = (float *)malloc(n * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    //  Imprimir las calificaciones y calcular el promedio inicial
    for (i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Preguntar si desea agregar más estudiantes
    printf("-.-¿Deseas agregar más estudiantes? (0 para no): ");
    scanf("%d", &adicionales);

    if (adicionales > 0) {
        int nuevo_tamano = n + adicionales;

        //  Usamos realloc() para ampliar el tamaño del arreglo
        float *temp = (float *)realloc(calificaciones, nuevo_tamano * sizeof(float));
        if (temp == NULL) {
            printf("Error al reasignar memoria.\n");
            free(calificaciones);
            return 1;
        }
        calificaciones = temp;

        // Imprimos nuevas calificaciones y recalculamos el promedio
        for (i = n; i < nuevo_tamano; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        promedio = suma / nuevo_tamano;
        n = nuevo_tamano;
    }

    // Se muestran todas las calificaciones y el promedio final
    printf("=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }
    printf("Promedio general: %.2f\n", promedio);

     //Liberar la memoria utilizada
    free(calificaciones);
    printf("Memoria liberada correctamente.\n");

    return 0;
}