/* 
 * File:   hilo.h
 * Author: diego
 *
 * Created on September 7, 2015, 2:02 AM
 */

#ifndef HILO_H
#define	HILO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct {
    int posX;
    int posY;
    bool estado;
};


void born();
void move(void *arg);
void evaluarMovimiento(int posX, int posY);
void die();
void procreate(int posX, int posY);
void waymark(int posX, int posY);
void communicate();
void *routine(void *arg);

#endif	/* HILO_H */

