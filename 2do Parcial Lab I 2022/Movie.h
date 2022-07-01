#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"

typedef struct
{
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
}Movie;

#endif // MOVIE_H_INCLUDED

int menuPrincipal();
int menuTipo();

Movie* movie_new();
Movie* movie_newParam(char* idStr, char* titulo, char* genero, char* duracion);
void movie_delete(Movie* this);

int movie_setId(Movie* this, int id);
int movie_getId(Movie* this, int* id);
int movie_setTitulo(Movie* this,char* titulo);
int movie_getTitulo(Movie* this,char* titulo);
int movie_setGenero(Movie* this,char* genero);
int movie_getGenero(Movie* this,char* genero);
int movie_setDuracion(Movie* this,int duracion);
int movie_getDuracion(Movie* this,int* duracion);

int mostrarPelicula(Movie* unaPelicula);
int mostrarPeliculas(LinkedList* listadoPeliculas);

int movie_loadFromText(char* path, LinkedList* listadoPeliculas);
int movie_guardarTexto(char* path, LinkedList* listadoPeliculas);

int filtrarGeneroAdventure(void* pElement);
int filtrarGeneroDrama(void* pElement);
int filtrarGeneroComedy(void* pElement);
int filtrarGeneroRomance(void* pElement);
int filtrarGeneroDocumentary(void* pElement);
int filtrarGeneroHorror(void* pElement);
int filtrarGeneroMusical(void* pElement);
int filtrarGeneroAnimation(void* pElement);
int filtrarGeneroAction(void* pElement);
int filtrarGeneroThriller(void* pElement);
int filtrarGeneroWestern(void* pElement);
int movie_filtrarTipos(LinkedList* listadoPeliculas);

void* movie_asignarTiempo(void* pElement);

int movie_ordenPorGeneroTiempo(void* pElementA, void* pElementB);
int movie_mostrarPosiciones(LinkedList* listadoPeliculas);
int movie_guardarPosiciones(LinkedList* listadoPeliculas, char* nombreArchivo);
