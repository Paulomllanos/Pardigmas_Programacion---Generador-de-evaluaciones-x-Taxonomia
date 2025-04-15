#include "Pregunta.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
//Se llama
Pregunta::Pregunta() {
    strcpy(enunciado, "");
    strcpy(respuesta, "");
    strcpy(tipo, "");
    anio = 0;
    tiempo = 0;
}

void Pregunta::crearPregunta(char* nivelTaxonomia) { 
    //Permite crear una pregunta tomando en consideración el nivel de taxonomia de el item vs el nivel de taxonomia del tipo de la pregunta, luego recibe información del enunciado, año y se le asigna en tiempo respecto a su taxonomia (Tiempo a nivel promedio)
    cout << "Seleccione el tipo de pregunta:\n";
    char op;
    strcpy(tipo, "Desconocido"); //Incializar valor por defecto
    bool opcionValida = false;
    switch (atoi(nivelTaxonomia)) {
        case 1: 
            do {
                cout << "a) Respuesta corta\n";
                cout << "b) Correspondencia\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Respuesta corta");
                    opcionValida = true;
                } else if (op == 'b') {
                    strcpy(tipo, "Correspondencia");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        case 2:
            do {
                cout << "a) Texto incompleto\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Texto incompleto");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        case 3:
            do {
                cout << "a) Opcion multiple\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Opcion multiple");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        case 4:
            do {
                cout << "a) Analogias/Diferencias\n";
                cout << "b) Graficos/Mapas\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Analogias/Diferencias");
                    opcionValida = true;
                } else if (op == 'b') {
                    strcpy(tipo, "Graficos/Mapas");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        case 5:
            do {
                cout << "a) Composicion y ensayo\n";
                cout << "b) Verdadero/Falso\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Composicion y ensayo");
                    opcionValida = true;
                } else if (op == 'b') {
                    strcpy(tipo, "Verdadero/Falso");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        case 6:
            do {
                cout << "a) Graficos/Mapas\n";
                cout << "Seleccione una opcion: ";
                cin >> op;
                cin.ignore();
                op = tolower(op);

                if (op == 'a') {
                    strcpy(tipo, "Graficos/Mapas");
                    opcionValida = true;
                } else {
                    cout << "Opción inválida. Intente nuevamente.\n";
                }
            } while (!opcionValida);
            break;
        default:
            cout << "Nivel taxonómico inválido.\n";
            return;
    }

    cout << "Ingrese el enunciado: ";
    cin.getline(enunciado, 200);

    cout << "Ingrese el anio de la pregunta: ";
    cin >> anio;
    cin.ignore();
    //condicional para las ocpiones multiples y verdadero/falso
    if (strcmp(tipo, "Opcion multiple") == 0) {
        cout << "Ingrese las alternativas (por ejemplo: a) opción A, b) opción B...):\n";
        char alternativas[200];
        cin.getline(alternativas, 200);

        strcat(enunciado, "\nAlternativas: ");
        strcat(enunciado, alternativas);

        cout << "Ingrese la respuesta correcta: ";
        cin.getline(respuesta, 100);

    } else if (strcmp(tipo, "Verdadero/Falso") == 0) {
        cout << "Ingrese la respuesta (V o F): ";
        cin.getline(respuesta, 100);

        char justificacion[200];
        cout << "Ingrese la justificación: ";
        cin.getline(justificacion, 200);

        strcat(respuesta, " - Justificación: ");
        strcat(respuesta, justificacion);

    } else {
        cout << "Ingrese la respuesta: ";
        cin.getline(respuesta, 100);
    }

    // Asignación automática del tiempo según nivel taxonómico
    switch (atoi(nivelTaxonomia)) {
        case 1: tiempo = 1; break;                 // Recordar: 0.5 a 1 min
        case 2: tiempo = 2; break;                 // Comprender: 1 a 2 min
        case 3: tiempo = 3; break;                 // Aplicar: 2 a 3 min
        case 4: tiempo = 4; break;                 // Analizar: 3 a 4 min
        case 5: tiempo = 5; break;                 // Evaluar: 4 a 5 min
        case 6: tiempo = 8; break;                 // Crear: 6 a 10 min (promedio 8)
        default: tiempo = 1; break;                // Valor por defecto
    }
}

void Pregunta::mostrar() { //Muestra información de la pregunta
    cout << "Tipo: " << tipo << "\n";
    cout << "Enunciado: " << enunciado << "\n";
    cout << "Anio: " << anio << "\n";
    cout << "Respuesta: " << respuesta << "\n";
    cout << "Tiempo: " << tiempo << " min\n";
}