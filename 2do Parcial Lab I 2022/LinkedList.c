#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

	if(this!=NULL)
	{
		returnAux = this->size;
	}
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodo=NULL;

	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	{

		nodo = this->pFirstNode;//guardo la direccion de memoria del primer nodo

		if(nodeIndex!=0)
		{
			for(int i=0; i<nodeIndex; i++)
			{
				nodo=nodo->pNextNode;
			}
		}
	}
    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* nuevoNodo = NULL;

	if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this))
	{
	    nuevoNodo=(Node*)malloc(sizeof(Node));
	    if(nuevoNodo!=NULL)
	    {
	    	nuevoNodo->pElement = pElement; // El nuevo nodo apunta a la carga

	    	if(nodeIndex==0)
	    	{
	    		nuevoNodo->pNextNode=this->pFirstNode; // Agarro el nodo siguiente y le asigno el primer nodo 1=>2
	    		this->pFirstNode = nuevoNodo; // El nuevo nodo lo apunto al primer nodo 2<=1
	    	}
	    	else
	    	{
	    		nuevoNodo->pNextNode=getNode(this, nodeIndex); // Le asigno la posicion siguiente al nodo que pedi en esa posicion
	    	    (getNode(this, nodeIndex -1))->pNextNode=nuevoNodo; // Agrego el nodo a la posicion solicitada
	    	}
	    	returnAux=0;
	    	this->size++; // actualizo el tamaño del linkedList
	    }
	 }
	 return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this !=NULL)
    {
    	retorno = addNode(this, ll_len(this), pElement);
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;
    Node* nodo;

        if(this!=NULL && index>=0 && index<ll_len(this))
        {
            nodo=getNode(this,index);

            if(nodo!=NULL)
            {
                retorno = nodo->pElement; //Si es distinto de null me retorna el nodo en el indice indicado
            }
        }
    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno=-1;
    Node* nodo=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	nodo=getNode(this, index);

    	if(nodo!=NULL)
    	{
    		nodo->pElement=pElement; //Si encontro la posicion le inserto mi nuevo pElement
    		retorno=0;
    	}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    Node* nodoBorrar=NULL;
    Node* nodoAnterior=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	if(index==0)
    	{
    		nodoBorrar=this->pFirstNode; //Le asigno al nodo a borrar el primer nodo
    		this->pFirstNode=nodoBorrar->pNextNode; //Luego le digo a la linkedList que mi primer nodo va a ser el siguiente nodo
    	}
    	else
    	{
    		nodoAnterior=getNode(this, index-1); //Le asigno el nodo anterior al indice indicado
    		nodoBorrar=getNode(this, index); //Le asigno el nodo en el indice indicado
    		nodoAnterior->pNextNode=nodoBorrar->pNextNode; //Le asigno al nodo actual el nodo siguiente al indice indicado
    	}

    	free(nodoBorrar); //Borro el nodo indicado
    	this->size--; //Achico un vagon ya que estoy borrando un nodo
    	retorno=0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
    	while(ll_len(this)>0)
    	{
    		ll_remove(this, ll_len(this)-1);
    		retorno=0;
    	}
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno=-1;

    if(this!=NULL && !ll_clear(this))
    {
    	free(this);
    	retorno=0;
    }
    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno=-1;
    Node* nodo=NULL;

    if(this!=NULL)
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		nodo=getNode(this, i);

    		if(nodo!=NULL && nodo->pElement==pElement)
    		{
    			retorno=i; //Guardo la posicion del elemento pasado como referencia
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this!=NULL)
    {
    	if(this->size>=1) //si la lista contiene almenos un elemento
    	{
    		retorno=0;
    	}
    	else
    	{
    		retorno=1; //lista vacia
    	}
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;

    retorno=ll_get(this, index);
    ll_remove(this, index);//elimino el node

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno=-1;

    if(this!=NULL)
    {
    	if(ll_indexOf(this, pElement)==-1)
    	{
        	retorno=0; // no encontro el element0
    	}
        else
        {
        	retorno=1; //encontro
        }
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;

    if(this!=NULL && this2!=NULL)
    {
    	retorno=1;

    	for(int i=0; i<ll_len(this2); i++)
    	{
    		if(!ll_contains(this, ll_get(this2, i))) //Obtengo los element de this2
    		{
    			retorno=0;
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL && from>=0 && to>from && to<=ll_len(this))
    {
    	cloneArray=ll_newLinkedList();

    	if(cloneArray!=NULL)
    	{
    		for(int i=from; i<to; i++)
    		{
    			ll_add(cloneArray, ll_get(this, i)); //Agrego los pElement de this al nuevo LinkedList
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno=-1;
    void* pElement1=NULL;
    void* pElement2=NULL;
    void* pAuxiliar=NULL;

    if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		for(int j=i+1; j<ll_len(this); j++)
    		{
    			pElement1=ll_get(this, i);
    			pElement2=ll_get(this, j);

    			if((!order && pFunc(pElement1,pElement2)<0) || (order==1 && pFunc(pElement1,pElement2)>0))
    			{
    				pAuxiliar=pElement1;
    				ll_set(this, i, pElement2);
    				ll_set(this, j, pAuxiliar);
    			}
    		}
    	}
    	retorno=0;
    }

    return retorno;
}

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* nuevaLista = NULL;
    void* pElement=NULL;

    if(this!= NULL && pFunc!= NULL)
    {
        nuevaLista = ll_newLinkedList();
        if(nuevaLista!=NULL)
        {
            for(int i=0; i<ll_len(this); i++)
            {
                pElement=ll_get(this, i);

                if(pFunc(pElement))
                {
                    ll_add(nuevaLista,pElement);
                }
            }
        }

    }
    return nuevaLista;
}

LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void*))
{
    void* pElement=NULL;
    LinkedList* nuevaLista = NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        nuevaLista=ll_newLinkedList();

        for(int i=0; i<ll_len(this); i++)
        {
            pElement=ll_get(this,i);
            pElement=pFunc(pElement);
            if(pElement!=NULL)
            {
                ll_add(nuevaLista,pElement);
            }
        }
    }
    return nuevaLista;
}
