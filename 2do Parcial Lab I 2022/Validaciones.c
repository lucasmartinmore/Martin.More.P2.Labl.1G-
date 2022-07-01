#include "Validaciones.h"

void validarCadena(char mensaje[], char mensajeDeError[], int tamanio, char variableCopiar[])
{
    char auxStr[100];
    printf("%s", mensaje);
    fflush(stdin);
    gets(auxStr);
    int i=0;

    while(strlen(auxStr)>tamanio || auxStr[i]==' ' || strlen(auxStr)<=0)
    {
        printf("%s", mensajeDeError);
        fflush(stdin);
        gets(auxStr);
        i++;
    }
    strcpy(variableCopiar, auxStr);
}

int validarEntero(char mensaje[], char mensajeDeError[], int minimo, int maximo)
{
    int auxInt;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &auxInt);

    while(auxInt<minimo || auxInt>maximo || auxInt==' ')
    {
        printf("%s", mensajeDeError);
        fflush(stdin);
        scanf("%d", &auxInt);
    }
    return auxInt;
}

float validarFlotante(char mensaje[], char errorDeMensaje[], float minimo, float maximo)
{
    float auxFloat;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &auxFloat);
    while(auxFloat<minimo || auxFloat>maximo || auxFloat==' ')
    {
        printf("%s", errorDeMensaje);
        fflush(stdin);
        scanf("%f", &auxFloat);
    }
    return auxFloat;
}

char validarCaracter(char mensaje[], char errorDeMensaje[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    while((caracter<'a' || caracter>'z' || caracter==' ') && (caracter<'A' || caracter>'Z' || caracter==' '))
    {
        printf("%s", errorDeMensaje);
        fflush(stdin);
        scanf("%c", &caracter);
    }
    return caracter;
}
