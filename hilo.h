/* 
 * File:   hilo.h
 * Author: pablofmc
 *
 * Created on September 8, 2015, 2:12 PM
 */

#ifndef HILO_H
#define	HILO_H


void movex(void *arg, int v);
void die();
void movey(void *arg, int v);
void ways(void *arg);
void crearHijoArriba(void *arg);
void crearHijoAbajo(void *arg);
void crearHijoDerecha(void *arg);
void crearHijoIzquierda(void *arg);
void *routine(void *arg);
void *move(void *arg);

#endif	/* HILO_H */

