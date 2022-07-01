#include "Parser.h"
#include "Movie.h"

int parser_MovieFromText(FILE* pFile, LinkedList* listadoPeliculas)
{
    int cantidad;
    Movie* unaPelicula;
    int retorno=0;
    char buffer[4][50];

    if(pFile!=NULL  && listadoPeliculas!=NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            unaPelicula=movie_new();
            cantidad=fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantidad==4)
            {
                unaPelicula=movie_newParam(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(listadoPeliculas, unaPelicula);
                retorno=1;
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}
