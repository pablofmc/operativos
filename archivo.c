#include "archivo.h"

void leerArchivo() {
    arch = fopen("archivo.txt", "r");

    while(!feof(arch)) {
            ch=(int)fgetc(arch);
            if(ch!='\n') {
                    //laberinto[i][j]=ch;
                    j++;
            } else {
                    j=0;
                    i++;
            }
    }
    fclose(arch);
}
