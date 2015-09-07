/* 
 * File:   main.c
 * Author: diego
 *
 * Created on September 6, 2015, 5:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define FILA 8
#define COLUMNA 8

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

	int laberinto[FILA][COLUMNA];
	int i=0, j=0, ch, cont;
	char as = '*', opc, jugarn;

	for(i=0;i<FILA;i++)
	{
		for(j=0;j<COLUMNA;j++)
		{
			laberinto[i][j] = 0;
		}
	}

	i = j = 0;

	FILE *arch;

	//llena la matriz apartir del archivo
	arch = fopen("archivo.txt", "r");

	while(!feof(arch)) {
		ch=(int)fgetc(arch);
		if(ch!='\n') {
			laberinto[i][j]=ch;
			j++;
		} else {
			j=0;
			i++;
		}
	}
	fclose(arch);

	//imprime la matriz
	for(i=0; i<FILA; i++) {
		for(j=0; j<COLUMNA; j++) {
			printf("%c", laberinto[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}