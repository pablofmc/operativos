#include "hilo.h"
#include <pthread.h>

void born(int posX, int posY){
    pthread_t tid;
    int misargs[2];

    void *routine(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    misargs[0] = -5;
    misargs[1] =-6;

    pthread_create(&tid, NULL, routine, (void*) misargs);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    pthread_join(tid, NULL);
    fflush(stdout);
    die();
}

void move(int posX, int posY){
    
}

void evaluarMovimiento(int posX, int posY){
    
}

void die(){
    printf("Hilo hijo finalizado.\n"); fflush(stdout);
    pthread_exit(NULL);
}

void procreate(int posX, int posY){
    
}

void waymark(int posX, int posY){
    
}

void *routine(void *arg) {
	int *argu;
	printf("Hilo hijo ejecutando...\n"); fflush(stdout);
	argu = (int *)arg;
	printf("Hilo hijo: arg.1=%d arg.2=%d.\n", argu[0], argu[1]);
	printf("Hilo hijo finalizado.\n"); fflush(stdout);
	pthread_exit(NULL);
}