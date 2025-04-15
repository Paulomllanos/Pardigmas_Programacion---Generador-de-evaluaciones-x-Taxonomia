#include "Evaluacion.h"
#include <iostream>
#include <cstring>

using namespace std;

Evaluacion::Evaluacion() {
    totalItems = 0;
    preguntasTotales = 0;
    contadorPreguntas = 0;
}

void Evaluacion::generar() {
    // Lógica completa para generar la evaluación
    cout << "Ingrese cantidad total de preguntas: ";
    cin >> preguntasTotales;
    //Mantener o eliminarlo
    cout << "Ingrese cantidad de items: ";
    cin >> totalItems;
    cin.ignore();

    for (int i = 1; i <= totalItems; i++) {
        char nivel[50];
        cout << "Niveles de taxonomia: " << endl;
        
        cout << "1. Recordar\n2. Entender\n3. Aplicar\n4. Analizar\n5. Evaluar\n6. Crear" << endl;
        cout << "Ingrese el nivel de taxonomia del item #" << i << ": ";
        cin.getline(nivel, 50);
        items[i].setNivel(nivel);
    }

    menuItems();

}

void Evaluacion::menuItems() {
    // Menú con opciones de interacción
    bool salir = false;
    while (!salir) {
        cout << "\nMenu de Items\n";
        cout << "1. Crear pregunta en item\n";
        cout << "2. Consultar item\n";
        cout << "3. Buscar item por taxonomia\n";
        cout << "4. Ver evaluación completa\n";
        cout << "5. Finalizar evaluacion\n";
        cout << "Seleccione una opcion: ";
        int opcion;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                crearPreguntaEnItem();
                break;
            case 2:
                consultarItems();
                break;
            case 3:
                buscarItem();
                break;
            case 4:
                imprimirEvaluacion();
                break;
            case 5:
                salir = true;
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }
}

void Evaluacion::crearPreguntaEnItem() {
    // Seleccionar item y crear pregunta
    if (contadorPreguntas >= preguntasTotales) {
        cout << "Ya ha alcanzado el numero total de preguntas permitidas.\n";
        return;
    }

    cout << "Seleccione item (1 a " << totalItems << "): ";
    int idx;
    cin >> idx;
    cin.ignore();
    if (idx >= 0 && idx <= totalItems) {
        items[idx].agregarPregunta(contadorPreguntas, preguntasTotales);
    } else {
        cout << "Item invalido.\n";
    }
}

void Evaluacion::consultarItems() {
    // Consultar preguntas de un item
    char buscarItem[50]; 
    cout << "Ingresa el #item a consultar: (1 a " << totalItems << ")" << endl;
    cin.getline(buscarItem, 50);
    int numeroItem = stoi(buscarItem);
    if (numeroItem >= 1 && numeroItem <= totalItems) {
        cout << "\nItem #" << numeroItem << ":\n";
        items[numeroItem].mostrarPreguntas();
    } else {
        cout << "Por favor ingresa un número valido entre 1 y " << totalItems << "." << endl;
    }
}

void Evaluacion::buscarItem() {
    // Buscar item por nivel de taxonomía
    char nivel[50];
    cout << "Niveles de taxonomia: " << endl;
    cout << "1. Recordar\n2. Entender\n3. Aplicar\n4. Analizar\n5. Evaluar\n6. Crear" << endl;
    cout << "Ingrese nivel de taxonomia a buscar: ";
    cin.getline(nivel, 50);

    for (int i = 1; i <= totalItems; i++) {
        if (strcmp(items[i].nivel, nivel) == 0) {
            cout << "\nItem #" << i << ":\n";
            
            items[i].mostrarPreguntas();
        }
    }
}

void Evaluacion::imprimirEvaluacion() {
    int tiempoTotal = 0;
    cout << "\n=== EVALUACION COMPLETA ===\n";
    for (int i = 1; i <= totalItems; i++) {
        cout << "\nItem #" << i << " (Nivel: " << items[i].nivel << ")\n";
        for (int j = 0; j < items[i].totalPreguntas; j++) {
            cout << "\nPregunta #" << j + 1 << ":\n";
            items[i].preguntas[j].mostrar();
            tiempoTotal += items[i].preguntas[j].tiempo;
        }
    }
    cout << "\nTiempo total estimado de la evaluación: " << tiempoTotal << " minutos.\n";
}