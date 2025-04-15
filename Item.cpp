#include "Item.h"
#include <iostream>
#include <cstring>

using namespace std;

Item::Item() {
    strcpy(nivel, "");
    totalPreguntas = 0;
}
// permite setear el nivel de taxonomia
void Item::setNivel(const char* n) {
    strcpy(nivel, n);
}
// Agrega una pregunta al item que corresponde y lleva la cuenta de cuantas preguntas se han agregado con relación al total
void Item::agregarPregunta(int& contadorGlobal, int maxTotal) {
    if (contadorGlobal >= maxTotal) {
        cout << "Se ha alcanzado el limite total de preguntas.\n";
        return;
    }

    if (totalPreguntas >= 100) {
        cout << "Se ha alcanzado el limite de preguntas por item.\n";
        return;
    }

    preguntas[totalPreguntas].crearPregunta(nivel);
    totalPreguntas++;
    contadorGlobal++;
}
// muestra las preguntas del item
void Item::mostrarPreguntas() {
    cout << "\nNivel Taxonomia: " << nivel << "\n";
    for (int i = 0; i < totalPreguntas; i++) {
        cout << "\nPregunta #" << i + 1 << ":\n";
        preguntas[i].mostrar();
    }
}