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



int main() {
    
    printf("      hola \n \n");
    generarMatriz();
    leerArchivo();
    imprimirMatriz();
    born();

    return EXIT_SUCCESS;
}
