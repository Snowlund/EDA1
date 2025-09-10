#include <stdio.h>

int main(void)
{
    int n;
    int a[100];
    int suma = 0;
    int resta;
    int min, max;
    int posmin = 0, posmax = 0;
    float promedio = 0.0;

    printf("Ingresa una cantidad max de 100: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    printf("Ingresa %d numeros\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    min = max = a[0];
    resta = a[0];
    //sumar, restar, encontrar min y max
    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (i > 0) resta -= a[i];
        if (a[i] < min) {
            min = a[i];
            posmin = i;
        }
        if (a[i] > max) {
            max = a[i];
            posmax = i;
        }
    }

    promedio = (float)suma / n;

    // invertir el arreglo
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("Arreglo invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("La suma es: %d\n", suma);
    printf("La resta es: %d\n", resta);
    printf("El promedio es: %.2f\n", promedio);
    printf("El numero minimo es: %d, en la posicion: %d\n", min, posmin);
    printf("El numero maximo es: %d, en la posicion: %d\n", max, posmax);

    return 0;
}
