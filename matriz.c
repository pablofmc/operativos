#include "matriz.h"

void generarMatriz() {
    for(i=0;i<FILA;i++)
    {
            for(j=0;j<COLUMNA;j++)
            {

                    laberinto[i][j].valor = '0';
            }
    }

    i = j = 0;
}

void imprimirMatriz() {
    //imprime la matriz
    for(i=0; i<FILA; i++) {
            for(j=0; j<COLUMNA; j++) {

                    printf("%c", laberinto[i][j].valor);
                    printf(" ");
            }
            printf("\n");
    }
    printf("-------------------------------\n");
}
