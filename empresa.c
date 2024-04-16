#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5
#define COLUMNA 12

void CargarMatriz(int matriz[FILA][COLUMNA]);
void MostrarMatriz(int matriz[FILA][COLUMNA]);

int main()
{
    int matriz[FILA][COLUMNA];
    srand(time(NULL));
    CargarMatriz(matriz);
    MostrarMatriz(matriz);
    return 0;
}

void CargarMatriz(int matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;    
        }
    }
}

void MostrarMatriz(int matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}