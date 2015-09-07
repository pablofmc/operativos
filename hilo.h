/* 
 * File:   hilo.h
 * Author: diego
 *
 * Created on September 7, 2015, 2:02 AM
 */

#ifndef HILO_H
#define	HILO_H

struct {
    int posX;
    int posY;
    bool estado;
};


void born(int posX, int posY);
void move(int posX, int posY);
void evaluarMovimiento(int posX, int posY);
void die();
void procreate(int posX, int posY);
void waymark(int posX, int posY);
void communicate();

#endif	/* HILO_H */

