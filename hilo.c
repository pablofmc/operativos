#include <stdio.h>
#include <pthread.h>

#include "estructura.h"

void born(void *misargs){
    int misargs[4];
    misargs[0] = 0; //x
    misargs[1] = 0; //y
    misargs[2] = -1; // origen
    misargs[3] = -1; // sgt
    
    pthread_t tid;

    void *routine(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);
    
    pthread_create(&tid, NULL, routine, (void*) misargs);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    //pthread_join(tid, NULL);
    printf("kajshdkjads");
    fflush(stdout);
    //move((void*) misargs);
    die();
}

void *move(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    if (argu[2] == 2 && argu[3] == 3 && laberinto[argu[0]][argu[1]].derecha == false) {        
        if(laberinto[argu[0]+1][argu[1]].valor != '*') {
            movex((void*) argu, +1);
        } else {
            die();
        }        
    } else if (argu[2] == 3 && argu[3] == 2 && laberinto[argu[0]][argu[1]].izquierda == false) {        
        if(laberinto[argu[0]-1][argu[1]].valor != '*') {
            movex((void*) argu, -1);
        } else {
            die();
        }
    } else if (argu[2] == 0 && argu[3] == 1 && laberinto[argu[0]][argu[1]].abajo == false) {        
        if(laberinto[argu[0]][argu[1] + 1].valor != '*') {
            movey((void*) argu, +1);
        } else {
            die();
        }
    } else if (argu[2] == 1 && argu[3] == 0 && laberinto[argu[0]][argu[1]].arriba == false) {        
        if(laberinto[argu[0]][argu[1] - 1].valor != '*') {
            movey((void*) argu, -1);
        } else {
            die();
        }
    }
}

void movex(void *arg, int v){
    int *argu;
    argu = (int *)arg;
    argu[0] = argu[0] + v;
    
    if (v == 1) {
        argu[2] = 2; // origen
        argu[3] = 3; // s
    
        laberinto[argu[0]][argu[1]].valor = "#";
        laberinto[argu[0]][argu[1]].derecha = true;
    } else {
        argu[2] = 3; // origen
        argu[3] = 2; // s
    
        laberinto[argu[0]][argu[1]].valor = "#";
        laberinto[argu[0]][argu[1]].izquierda = true;;
    }
    
    move((void*) argu);
}

void movey(void *arg, int v){
    int *argu;
    argu = (int *)arg;
    argu[0] = argu[0] + v;
    
    if (v == 1) {
        argu[2] = 0; // origen
        argu[3] = 1; // s
    
        laberinto[argu[0]][argu[1]].valor = "#";
        laberinto[argu[0]][argu[1]].abajo = true;
    } else {
        argu[2] = 1; // origen
        argu[3] = 0; // s
    
        laberinto[argu[0]][argu[1]].valor = "#";
        laberinto[argu[0]][argu[1]].arriba = true;;
    }
    
    move((void*) argu);
}

void Ways(void *arg) {
    int *argu;
    argu = (int *)arg;
    
}

void die(){
    printf("Hilo hijo finalizado.\n"); fflush(stdout);
    pthread_exit(NULL);
}


void evaluateProcreate(void *arg){
   
}

void *routine(void *arg) {
    int *argu;
    argu = (int*) arg;
    if (laberinto[1][0].valor != '*') {
        argu[0] = 1;
        argu[1] = 0;
        argu[2] = 2;
        argu[3] = 3;
        laberinto[0][0].derecha = true;
        laberinto[0][1].derecha = true;   
        laberinto[0][1].valor = '#';
        crearHijoDerecha((void *)argu);
    }
    if (laberinto[0][1].valor != '*') {
        argu[0] = 0;
        argu[1] = 1;
        argu[2] = 0;
        argu[3] = 1;
        laberinto[0][0].abajo = true;
        laberinto[0][1].abajo = true;   
        laberinto[0][1].valor = '#'
        movey((void *)argu);       
    }
}

void crearHijoArriba(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 1; // origen
    misargs[3] = 0; // s
    
    laberinto[][];
    pthread_t tid;

    void *move(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) arg);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    //pthread_join(tid, NULL);
    printf("kajshdkjads");
    fflush(stdout);
}


void crearHijoDerecha(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 2; // origen
    misargs[3] = 3; // s
    
    laberinto[argu[0]][argu[1]].valor = "#";
    laberinto[argu[0]][argu[1]].derecha = true;
    
    pthread_t tid;

    void *move(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) arg);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    //pthread_join(tid, NULL);
    printf("kajshdkjads");
    fflush(stdout);
}

void crearHijoDerecha(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]+1; //y
    misargs[2] = 2; // origen
    misargs[3] = 3; // s
    
    laberinto[argu[0]][argu[1]].valor = "#";
    laberinto[argu[0]][argu[1]].derecha = true;
    
    pthread_t tid;

    void *move(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) arg);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    //pthread_join(tid, NULL);
    printf("kajshdkjads");
    fflush(stdout);
}

void crearHijoDerecha(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]+1; //y
    misargs[2] = 2; // origen
    misargs[3] = 3; // s
    
    laberinto[argu[0]][argu[1]].valor = "#";
    laberinto[argu[0]][argu[1]].derecha = true;
    
    pthread_t tid;

    void *move(void *arg);

    printf("Creando hilo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) arg);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);

    //pthread_join(tid, NULL);
    printf("kajshdkjads");
    fflush(stdout);
}