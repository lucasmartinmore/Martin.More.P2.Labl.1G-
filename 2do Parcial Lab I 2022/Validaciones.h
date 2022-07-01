#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // VALIDACIONES_H_INCLUDED

void validarCadena(char mensaje[], char mensajeDeError[], int tamanio, char variableCopiar[]);
int validarEntero(char mensaje[], char mensajeDeError[], int minimo, int maximo);
float validarFlotante(char mensaje[], char errorDeMensaje[], float minimo, float maximo);
char validarCaracter(char mensaje[], char errorDeMensaje[]);
