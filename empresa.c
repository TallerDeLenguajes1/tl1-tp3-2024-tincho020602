#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5
#define COLUMNA 12

void CargarMatriz(float matriz[FILA][COLUMNA]);
void MostrarMatriz(float matriz[FILA][COLUMNA]);
void PromedioGanancia(float matriz[FILA][COLUMNA]);

int main()
{
    float matriz[FILA][COLUMNA];
    srand(time(NULL));
    CargarMatriz(matriz);
    MostrarMatriz(matriz);
    PromedioGanancia(matriz);
    return 0;
}

void CargarMatriz(float matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;    
        }
    }
}

void MostrarMatriz(float matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%2.f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void PromedioGanancia(float matriz[FILA][COLUMNA])
{
    float promedio;
    float ganancia=0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            ganancia= matriz[i][j] + ganancia;
            
        }
            promedio= ganancia / 12;
            printf("\nEl promedio en el anio %d es de %.2f",i+1,promedio);
    }
}