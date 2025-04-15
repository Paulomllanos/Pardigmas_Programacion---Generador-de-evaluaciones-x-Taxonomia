#ifndef PREGUNTA_H
#define PREGUNTA_H

//Se crea la clase de pregunta con sus métodos
class Pregunta {
public: //atributos publicos
    char enunciado[200];
    char respuesta[100];
    char tipo[50];
    int anio;
    int tiempo;
    // metodos
    Pregunta();
    void crearPregunta(char* nivelTaxonomia);
    void mostrar();
};

#endif