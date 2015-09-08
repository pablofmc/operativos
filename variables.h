

#ifndef VARIABLES_H
#define	VARIABLES_H
#define FILA 8
#define COLUMNA 8
#include "estructura.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* mutex para sincronizar el acceso a buffer */
pthread_mutex_t mutexBuffer;

int i, j, ch, cont;
char as, opc, jugarn;
   
FILE *arch;

struct campo laberinto[FILA][COLUMNA];

#endif	/* VARIABLES_H */
