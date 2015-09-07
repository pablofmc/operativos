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



void born();
void move(void *arg);

void born(void *arg);
void move(void *arg);
void evaluarMovimiento(void *arg);
void die();
void evaluarProcreate(void *arg);
void waymark(int posX, int posY);
void communicate();
void *routine(void *arg);

#endif	/* HILO_H */

