
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
    pthread_mutex_lock(&mutexBuffer);
    imprimirMatriz();
    pthread_mutex_unlock(&mutexBuffer);
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
    char valor;
    
    //ver si hay más caminas
    ways((void *)argu);
    
    pthread_mutex_lock(&mutexBuffer);
    bool derecha = laberinto[argu[0]][argu[1]].derecha;
    bool izquierda = laberinto[argu[0]][argu[1]].izquierda;
    bool abajo = laberinto[argu[0]][argu[1]].abajo;
    bool arriba = laberinto[argu[0]][argu[1]].arriba;
    printf("SIIII %d %d \n", argu[0], argu[1]);
    printf("NOOO %d %d \n", argu[2], argu[3]);
    pthread_mutex_unlock(&mutexBuffer);
    
    if (argu[2] == 2 && argu[3] == 3 && derecha == false) {         
        pthread_mutex_lock(&mutexBuffer);
        valor = laberinto[argu[0]][argu[1]+1].valor;
        pthread_mutex_unlock(&mutexBuffer);
        if(valor != '*') {
            movex((void*) argu, +1);
        } else {
            die();
        }        
    } else if (argu[2] == 3 && argu[3] == 2 && izquierda == false) {        
        pthread_mutex_lock(&mutexBuffer);
        valor = laberinto[argu[0]][argu[1]-1].valor;
        pthread_mutex_unlock(&mutexBuffer);
        if(valor != '*') {
            movex((void*) argu, -1);
        } else {
            die();
        }
    } else if (argu[2] == 0 && argu[3] == 1 && abajo == false) {       
        pthread_mutex_lock(&mutexBuffer);
        valor = laberinto[argu[0]+1][argu[1]].valor;        
        pthread_mutex_unlock(&mutexBuffer);
        if(valor != '*') {
            movey((void*) argu, +1);
        } else {
            die();
        }
    } else if (argu[2] == 1 && argu[3] == 0 && arriba == false) { 
        
        pthread_mutex_lock(&mutexBuffer);
        valor = laberinto[argu[0]-1][argu[1]].valor;
        
        pthread_mutex_unlock(&mutexBuffer);
        if(valor != '*') {
            movey((void*) argu, -1);
        } else {
            die();
        }
    } else {
        die();
    }
}

void movex(void *arg, int v){
    int *argu;
    argu = (int *)arg;
    argu[1] = argu[1] + v;
    if (v == 1) {
        argu[2] = 2; // origen
        argu[3] = 3; // s
        pthread_mutex_lock (&mutexBuffer);
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]][argu[1]-1].derecha = true;        
        pthread_mutex_unlock (&mutexBuffer);
    } else {
        argu[2] = 3; // origen
        argu[3] = 2; // s
        pthread_mutex_lock (&mutexBuffer);
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]][argu[1]+1].derecha = true;
        pthread_mutex_unlock (&mutexBuffer);
    }
    pthread_mutex_lock (&mutexBuffer);
    imprimirMatriz(); 
    pthread_mutex_unlock (&mutexBuffer);
    
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
        laberinto[argu[0]-1][argu[1]].abajo = true;        
        pthread_mutex_unlock (&mutexBuffer);
    } else {
        argu[2] = 1; // origen
        argu[3] = 0; // s
        pthread_mutex_lock (&mutexBuffer);
        laberinto[argu[0]][argu[1]].valor = '#';
        laberinto[argu[0]+1][argu[1]].arriba = true;
        pthread_mutex_unlock (&mutexBuffer);
    }
    pthread_mutex_lock (&mutexBuffer);
    imprimirMatriz(); 
    pthread_mutex_unlock (&mutexBuffer);
    
    move((void*) argu);
}

void ways(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    if (argu[2] == 0 && argu[3] == 1 || argu[2] == 1 && argu[3] == 0){
        char sgtcol, antcol;
        bool izq, der;
        pthread_mutex_lock (&mutexBuffer);
        sgtcol = laberinto[argu[0]][argu[1]+1].valor;
        antcol = laberinto[argu[0]][argu[1]-1].valor;       
        izq = laberinto[argu[0]][argu[1]].izquierda;
        der = laberinto[argu[0]][argu[1]].derecha;
        pthread_mutex_unlock (&mutexBuffer);
        
        if (antcol != '*' && argu[1]-1 >= 0) {            
            if(izq == false) {
                crearHijoIzquierda((void*) argu);
            }
        }
        if (sgtcol != '*' && argu[1]+1 < COLUMNA) {           
            if(der == false) {  
                crearHijoDerecha((void*) argu);
            }            
        }
    } else if (argu[2] == 2 && argu[3] == 3 || argu[2] == 3 && argu[3] == 2){
        
        
        char sgtfila, antfila;
        bool arriba, abajo;
        pthread_mutex_lock (&mutexBuffer);
        sgtfila = laberinto[argu[0]+1][argu[1]].valor;
        antfila = laberinto[argu[0]-1][argu[1]].valor;
        arriba = laberinto[argu[0]][argu[1]].arriba;
        abajo = laberinto[argu[0]][argu[1]].abajo;
        pthread_mutex_unlock (&mutexBuffer);
        if (sgtfila == '*' && argu[0]+1 < FILA && antfila != '*' && argu[0]-1 >= 0) {
            if(abajo == false && arriba == false) {
                crearHijoArribaAbajo((void*) argu);
            }
        } else {
           if (antfila != '*' && argu[0]-1 >= 0) {
                if(arriba == false) {
                    crearHijoArriba((void*) argu);
                }
            } else {
               if (antfila != '*' && argu[0]-1 >= 0) {
                    if(arriba == false) {
                        crearHijoArriba((void*) argu);
                    }
                }
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
    int valor = laberinto[0][1].valor;
    laberinto[0][0].valor = '#';   
    pthread_mutex_unlock (&mutexBuffer);
    printf("Columna 2: %c \n",laberinto[0][1].valor);
    printf("Fila 2: %c \n",laberinto[1][0].valor);
    if (valor != '*') {
        argu[0] = 0;
        argu[1] = 1;
        argu[2] = 2;
        argu[3] = 3;
        pthread_mutex_lock (&mutexBuffer);
        laberinto[0][0].derecha = true;  
        laberinto[0][1].valor = '#'; 
        pthread_mutex_unlock (&mutexBuffer);
        crearHijoDerecha((void *)argu);    
    }
    pthread_mutex_lock (&mutexBuffer);
    valor = laberinto[1][0].valor;
    pthread_mutex_unlock (&mutexBuffer);
    if (valor != '*') {
        
        argu[0] = 1;
        argu[1] = 0;
        argu[2] = 0;
        argu[3] = 1;
        pthread_mutex_lock (&mutexBuffer);
        laberinto[0][0].abajo = true;   
        laberinto[1][0].valor = '#';
        imprimirMatriz();
        pthread_mutex_unlock (&mutexBuffer);           
        
        movey((void *)argu, +1);       
    }
    
    die();
   
}

void crearHijoArribaAbajo(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    pthread_t tid[2];
    // arriba ---------------------------------------------------------------
    int misargs[4];
    misargs[0] = argu[0]-1; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 1; // origen
    misargs[3] = 0; // s
    
    pthread_mutex_lock(&mutexBuffer);
    laberinto[misargs[0]][misargs[1]].valor = '#';
    laberinto[misargs[0]+1][misargs[1]].arriba = true;
    pthread_mutex_unlock(&mutexBuffer);
    
    

    void *move(void *misargs);

    printf("Creando hilo arriba...\n");
    fflush(stdout);
    
    
    pthread_create(&tid[0], NULL, move, (void*) misargs);
    // fin arriba ------------------------------------------------------------
    // inicio abajo ----------------------------------------------------------
    int misarg[4];
    misarg[0] = argu[0]+1; //x
    misarg[1] = argu[1]; //y
    misarg[2] = 0; // origen
    misarg[3] = 1; // s
    
    pthread_mutex_lock(&mutexBuffer);
    laberinto[misarg[0]][misarg[1]].valor = '#';
    laberinto[misarg[0]-1][misarg[1]].arriba = true;
    pthread_mutex_unlock(&mutexBuffer);    

    void *move(void *misarg);

    printf("Creando hilo arriba...\n");
    fflush(stdout);
    
    
    pthread_create(&tid[1], NULL, move, (void*) misarg);
    
    // fin abajo ------------------------------------------------------------
    
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    
    fflush(stdout);
    
}

void crearHijoArriba(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]-1; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 1; // origen
    misargs[3] = 0; // s
    
    pthread_mutex_lock(&mutexBuffer);
    laberinto[misargs[0]][misargs[1]].valor = '#';
    laberinto[misargs[0]+1][misargs[1]].arriba = true;
    pthread_mutex_unlock(&mutexBuffer);
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo arriba...\n");
    fflush(stdout);
    
    
    pthread_create(&tid, NULL, move, (void*) misargs);
    pthread_join(tid, NULL);
    
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
    
    pthread_mutex_lock(&mutexBuffer);
    laberinto[misargs[0]][misargs[1]].valor = '#';
    laberinto[misargs[0]][misargs[1]-1].derecha = true;
    pthread_mutex_unlock(&mutexBuffer);
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo derecha...\n");
    fflush(stdout);    
    
    pthread_create(&tid, NULL, move, (void*) misargs);
    
    pthread_join(tid, NULL);
    
    fflush(stdout);
    
}

void crearHijoIzquierda(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]; //x
    misargs[1] = argu[1]-1; //y
    misargs[2] = 3; // origen
    misargs[3] = 2; // sgt
    
    
    pthread_mutex_lock(&mutexBuffer);
    laberinto[misargs[0]][misargs[1]].valor = '#';
    laberinto[misargs[0]][misargs[1]+1].izquierda = true;
    pthread_mutex_unlock(&mutexBuffer);
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo izquierda...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);
    pthread_join(tid, NULL);
    fflush(stdout);
}

void crearHijoAbajo(void *arg) {
    int *argu;
    argu = (int *)arg;
    
    int misargs[4];
    misargs[0] = argu[0]+1; //x
    misargs[1] = argu[1]; //y
    misargs[2] = 0; // origen
    misargs[3] = 1; // s
    
    printf("SSOOOY ABAJOO...");
    printf("%d",misargs[0]);
    printf("%d",misargs[1]);
    printf("%d",misargs[2]);
    printf("%d",misargs[3]);
    pthread_mutex_lock(&mutexBuffer);
    laberinto[argu[0]][argu[1]].valor = '#';
    laberinto[argu[0]-1][argu[1]].abajo = true;
    pthread_mutex_unlock(&mutexBuffer);
    
    pthread_t tid;

    void *move(void *misargs);

    printf("Creando hilo abajo...\n");
    fflush(stdout);

    pthread_create(&tid, NULL, move, (void*) misargs);
    pthread_join(tid, NULL);
    
    fflush(stdout);
    
}
