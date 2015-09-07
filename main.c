/* 
 * File:   main.c
 * Author: diego
 *
 * Created on September 6, 2015, 5:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "hilo.h"
#include "matriz.h"
#include "archivo.h"



int main() {
    int misargs[2];
    misargs[0] = 0;
    misargs[1] = 0;
    printf("      hola \n \n");
    generarMatriz();
    leerArchivo();
    imprimirMatriz();
    born((void*) misargs);

    return EXIT_SUCCESS;
}
