#include "hilo.h"
#include <pthread.h>

void born(void *misargs){
    pthread_t tid;

    void *routine(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, routine, (void*) misargs);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    pthread_join(tid, NULL);
    fflush(stdout);
    //move((void*) misargs);
    die();
}

void move(void *arg){
    int *argu;
    argu = (int *)arg;
    argu[0] = 0;
    argu[1] = 1;
    //evaluateProcreate(void *arg);
}

void evaluarMovimiento(void *arg){
    
}


void die(){
    printf("Hilo hijo finalizado.\n"); fflush(stdout);
    pthread_exit(NULL);
}


void evaluateProcreate(void *arg){
   
}

void waymark(int posX, int posY){
    
}

void *routine(void *arg) {
	int *argu;
	printf("Hilo hijo ejecutando...\n"); fflush(stdout);
	argu = (int *)arg;
	printf("Hilo hijo: arg.1=%d arg.2=%d.\n", argu[0], argu[1]);
	pthread_exit(NULL);
}
