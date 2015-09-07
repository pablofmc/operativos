/* 
 * File:   variables.h
 * Author: diego
 *
 * Created on September 7, 2015, 1:19 AM
 */

#ifndef VARIABLES_H
#define	VARIABLES_H
#define FILA 8
#define COLUMNA 8
#include "estructura.h"
#include <stdio.h>

int i, j, ch, cont;
char as, opc, jugarn;
   
FILE *arch;

struct campo laberinto[FILA][COLUMNA];

#endif	/* VARIABLES_H */

