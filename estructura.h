/* 
 * File:   estructura.h
 * Author: diego
 *
 * Created on September 7, 2015, 10:11 AM
 */

#ifndef ESTRUCTURA_H
#define	ESTRUCTURA_H
#include <stdbool.h>

struct campo {
    char valor;
    bool arriba;
    bool abajo;
    bool derecha;
    bool izquierda;
};

#endif	/* ESTRUCTURA_H */

