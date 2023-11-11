///Librerias
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

///Macros
#define DIM 30

///Estructuras
typedef struct stEquipo {
    int idEquipo;
    char nombreEquipo[DIM];
}stEquipo;

typedef struct stJugador {
    int idJugador;
    int nroCamiseta;
    char nombreJugador[DIM];
    int puntosAnotados;
}stJugador;

typedef struct stListaSecundaria {
    stJugador infoJugadores;
    struct stListaSecundaria *ptrSiguiente;
}stListaSecundaria;

typedef struct stListaPpal {
    stEquipo infoEquipo;
    stListaSecundaria *ptrListaJugadores;
    struct stListaPpal *ptrSiguiente;
}stListaPpal;

typedef struct stJugadorEquipo {
    int idEquipo;
    char nombreEquipo[DIM];
    int idJugador;
    int nroCamiseta;
    char nombreJugador[DIM];
    int puntosAnotados;
}stJugadorEquipo;

typedef struct stArbolGoleadores {
    stJugadorEquipo infoEquipoJugador;
    struct stArbolGoleadores *ptrIzq;
    struct stArbolGoleadores *ptrDer;
}stArbolGoleadores;

///Prototipado (Solo funciones que no son de tipo VOID)
stListaPpal *inicializarListaPpal();
stListaSecundaria *inicializarListaSecundaria();
stListaPpal *crearNodoPpal(stEquipo infoEquipo);
stListaSecundaria *crearNodoSecundario(stJugador infoJugador);
stListaPpal *agregarAlPrincipioPpal(stListaPpal *ptrListaEquipos, stListaPpal *nuevoEquipo);
stListaSecundaria *agregarAlPrincipioSecundaria(stListaSecundaria *ptrListaJugadores, stListaSecundaria *nuevoJugador);
stListaPpal *buscarEquipoPorNombre(stListaPpal *ptrListaEquipos, char nombreEquipo[]);
stListaPpal *crearEquipos(stListaPpal *ptrListaEquipos, stEquipo auxEquipo, stJugador auxJugador);
stListaPpal *pasarDelArchivoALista(stListaPpal *ptrListaEquipos, char nombreArchivo[]);
stListaPpal *insertarNuevosJugadores(stListaPpal *ptrListaEquipos);
stArbolGoleadores *inicializarArbol();
stArbolGoleadores *crearNodoArbol(stJugadorEquipo auxJugadorEquipo);
stArbolGoleadores *insertarJugadoresGoleadoresEnArbol(stArbolGoleadores *ptrArbolGoleadores, stJugadorEquipo auxJugadorEquipo);
stListaSecundaria *buscarJugadorGoleadorPorEquipo(stListaSecundaria *ptrListaJugadores);
stArbolGoleadores *cargarArbolConGoleadoresDeEquipos(stListaPpal *ptrListaEquipos, stArbolGoleadores *ptrArbolGoleadores);
int calcularTotalJugadoresEquipos(stListaSecundaria *ptrListaJugadores);
int calcularCantidadTotalJugadores(stListaPpal *ptrListaEquipos);
/*------------------------------------------------------------------*/
int main(){

    /**Verificación: MostrarArchivo**/
    char nombreArchivo[] = {"registroJugador.dat"};
    //mostrarArchivo(nombreArchivo);

    /**Declaración e inicialización Lista**/
    stListaPpal *ptrListaEquipos = inicializarListaPpal();

    ///Ejercicio 1
    /**Pasar del Archivo a la Lista de Equipos**/
    ptrListaEquipos = pasarDelArchivoALista(ptrListaEquipos, nombreArchivo);

    /**Debug: Mostrar Lista de Listas**/
    //mostrarListaEquipos(ptrListaEquipos);

    ///Ejercicio 2
    /**Crear nuevos equipos e insertarle jugadores**/
//    ptrListaEquipos = insertarNuevosJugadores(ptrListaEquipos);
//    mostrarListaEquipos(ptrListaEquipos);

    ///Ejercicio 3
    //mostrarListaEquipos(ptrListaEquipos);

    ///Ejercicio 4
    //stArbolGoleadores *ptrArbolGoleadores = inicializarArbol();
    //ptrArbolGoleadores = cargarArbolConGoleadoresDeEquipos(ptrListaEquipos, ptrArbolGoleadores);
    //mostrarArbolGoleadoresEnOrden(ptrArbolGoleadores);

    ///Ejercicio 5
    calcularPorcentajeTorneo(ptrListaEquipos);

    ///Ejercicio 6
    char archivoNroCamisetaEspecifico[] = {"jugadoresPorNumeroCamiseta.dat"};
    //pasarDeLaListaAlArchivo(archivoNroCamisetaEspecifico, ptrListaEquipos, 3);
    printf("MOSTRANDO ARCHIVO CON JUGADORES DEL NRO DE CAMISETA 3 \n\n");
    mostrarArchivo(archivoNroCamisetaEspecifico);

    return 0;
}
/*------------------------------------------------------------------*/
///Funciones

///Mostrar Archivo
void mostrarUnRegistroJugador(stJugadorEquipo auxRegistro){
    printf("\n................................\n");
    printf("Equipo: %s\n", auxRegistro.nombreEquipo);
    printf("ID Equipo: %i\n\n", auxRegistro.idEquipo);
    printf("Jugador: %s\n", auxRegistro.nombreJugador);
    printf("ID Jugador: %i\n", auxRegistro.idJugador);
    printf("Nro Camiseta: %i\n", auxRegistro.nroCamiseta);
    printf("Goles Anotados: %i", auxRegistro.puntosAnotados);
    printf("\n................................\n");
}

void mostrarArchivo(char nombreArchivo[]) {

    FILE *ptrArchivo = fopen(nombreArchivo, "rb");
    stJugadorEquipo auxRegistro;

    if(ptrArchivo == NULL) printf("\nError al abrir el Archivo\n");

    else {
        while(fread(&auxRegistro, sizeof(stJugadorEquipo), 1, ptrArchivo) == 1) mostrarUnRegistroJugador(auxRegistro);

        fclose(ptrArchivo);
    }
}

///Inicializar Listas (Principal y Secundaria)
stListaPpal *inicializarListaPpal() {
   return NULL;
}

stListaSecundaria *inicializarListaSecundaria() {
    return NULL;
}

///Crear Nodos (Principal y Secundario)
stListaPpal *crearNodoPpal(stEquipo infoEquipo) {

    stListaPpal *nuevoEquipo = (stListaPpal*) malloc(sizeof(stListaPpal));

    strcpy(nuevoEquipo->infoEquipo.nombreEquipo, infoEquipo.nombreEquipo);
    nuevoEquipo->infoEquipo.idEquipo = infoEquipo.idEquipo;
    nuevoEquipo->ptrSiguiente = NULL;

    return nuevoEquipo;
}

stListaSecundaria *crearNodoSecundario(stJugador infoJugador) {

    stListaSecundaria *nuevoJugador = (stListaSecundaria*) malloc(sizeof(stListaSecundaria));

    strcpy(nuevoJugador->infoJugadores.nombreJugador, infoJugador.nombreJugador);
    nuevoJugador->infoJugadores.idJugador = infoJugador.idJugador;
    nuevoJugador->infoJugadores.nroCamiseta = infoJugador.nroCamiseta;
    nuevoJugador->infoJugadores.puntosAnotados = infoJugador.puntosAnotados;
    nuevoJugador->ptrSiguiente = NULL;

    return nuevoJugador;
}

///Agregar al Principio (Principal y Secundario)
stListaPpal *agregarAlPrincipioPpal(stListaPpal *ptrListaEquipos, stListaPpal *nuevoEquipo) {

    if(ptrListaEquipos == NULL) ptrListaEquipos = nuevoEquipo;

    else {
        nuevoEquipo->ptrSiguiente = ptrListaEquipos;
        ptrListaEquipos = nuevoEquipo;
    }
    return ptrListaEquipos;
}

stListaSecundaria *agregarAlPrincipioSecundaria(stListaSecundaria *ptrListaJugadores, stListaSecundaria *nuevoJugador) {

    if(ptrListaJugadores == NULL) ptrListaJugadores = nuevoJugador;

    else {
        nuevoJugador->ptrSiguiente = ptrListaJugadores;
        ptrListaJugadores = nuevoJugador;
    }
    return ptrListaJugadores;
}

///Copiar Equipo (Pasar los datos de stJugadorEquipo a una variable de tipo stEquipo)
void copiarEquipo(stJugadorEquipo auxJugadorEquipo, stEquipo *auxEquipo) {

    strcpy(auxEquipo->nombreEquipo, auxJugadorEquipo.nombreEquipo);
    auxEquipo->idEquipo = auxJugadorEquipo.idEquipo;
}

///Copiar Jugador (Pasar los datos de stJugadorEquipo a una variable de tipo stJugador)
void copiarJugador(stJugadorEquipo auxJugadorEquipo, stJugador *auxJugador) {

    strcpy(auxJugador->nombreJugador, auxJugadorEquipo.nombreJugador);
    auxJugador->idJugador = auxJugadorEquipo.idJugador;
    auxJugador->nroCamiseta = auxJugadorEquipo.nroCamiseta;
    auxJugador->puntosAnotados = auxJugadorEquipo.puntosAnotados;
}

///Buscamos equipo por nombre
stListaPpal *buscarEquipoPorNombre(stListaPpal *ptrListaEquipos, char nombreEquipo[]) {

    stListaPpal *auxListaEquipos = ptrListaEquipos;

    while(auxListaEquipos != NULL) {

        if(strcmp( auxListaEquipos->infoEquipo.nombreEquipo, nombreEquipo) == 0) return auxListaEquipos;

        auxListaEquipos = auxListaEquipos->ptrSiguiente;
    }
    return NULL;
}

///Creamos equipos
stListaPpal *crearEquipos(stListaPpal *ptrListaEquipos, stEquipo auxEquipo, stJugador auxJugador) {

    stListaPpal *resultadoBusqueda = buscarEquipoPorNombre(ptrListaEquipos, auxEquipo.nombreEquipo);

    if(resultadoBusqueda == NULL) { //No encontró el equipo

        stListaPpal *nuevoEquipo = crearNodoPpal(auxEquipo);
        ptrListaEquipos = agregarAlPrincipioPpal(ptrListaEquipos, nuevoEquipo);

        stListaSecundaria *nuevoJugador = crearNodoSecundario(auxJugador);
        ptrListaEquipos->ptrListaJugadores = inicializarListaSecundaria();
        ptrListaEquipos->ptrListaJugadores = agregarAlPrincipioSecundaria(ptrListaEquipos->ptrListaJugadores, nuevoJugador);
    }

    if(resultadoBusqueda != NULL) { //Si encontró el equipo

        stListaSecundaria *jugadorNuevo = crearNodoSecundario(auxJugador);
        resultadoBusqueda->ptrListaJugadores = agregarAlPrincipioSecundaria(resultadoBusqueda->ptrListaJugadores, jugadorNuevo);
    }
    return ptrListaEquipos;
}

///Pasamos los datos del Archivo a una Lista de Listas
stListaPpal *pasarDelArchivoALista(stListaPpal *ptrListaEquipos, char nombreArchivo[]) {

    FILE *ptrArchivo = fopen(nombreArchivo, "rb");
    stJugadorEquipo auxRegistro;

    if(ptrArchivo == NULL) printf("Error al abir el Archivo\n\n");

    else {
        while(fread(&auxRegistro, sizeof(stJugadorEquipo), 1, ptrArchivo) == 1) {

            stEquipo auxEquipo;
            copiarEquipo(auxRegistro, &auxEquipo);

            stJugador auxJugador;
            copiarJugador(auxRegistro, &auxJugador);

            ptrListaEquipos = crearEquipos(ptrListaEquipos, auxEquipo, auxJugador);
        }
        fclose(ptrArchivo);
    }
    return ptrListaEquipos;
}

///Mostrar Lista de Listas
void mostrarListaJugadores(stListaSecundaria *ptrListaJugadores) {

    if(ptrListaJugadores != NULL) {

            printf("Nombre Jugador: %s \n", ptrListaJugadores->infoJugadores.nombreJugador);
            printf("ID Jugador: %i \n", ptrListaJugadores->infoJugadores.idJugador);
            printf("Nro Camiseta: %i \n", ptrListaJugadores->infoJugadores.nroCamiseta);
            printf("Goles Anotados: %i \n\n", ptrListaJugadores->infoJugadores.puntosAnotados);

            mostrarListaJugadores(ptrListaJugadores->ptrSiguiente);
    }
}

void mostrarListaEquipos(stListaPpal *ptrListaEquipos) {

    if(ptrListaEquipos != NULL) {

            printf("\n..........................................................\n");
            printf("NOMBRE EQUIPO: %s \n", ptrListaEquipos->infoEquipo.nombreEquipo);
            printf("ID EQUIPO: %i \n\n", ptrListaEquipos->infoEquipo.idEquipo);

            mostrarListaJugadores(ptrListaEquipos->ptrListaJugadores);
            printf("..........................................................\n");

            mostrarListaEquipos(ptrListaEquipos->ptrSiguiente);
    }
}

///Cargar Equipo (Le pedimos al usuario los datos de stEquipo)
void cargarEquipo(stEquipo *unEquipo) {

    //Podría verificarse si el equipo que quiere crear no exista

    printf("Ingrese el nombre del Equipo: ");
    fflush(stdin);
    gets(unEquipo->nombreEquipo);
    printf("\n");

    printf("Ingrese el ID del Equipo: ");
    fflush(stdin);
    scanf("%i", &unEquipo->idEquipo);
    printf("\n");
}

///Cargar Jugador (Le pedimos al usuario los datos de stJugador)
void cargarJugador(stJugador *unJugador) {

    printf("Ingrese el nombre del Jugador: ");
    fflush(stdin);
    gets(unJugador->nombreJugador);
    printf("\n");

    printf("Ingrese el ID del Jugador: ");
    fflush(stdin);
    scanf("%i", &unJugador->idJugador);
    printf("\n");

    printf("Ingrese nro de Camiseta: ");
    fflush(stdin);
    scanf("%i", &unJugador->idJugador);
    printf("\n");

    printf("Ingrese la cantidad de Goles convertidos: ");
    fflush(stdin);
    scanf("%i", &unJugador->puntosAnotados);
    printf("\n");
}

///Insertar nuevos jugadores a la Lista de Listas
stListaPpal *insertarNuevosJugadores(stListaPpal *ptrListaEquipos) {

    char eleccion = 'n';

    stEquipo auxEquipoNuevo;
    cargarEquipo(&auxEquipoNuevo);

    stJugador auxJugadorNuevo;
    cargarJugador(&auxJugadorNuevo);

    stListaPpal *resultadoBusqueda = buscarEquipoPorNombre(ptrListaEquipos, auxEquipoNuevo.nombreEquipo);

    if(resultadoBusqueda == NULL) {

        printf("El equipo |%s| no existe, pulse 's' para crearlo: ", auxEquipoNuevo.nombreEquipo);
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

        if(eleccion == 's' || eleccion == 'S') ptrListaEquipos = crearEquipos(ptrListaEquipos, auxEquipoNuevo, auxJugadorNuevo);
    }

    if(resultadoBusqueda != NULL) {

        printf("El equipo |%s| existe, pulse 's' para añadir un Jugador al equipo: ", auxEquipoNuevo.nombreEquipo);
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

        if(eleccion == 's' || eleccion == 'S') ptrListaEquipos = crearEquipos(ptrListaEquipos, auxEquipoNuevo, auxJugadorNuevo);
    }
    return ptrListaEquipos;
}

///Inicializar Árbol
stArbolGoleadores *inicializarArbol() {
    return NULL;
}

///Crear nodoÁrbol
stArbolGoleadores *crearNodoArbol(stJugadorEquipo auxJugadorEquipo) {

    stArbolGoleadores *nuevoNodo = (stArbolGoleadores*) malloc(sizeof(stArbolGoleadores));

    nuevoNodo->infoEquipoJugador = auxJugadorEquipo;
    nuevoNodo->ptrDer = NULL;
    nuevoNodo->ptrIzq = NULL;

    return nuevoNodo;
}

///Insertar jugadores en el Árbol por cantidad de Goles
stArbolGoleadores *insertarJugadoresGoleadoresEnArbol(stArbolGoleadores *ptrArbolGoleadores, stJugadorEquipo auxJugadorEquipo) {

    if(ptrArbolGoleadores == NULL) ptrArbolGoleadores = crearNodoArbol(auxJugadorEquipo);

    else {
        if(auxJugadorEquipo.puntosAnotados > ptrArbolGoleadores->infoEquipoJugador.puntosAnotados) ptrArbolGoleadores->ptrDer = insertarJugadoresGoleadoresEnArbol(ptrArbolGoleadores->ptrDer, auxJugadorEquipo);

        else ptrArbolGoleadores->ptrIzq = insertarJugadoresGoleadoresEnArbol(ptrArbolGoleadores->ptrIzq, auxJugadorEquipo);
    }
    return ptrArbolGoleadores;
}

///Recorro cada Lista de jugadores por equipo y retorno el jugador con más goles anotados
stListaSecundaria *buscarJugadorGoleadorPorEquipo(stListaSecundaria *ptrListaJugadores) {

    stListaSecundaria *jugadorConMasGoles = ptrListaJugadores;
    ptrListaJugadores = ptrListaJugadores->ptrSiguiente;

    while(ptrListaJugadores != NULL) {

        if(jugadorConMasGoles->infoJugadores.puntosAnotados < ptrListaJugadores->infoJugadores.puntosAnotados) jugadorConMasGoles = ptrListaJugadores;

        ptrListaJugadores = ptrListaJugadores->ptrSiguiente;
    }
    return jugadorConMasGoles;
}

///Insertamos en el Árbol los jugadores con más goles de cada equipo
stArbolGoleadores *cargarArbolConGoleadoresDeEquipos(stListaPpal *ptrListaEquipos, stArbolGoleadores *ptrArbolGoleadores) {

    stJugadorEquipo auxRegistro;
    stListaPpal *auxListaEquipos = ptrListaEquipos;

    while(auxListaEquipos != NULL) {

        ///Retornamos el nodo Con el jugador con más goles
        stListaSecundaria *jugadorConMasGoles = buscarJugadorGoleadorPorEquipo(auxListaEquipos->ptrListaJugadores);

        ///Guardo los datos del jugador con más goles en la variable AuxRegistro
        strcpy(auxRegistro.nombreEquipo, auxListaEquipos->infoEquipo.nombreEquipo);
        auxRegistro.idEquipo = auxListaEquipos->infoEquipo.idEquipo;
        strcpy(auxRegistro.nombreJugador, jugadorConMasGoles->infoJugadores.nombreJugador);
        auxRegistro.idJugador = jugadorConMasGoles->infoJugadores.idJugador;
        auxRegistro.nroCamiseta = jugadorConMasGoles->infoJugadores.nroCamiseta;
        auxRegistro.puntosAnotados = jugadorConMasGoles->infoJugadores.puntosAnotados;

        ///Inserto en el arbol el Jugador con más goles de cada equipo
        ptrArbolGoleadores = insertarJugadoresGoleadoresEnArbol(ptrArbolGoleadores, auxRegistro);

        ///Avanzo de Nodo en la Lista de Equipos
        auxListaEquipos = auxListaEquipos->ptrSiguiente;
    }
    return ptrArbolGoleadores;
}

///Mostramos el Árbol de goleadores in Oreden
void mostrarArbolGoleadoresEnOrden(stArbolGoleadores *ptrArbolGoleadores) {

    if(ptrArbolGoleadores != NULL) {

        mostrarArbolGoleadoresEnOrden(ptrArbolGoleadores->ptrIzq);

        printf("EQUIPO: %s \n", ptrArbolGoleadores->infoEquipoJugador.nombreEquipo);
        printf("ID EQUIPO: %i \n", ptrArbolGoleadores->infoEquipoJugador.idEquipo);
        printf("JUGADOR: %s \n", ptrArbolGoleadores->infoEquipoJugador.nombreJugador);
        printf("ID JUGADOR: %i \n", ptrArbolGoleadores->infoEquipoJugador.idJugador);
        printf("NRO CAMISETA: %i \n", ptrArbolGoleadores->infoEquipoJugador.nroCamiseta);
        printf("GOLES: %i \n\n", ptrArbolGoleadores->infoEquipoJugador.puntosAnotados);

        mostrarArbolGoleadoresEnOrden(ptrArbolGoleadores->ptrDer);
    }
}

///Calculamos la cantidad de Jugadores por Equipo
int calcularTotalJugadoresEquipos(stListaSecundaria *ptrListaJugadores) {

    int cantidadJugadores = 0;

    while(ptrListaJugadores != NULL) {

        cantidadJugadores++;
        ptrListaJugadores = ptrListaJugadores->ptrSiguiente;
    }
    return cantidadJugadores;
}

///Función que calcula la cantidad total de jugadores en base a la función que calcula la cantidad de jugadores por equipo
int calcularCantidadTotalJugadores(stListaPpal *ptrListaEquipos) {

    int cantidadTotalJugadores = 0;

    while(ptrListaEquipos != NULL) {

        cantidadTotalJugadores =  cantidadTotalJugadores + calcularTotalJugadoresEquipos(ptrListaEquipos->ptrListaJugadores);
        ptrListaEquipos = ptrListaEquipos->ptrSiguiente;
    }
    return cantidadTotalJugadores;
}

///Función que calcula el porcentaje de cada Equipo
void calcularPorcentajeTorneo(stListaPpal *ptrListaEquipos) {

    int cantidadJugadoresPorEquipo = 0;
    float porcentajePorEquipo = 0;


    int cantidadTotalJugadores = calcularCantidadTotalJugadores(ptrListaEquipos);
    printf("Cantidad total de jugadores registrados en el torneo es |%i| \n\n", cantidadTotalJugadores);


    while(ptrListaEquipos != NULL) {

        cantidadJugadoresPorEquipo = calcularTotalJugadoresEquipos(ptrListaEquipos->ptrListaJugadores);
        printf("Cantidad de jugadores del Equipo |%s| es de |%i| \n",ptrListaEquipos->infoEquipo.nombreEquipo, cantidadJugadoresPorEquipo);
        porcentajePorEquipo = (float)cantidadJugadoresPorEquipo/cantidadTotalJugadores;
        printf("Porcentaje de Jugadores del equipo |%s| es de |%.2f Porciento| \n\n",ptrListaEquipos->infoEquipo.nombreEquipo, porcentajePorEquipo);

        ptrListaEquipos = ptrListaEquipos->ptrSiguiente;
    }
}

void copiarAuxJugadorEquipo( stJugadorEquipo *auxJugadorEquipo, stEquipo auxEquipo, stJugador auxJugador) {

    strcpy(auxJugadorEquipo->nombreEquipo, auxEquipo.nombreEquipo);
    auxJugadorEquipo->idEquipo = auxEquipo.idEquipo;
    strcpy(auxJugadorEquipo->nombreJugador, auxJugador.nombreJugador);
    auxJugadorEquipo->idJugador = auxJugador.idJugador;
    auxJugadorEquipo->nroCamiseta = auxJugador.nroCamiseta;
    auxJugadorEquipo->puntosAnotados = auxJugador.puntosAnotados;
}

void pasarDeLaListaAlArchivo(char nombreArchivo[], stListaPpal *ptrListaEquipos, int nroCamiseta) {

    stJugadorEquipo auxJugadorEquipo;

    FILE *ptrArchivo = fopen(nombreArchivo, "ab");

    if(ptrArchivo == NULL) printf("Error al abrir el Archivo \n\n");

    else {
        while(ptrListaEquipos != NULL) {

            while(ptrListaEquipos->ptrListaJugadores != NULL) {

                if(ptrListaEquipos->ptrListaJugadores->infoJugadores.nroCamiseta == nroCamiseta) {

                    copiarAuxJugadorEquipo(&auxJugadorEquipo, ptrListaEquipos->infoEquipo, ptrListaEquipos->ptrListaJugadores->infoJugadores);
                    fwrite(&auxJugadorEquipo, sizeof(stJugadorEquipo), 1, ptrArchivo);
                }
                ptrListaEquipos->ptrListaJugadores = ptrListaEquipos->ptrListaJugadores->ptrSiguiente;
            }
            ptrListaEquipos = ptrListaEquipos->ptrSiguiente;
        }
        fclose(ptrArchivo);
    }
}
