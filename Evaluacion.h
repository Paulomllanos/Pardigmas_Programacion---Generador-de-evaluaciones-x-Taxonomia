#ifndef EVALUACION_H
#define EVALUACION_H

#include "Item.h"

class Evaluacion {
private:
    Item items[10];
    int totalItems;
    int preguntasTotales;
    int contadorPreguntas;

public:
    Evaluacion();
    void generar();
    void menuItems();
    void crearPreguntaEnItem();
    void consultarItems();
    void buscarItem();
    void imprimirEvaluacion(); // Puedes agregar esta definición si la completas
};

#endif