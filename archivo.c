#include "archivo.h"

void leerArchivo() {
    pthread_mutex_lock (&mutexBuffer);
    arch = fopen("archivo.txt", "r");
    i=0; j=0;
    while(!feof(arch)) {
            ch=(int)fgetc(arch);
            if(ch!='\n') {
                    laberinto[i][j].valor = ch;
                    j++;
            } else {
                    j=0;
                    i++;
            }
    }
    
    fclose(arch);
    printf("salida: %c \n", laberinto[0][1].valor);
    pthread_mutex_unlock (&mutexBuffer);
}
