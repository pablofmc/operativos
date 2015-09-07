/* 
 * File:   archivo.h
 * Author: diego
 *
 * Created on September 7, 2015, 1:22 AM
 */

#include "variables.h"
#ifndef ARCHIVO_H
#define	ARCHIVO_H

void leerArchivo() {
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
}

#endif	/* ARCHIVO_H */

