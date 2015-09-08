
#include <pthread.h>

#include "estructura.h"
#include "variables.h"
#include "hilo.h"

void born(){
    int misargs[4];
    misargs[0] = 0; //x
    misargs[1] = 0; //y
    misargs[2] = -1; // origen
    misargs[3] = -1; // sgt
    
    pthread_t tid;

    void *routine(void *misargs);

    printf("Creando hilo...\n");
    fflush(stdout);
    
    pthread_create(&tid, NULL, routine, (void*) misargs);

    printf("Hilo creado. Esperando su finalizacion..\n");
    fflush(stdout);
    
    pthread_join(tid, NULL);
    
    /*
    int var = 0;
    while(var < 100) {
        pthread_mutex_lock (&mutexBuffer);

        imprimirMatriz();
        
        pthread_mutex_unlock (&mutexBuffer);
        
        var++;
    }*/
}

void *move(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    //ver si hay más caminas
    ways((void *)argu);
    
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
    
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]][argu[1]].derecha = true;
    } else {
        argu[2] = 3; // origen
        argu[3] = 2; // s
    
        laberinto[argu[0]][argu[1]].valor = '#';
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
        pthread_mutex_lock (&mutexBuffer);
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]][argu[1]].abajo = true;
        pthread_mutex_unlock (&mutexBuffer);
    } else {
        argu[2] = 1; // origen
        argu[3] = 0; // s
        pthread_mutex_lock (&mutexBuffer);
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]][argu[1]].arriba = true;
        pthread_mutex_lock (&mutexBuffer);
    }
    pthread_mutex_lock (&mutexBuffer);
    imprimirMatriz();
    pthread_mutex_unlock (&mutexBuffer);
 
    //move((void*) argu);
}

void ways(void *arg) {
    int *argu;
    argu = (int *)arg;
    if (argu[2] == 0 && argu[3] == 1 || argu[2] == 1 && argu[3] == 0){
        if (laberinto[argu[0]-1][argu[1]].valor != '*' && argu[0]-1 >= 0) {
            if(laberinto[argu[0]][argu[1]].izquierda == false) {
                crearHijoIzquierda((void*) argu);
            }
        } else if (laberinto[argu[0]+1][argu[1]].valor == '*' && argu[0]+1 < FILA) {
            if(laberinto[argu[0]][argu[1]].derecha == false) {
                crearHijoDerecha((void*) argu);
            }
        }
    } else if (argu[2] == 2 && argu[3] == 3 || argu[2] == 3 && argu[3] == 2){
        if (laberinto[argu[0]][argu[1]-1].valor != '*' && argu[1]-1 >= 0) {
            if(laberinto[argu[0]][argu[1]].arriba == false) {
                crearHijoArriba((void*) argu);
            }
        } else if (laberinto[argu[0]][argu[1]+1].valor == '*' && argu[1]+1 < COLUMNA) {
            if(laberinto[argu[0]][argu[1]].abajo == false) {
                crearHijoAbajo((void*) argu);
            }
        }
    }
}

void die(){
    printf("Hilo hijo finalizado.\n"); fflush(stdout);
    pthread_exit(NULL);
}


void *routine(void *arg) {
    int *argu;
    argu = (int*) arg;
    
    pthread_mutex_lock (&mutexBuffer);
    laberinto[0][0].valor = '#';
    printf("kajhsk: %c",laberinto[0][1].valor);
    if (laberinto[1][0].valor != '*') {
        argu[0] = 0;
        argu[1] = 1;
        argu[2] = 2;
        argu[3] = 3;
        laberinto[0][0].derecha = true;  
        laberinto[0][1].valor = '#';
        
        /* Se desbloquea el mutex */
        pthread_mutex_unlock (&mutexBuffer);
        //crearHijoDerecha((void *)argu);    
    }
    /* Se espera y se bloquea el mutex */
    pthread_mutex_lock (&mutexBuffer);
    if (laberinto[1][0].valor != '*') {
        argu[0] = 1;
        argu[1] = 0;
        argu[2] = 0;
        argu[3] = 1;
        laberinto[0][0].abajo = true;   
        laberinto[0][1].valor = '#';
        /* Se desbloquea el mutex */
        pthread_mutex_unlock (&mutexBuffer);
        //movey((void *)argu, +1);       
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
    
    laberinto[argu[0]][argu[1]].valor = '#';
    laberinto[argu[0]][argu[1]].arriba = true;
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo arriba...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);
    
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
    
    laberinto[argu[0]][argu[1]].valor = '#';
    laberinto[argu[0]][argu[1]].derecha = true;
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo derecha...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);

    fflush(stdout);
}

void crearHijoIzquierda(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 3; // origen
    misargs[3] = 2; // sgt
    
    laberinto[argu[0]][argu[1]].valor = '#';
    laberinto[argu[0]][argu[1]].izquierda = true;
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo izquierda...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);
    
    fflush(stdout);
}

void crearHijoAbajo(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 0; // origen
    misargs[3] = 1; // s
    
    laberinto[argu[0]][argu[1]].valor = '#';
    laberinto[argu[0]][argu[1]].abajo = true;
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo abajo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);
    
    fflush(stdout);
}