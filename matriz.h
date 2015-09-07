/* 
 * File:   matriz.h
 * Author: diego
 *
 * Created on September 7, 2015, 12:54 AM
 */

#include "variables.h"
#ifndef MATRIZ_H
#define	MATRIZ_H


void generarMatriz() {
    for(i=0;i<FILA;i++)
    {
            for(j=0;j<COLUMNA;j++)
            {
                    laberinto[i][j] = 0;
            }
    }

    i = j = 0;
}

void imprimirMatriz() {
    //imprime la matriz
    for(i=0; i<FILA; i++) {
            for(j=0; j<COLUMNA; j++) {
                    printf("%c", laberinto[i][j]);
                    printf(" ");
            }
            printf("\n");
    }
}


#endif	/* MATRIZ_H */

