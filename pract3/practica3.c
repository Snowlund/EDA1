#include <stdio.h>
#include <string.h>

#define MAX 5

struct pelicula {
    char nombre[20];
    char genero[20];
    int anio;
    int numDirectores;
    char directores[2][20];
};

int main() {
    struct pelicula videoteca[MAX];
    int numPeliculas;

    printf("¿Cuántas películas vas a registrar (máx %d)? ", MAX);
    scanf("%d", &numPeliculas);
    getchar(); // limpiar buffer

    // Validación simple
    if (numPeliculas <= 0 || numPeliculas > MAX) {
        printf("Número inválido de películas.\n");
        return 1;
    }

    for (int i = 0; i < numPeliculas; i++) {
        printf("\nPelícula #%d\n", i + 1);

        printf("Nombre: ");
        fgets(videoteca[i].nombre, 20, stdin);
        videoteca[i].nombre[strcspn(videoteca[i].nombre, "\n")] = '\0';

        printf("Género: ");
        fgets(videoteca[i].genero, 20, stdin);
        videoteca[i].genero[strcspn(videoteca[i].genero, "\n")] = '\0';

        printf("Año: ");
        scanf("%d", &videoteca[i].anio);
        getchar();

        printf("Número de directores (máx 2): ");
        scanf("%d", &videoteca[i].numDirectores);
        getchar();

        if (videoteca[i].numDirectores <= 0 || videoteca[i].numDirectores > 2) {
            printf("Número inválido de directores.\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director #%d: ", j + 1);
            fgets(videoteca[i].directores[j], 20, stdin);
            videoteca[i].directores[j][strcspn(videoteca[i].directores[j], "\n")] = '\0';
        }
    }

    // Imprimir en orden inverso de entrada
    printf("\nPelículas en orden inverso:\n");
    for (int i = numPeliculas - 1; i >= 0; i--) {
        printf("Nombre: %s | Género: %s | Año: %d\n", videoteca[i].nombre, videoteca[i].genero, videoteca[i].anio);
    }

    // Contador por género
    char generoBuscado[20];
    printf("\n¿Género a contar? ");
    fgets(generoBuscado, 20, stdin);
    generoBuscado[strcspn(generoBuscado, "\n")] = '\0';

    int contador = 0;
    for (int i = 0; i < numPeliculas; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }
    printf("Hay %d películas del género '%s'.\n", contador, generoBuscado);

    // Búsqueda por nombre
    char nombreBuscado[20];
    printf("\n¿Nombre de película a buscar? ");
    fgets(nombreBuscado, 20, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    int encontrada = 0;
    for (int i = 0; i < numPeliculas; i++) {
        if (strcmp(videoteca[i].nombre, nombreBuscado) == 0) {
            printf("Película encontrada: %s (%d), Género: %s\n", videoteca[i].nombre, videoteca[i].anio, videoteca[i].genero);
            encontrada = 1;
            break;
        }
    }
    if (!encontrada) {
        printf("Película no encontrada.\n");
    }

    return 0;
}
