#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Movie.h"
#include "Validaciones.h"

int main()
{
    srand(time(NULL));
    LinkedList* listadoPeliculas=ll_newLinkedList();
    char nombreArchivo[50];
    int banderaCarga=0;
    int banderaTiempo=0;
    int banderaPosicion=0;
    int seguir=0;

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(banderaCarga==0)
            {
                validarCadena("Ingrese nombre del archivo(Ej:movies.csv): ","Error, reingrese nombre del archivo(Ej:Movie.csv): ",50,nombreArchivo);
                if(movie_loadFromText(nombreArchivo,listadoPeliculas))
                {
                    banderaCarga=1;
                }
            }
            else
            {
                printf("\n--------- El archivo ya se encuentra cargado ! ---------  \n");
            }
            break;
        case 2:
            if(banderaCarga)
            {
                mostrarPeliculas(listadoPeliculas);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de mostrar ! ---------  \n");
            }
            break;
        case 3:

            if(banderaCarga)
            {
                listadoPeliculas=ll_map(listadoPeliculas,movie_asignarTiempo);
                banderaTiempo=1;
                printf("\n--------- Se asigno los tiempos de las peliculas correctamente ! ---------  \n");
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de asignar el tiempo ! ---------  \n");
            }
            break;
        case 4:
            if(banderaCarga)
            {
                movie_filtrarTipos(listadoPeliculas);
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo antes de filtrar los tipos ! ---------  \n");
            }
            break;
        case 5:
            if(banderaCarga && banderaTiempo)
            {
                movie_mostrarPosiciones(listadoPeliculas);
                banderaPosicion=1;
            }
            else
            {
                printf("\n--------- Se debe cargar el archivo y asignar los tiempos antes de mostrar las posiciones ! ---------  \n");
            }
            break;
        case 6:
            if(banderaPosicion)
            {
                if(movie_guardarPosiciones(listadoPeliculas,"moviesOrdenadas.csv"))
                {
                    printf("\n--------- El archivo movieOrdenadas.csv se cargo correctamente ! ---------  \n");
                }
            }
            else
            {
                printf("\n--------- Antes de guardar el archivo se debe ordenar por tipo y tiempo ! ---------  \n");
            }
            break;
        case 7:
            ll_deleteLinkedList(listadoPeliculas);
            seguir=1;
            break;
        }
        system("pause");
    }while(seguir!=1);
}


