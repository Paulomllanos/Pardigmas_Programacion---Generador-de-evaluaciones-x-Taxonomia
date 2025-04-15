#ifndef ITEM_H
#define ITEM_H

#include "Pregunta.h"
// Clase de Item
class Item {
public:
    char nivel[50];
    Pregunta preguntas[100];
    int totalPreguntas;

    Item();
    void setNivel(const char* n);
    void agregarPregunta(int& contadorGlobal, int maxTotal);
    void mostrarPreguntas();
};

#endif