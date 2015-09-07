/* 
 * File:   main.c
 * Author: diego
 *
 * Created on September 6, 2015, 5:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matriz.h"
#include "archivo.h"

void *mifuncion(void *arg) {
    int *argu;
    printf("Hilo hijo ejecutando...\n"); fflush(stdout);
    argu = (int *)arg;
    printf("Hilo hijo: arg.1=%d arg.2=%d.\n", argu[0], argu[1]);
    printf("Hilo hijo finalizado.\n"); fflush(stdout);
    pthread_exit(NULL);
}

int main() {
    printf("      hola \n \n");

    pthread_t tid;
    int misargs[2];

    void *mifuncion(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    misargs[0] = -5;
    misargs[1] =-6;

    pthread_create(&tid, NULL, mifuncion, (void*) misargs);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    pthread_join(tid, NULL);
    fflush(stdout);

    generarMatriz();
    leerArchivo();
    imprimirMatriz();

    return EXIT_SUCCESS;
}