#include "Movie.h"
#include "Validaciones.h"

int menuPrincipal()
{
    system("cls");
    int opcion;
    printf(" ________________________________________________________\n");
    printf("|               >>> LINKEDLIST PELICULAS <<<             |\n");
    printf("|________________________________________________________|\n\n");
    printf("|              1) Cargar archivo modo texto              |\n");
    printf("|              2) Imprimir lista de peliculas            |\n");
    printf("|              3) Asignar tiempos de pelicula            |\n");
    printf("|              4) Filtrar peliculas por tipo             |\n");
    printf("|              5) Mostrar peliculas ordenada x genero    |\n");
    printf("|              6) Guardar peliculas ordenadas x genero   |\n");
    printf("|              7) Salir                                  |\n");
    printf("|________________________________________________________|\n\n");
    printf("---------------------------------------------------------\n");
    opcion=validarEntero(">>>>   Ingrese opcion: ",">>>>   Reingrese opcion: ",1,7);
    return opcion;
}

int menuTipo()
{
    system("cls");
    int opcion;
    printf(" _____________________________________\n");
    printf("|          >>> ELEGIR TIPO <<<        |\n");
    printf("|_____________________________________|\n\n");
    printf("|               1) Adventure          |\n");
    printf("|               2) Drama              |\n");
    printf("|               3) Comedy             |\n");
    printf("|               4) Romance            |\n");
    printf("|               5) Documentary        |\n");
    printf("|               6) Horror             |\n");
    printf("|               7) Musical            |\n");
    printf("|               8) Animation          |\n");
    printf("|               9) Action             |\n");
    printf("|              10) Thriller           |\n");
    printf("|              11) Western            |\n");
    printf("|_____________________________________|\n\n");
    printf("--------------------------------------\n");
    opcion=validarEntero(">>>>   Ingrese opcion: ",">>>>   Reingrese opcion: ",1,11);
    return opcion;
}

Movie* movie_new()
{
    return(Movie*)malloc(sizeof(Movie));
}

Movie* movie_newParam(char* idStr, char* titulo, char* genero, char* duracion)
{
	Movie* nuevaPelicula=movie_new();

	if(nuevaPelicula!=NULL && movie_setId(nuevaPelicula,atoi(idStr)) && movie_setTitulo(nuevaPelicula, titulo) &&
    movie_setGenero(nuevaPelicula, genero) && movie_setDuracion(nuevaPelicula, atoi(duracion)))
	{
		return nuevaPelicula;
	}
	free(nuevaPelicula);
    nuevaPelicula=NULL;

	return nuevaPelicula;
}

void movie_delete(Movie* this)
{
	free(this);
}

int movie_setId(Movie* this, int id)
{
	int retorno=0;

	if(this!=NULL && id>0)
	{
		this->id=id;
	    retorno=1;
	}
	return retorno;
}

int movie_getId(Movie* this, int* id)
{
	int retorno=0;
	if(this!=NULL && id!=NULL)
	{
	    *id=this->id;
		retorno=1;
	}
	return retorno;
}

int movie_setTitulo(Movie* this,char* titulo)
{
	int retorno=0;

	if(this!=NULL && titulo!=NULL && strlen(titulo)<50 && strlen(titulo)>0)
	{
		strcpy(this->titulo,titulo);
	    retorno=1;
	}
	return retorno;
}

int movie_getTitulo(Movie* this,char* titulo)
{
	int retorno=0;

	if(this!=NULL && titulo!=NULL && strlen(titulo)<50 && strlen(titulo)>0)
	{
		strcpy(titulo, this->titulo);
	    retorno=1;
	}
	return retorno;
}

int movie_setGenero(Movie* this,char* genero)
{
	int retorno=0;

	if(this!=NULL && genero!=NULL && strlen(genero)<50 && strlen(genero)>0)
	{
		strcpy(this->genero, genero);
		retorno=1;
	}
	return retorno;
}

int movie_getGenero(Movie* this,char* genero)
{
	int retorno=0;

	if(this!=NULL && genero!=NULL && strlen(genero)<50 && strlen(genero)>0)
	{
		strcpy(genero, this->genero);
		retorno=1;
	}
	return retorno;
}

int movie_setDuracion(Movie* this,int duracion)
{
	int retorno=0;

	if(this!=NULL && duracion>=0)
	{
		this->duracion=duracion;
		retorno=1;
	}
	return retorno;
}

int movie_getDuracion(Movie* this,int* duracion)
{
	int retorno=0;

	if(this!=NULL && duracion!=NULL)
	{
		*duracion=this->duracion;
		retorno=1;
	}
	return retorno;
}

int mostrarPelicula(Movie* unaPelicula)
{
    int retorno=0;
    if(unaPelicula!=NULL)
    {
        printf("   %2d\t%25s\t%15s     %2d\n",unaPelicula->id,unaPelicula->titulo,unaPelicula->genero,unaPelicula->duracion);
        printf("____________________________________________________________________\n");
        retorno=1;
    }
    return retorno;
}

int mostrarPeliculas(LinkedList* listadoPeliculas)
{
    int retorno=0;
    Movie* unaPelicula=NULL;
    int tam=ll_len(listadoPeliculas);
    int flagBanderaPelicula=0;

	if(listadoPeliculas!=NULL)
	{
	    retorno=1;
		printf(" ___________________________________________________________________\n");
		printf("|                    >>> LISTADO DE PELICULAS <<<                   |\n");
		printf("|___________________________________________________________________|\n\n");
		printf("|  Id               Titulo                      Genero     Tiempo   |\n");
		printf("|___________________________________________________________________|\n");

		for(int i=0; i<tam; i++)
		{
		    unaPelicula=(Movie*)ll_get(listadoPeliculas,i);
		    if(unaPelicula!=NULL)
            {
                mostrarPelicula(unaPelicula);
                flagBanderaPelicula=1;
            }
		}
	}

    if(flagBanderaPelicula==0)
    {
        printf("No se encuentran peliculas cargadas\n");
    }
	return retorno;
}



int movie_loadFromText(char* path, LinkedList* listadoPeliculas)
{
    int retorno=0;
    FILE* pFile=NULL;

    if(path!=NULL && listadoPeliculas!=NULL)
    {
        pFile=fopen(path, "r");
        if(pFile!= NULL)
        {
            if(parser_MovieFromText(pFile,listadoPeliculas))
            {
                retorno=1;
                printf("\n--------- Carga de archivo realizada exitosamente ! ---------  \n");
            }
            else
            {
                printf("\n--------- El archivo no se pudo cargar correctamente ! ---------  \n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\n--------- Error, el archivo no pudo abrirse o no fue encontrado ! ---------  \n");
        }
    }
    return retorno;
}

int movie_guardarTexto(char* path, LinkedList* listadoPeliculas)
{
    FILE* pFile=fopen(path,"w") ;
    int tam =  ll_len(listadoPeliculas);
    Movie* unaPelicula;
    int retorno=0;

    if(pFile!=NULL)
    {
        fprintf(pFile,"id_peli,titulo,genero,duracion\n");
        for(int i=0; i<tam; i++)
        {
            unaPelicula=(Movie*)ll_get(listadoPeliculas,i);
            if(unaPelicula!=NULL)
            {
                fprintf(pFile,"%d,%s,%s,%d\n", unaPelicula->id,unaPelicula->titulo,unaPelicula->genero,unaPelicula->duracion);
                retorno=1;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

int filtrarGeneroAdventure(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"ADVENTURE")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroDrama(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"DRAMA")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroComedy(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"COMEDY")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroRomance(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"ROMANCE")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroDocumentary(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"DOCUMENTARY")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroHorror(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"HORROR")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroMusical(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"MUSICAL")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroAnimation(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"ANIMATION")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroAction(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"ACTION")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroThriller(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"THRILLER")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int filtrarGeneroWestern(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    int retorno=0;

    if(pElement!=NULL)
    {
        if(stricmp(unaPelicula->genero,"WESTERN")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int movie_filtrarTipos(LinkedList* listadoPeliculas)
{
    int retorno=0;
    LinkedList* listaNueva=NULL;

    switch(menuTipo())
    {
    case 1:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroAdventure);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroAdventure.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo adventura en el archivo movieGeneroAdventure.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 2:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroDrama);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroDrama.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo drama en el archivo movieGeneroDrama.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 3:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroComedy);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroComedy.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo comedy en el archivo movieGeneroComedy.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 4:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroRomance);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroRomance.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo romance en el archivo movieGeneroRomance.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 5:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroDocumentary);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroDocumentary.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo documentary en el archivo movieGeneroDocumentary.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 6:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroHorror);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroHorror.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo horror en el archivo movieGeneroHorror.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 7:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroMusical);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroMusical.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo musical en el archivo movieGeneroMusical.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 8:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroAnimation);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroAnimation.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo animation en el archivo movieGeneroAnimation.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 9:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroAction);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroAction.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo Action en el archivo movieGeneroAction.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 10:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroThriller);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroThriller.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo western en el archivo movieGeneroThriller.csv ! ---------  \n");
            retorno=1;
        }
        break;
    case 11:
        listaNueva=ll_filter(listadoPeliculas,filtrarGeneroWestern);

        if(!ll_isEmpty(listaNueva))
        {
            movie_guardarTexto("movieGeneroWestern.csv",listaNueva);
            printf("\n--------- Se cargo las peliculas tipo western en el archivo movieGeneroWestern.csv ! ---------  \n");
            retorno=1;
        }
        break;
        system("pause");
    }
    return retorno;
}

void* movie_asignarTiempo(void* pElement)
{
    Movie* unaPelicula=(Movie*)pElement;
    void* retorno=NULL;
    int TiempoAleatorio;

    if(pElement!=NULL)
    {
        TiempoAleatorio=rand()%(240-100)+100;
        movie_setDuracion(unaPelicula,TiempoAleatorio);
        retorno=(void*)unaPelicula;
    }
    return retorno;
}

int movie_ordenPorGeneroTiempo(void* pElementA, void* pElementB)
{
    int retorno=0;
    Movie* peliculaUno=(Movie*)pElementA;
    Movie* peliculaDos=(Movie*)pElementB;

    if(peliculaUno!=NULL && peliculaDos!=NULL)
    {
        retorno=strcmp(peliculaUno->genero,peliculaDos->genero);

        if(!retorno)
        {
            retorno=peliculaUno->duracion+peliculaDos->duracion; //ascendente - || descendente +
        }
    }
    return retorno;
}


int movie_mostrarPosiciones(LinkedList* listadoPeliculas)
{
    int retorno=0;

    if(listadoPeliculas!=NULL)
    {
        ll_sort(listadoPeliculas,movie_ordenPorGeneroTiempo,1); //1 ASCENDENTE || 0 DESCENDENTE
        mostrarPeliculas(listadoPeliculas);
        retorno=1;
    }
    return retorno;
}

int movie_guardarPosiciones(LinkedList* listadoPeliculas, char* nombreArchivo)
{
    int retorno=0;

    if(listadoPeliculas!=NULL && nombreArchivo!=NULL)
    {
        movie_guardarTexto(nombreArchivo,listadoPeliculas);
        retorno=1;
    }
    return retorno;
}

