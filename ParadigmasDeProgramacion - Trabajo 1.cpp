// Tarea 1 Grupo10
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PREGUNTAS = 100;
const int MAX_ITEMS = 10;
const int MAX_TIPO = 8;

class Pregunta {
public:
    char enunciado[200];
    char respuesta[100];
    char tipo[50];
    int anio;
    int tiempo;

    Pregunta() {
        strcpy(enunciado, "");
        strcpy(respuesta, "");
        strcpy(tipo, "");
        anio = 0;
        tiempo = 0;
    }

    void crearPregunta(const char* nivelTaxonomia) {
        cout << "Seleccione el tipo de pregunta:\n";
        cout << "a) Composicion y ensayo\n";
        cout << "b) Respuesta corta\n";
        cout << "c) Texto incompleto\n";
        cout << "d) Correspondencia\n";
        cout << "e) Opcion multiple\n";
        cout << "f) Verdadero/Falso\n";
        cout << "g) Analogias/Diferencias\n";
        cout << "h) Graficos/Mapas\n";
        cout << "Seleccione una opcion (a-h): ";
        char op;
        cin >> op;
        cin.ignore();
        switch (op) {
            case 'a': strcpy(tipo, "Composicion y ensayo"); break;
            case 'b': strcpy(tipo, "Respuesta corta"); break;
            case 'c': strcpy(tipo, "Texto incompleto"); break;
            case 'd': strcpy(tipo, "Correspondencia"); break;
            case 'e': strcpy(tipo, "Opcion multiple"); break;
            case 'f': strcpy(tipo, "Verdadero/Falso"); break;
            case 'g': strcpy(tipo, "Analogias/Diferencias"); break;
            case 'h': strcpy(tipo, "Graficos/Mapas"); break;
            default: strcpy(tipo, "Desconocido"); break;
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

        cout << "Ingrese el tiempo estimado en minutos: ";
        cin >> tiempo;
        cin.ignore();
    }

    void mostrar() {
        
        cout << "Tipo: " << tipo << "\n";
        cout << "Enunciado: " << enunciado << "\n";
        cout << "Anio: " << anio << "\n";
        cout << "Respuesta: " << respuesta << "\n";
        cout << "Tiempo: " << tiempo << " min\n";
    }
};

class Item {
public:
    char nivel[50];
    Pregunta preguntas[MAX_PREGUNTAS];
    int totalPreguntas;

    Item() {
        strcpy(nivel, "");
        totalPreguntas = 0;
    }

    void setNivel(const char* n) {
        strcpy(nivel, n);
    }

    void agregarPregunta(int& contadorGlobal, int maxTotal) {
        if (contadorGlobal >= maxTotal) {
            cout << "Se ha alcanzado el limite total de preguntas.\n";
            return;
        }
//Validación extra que puede ser eliminada
        if (totalPreguntas >= MAX_PREGUNTAS) {
            cout << "Se ha alcanzado el limite de preguntas por item.\n";
            return;
        }

        preguntas[totalPreguntas].crearPregunta(nivel);
        totalPreguntas++;
        contadorGlobal++;
    }

    void mostrarPreguntas() {
        cout << "\nNivel Taxonomia: " << nivel << "\n";
        for (int i = 0; i < totalPreguntas; i++) {
            cout << "\nPregunta #" << i + 1 << ":\n";
            preguntas[i].mostrar();
        }
    }
};

class Evaluacion {
private:
    Item items[MAX_ITEMS];
    int totalItems;
    int preguntasTotales;
    int contadorPreguntas;

public:
    Evaluacion() {
        totalItems = 0;
        preguntasTotales = 0;
        contadorPreguntas = 0;
    }

    void generar() {
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

    void menuItems() {
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

    void crearPreguntaEnItem() {
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

    void consultarItems() {
        char buscarItem[50]; 
        cout << "Ingresa el #item a consultar: (1 a " << totalItems << ")" << endl;
        cin.getline(buscarItem, 50);
        int numeroItem = stoi(buscarItem);
        if (numeroItem >= 1 && numeroItem <= totalItems) {
           cout << "\nItem #" << numeroItem << ":\n";
           items[numeroItem].mostrarPreguntas();
        } else {
           cout << "Por favor ingresa un número valido entre 1 y " << totalItems << "." << endl;}
    }

    void buscarItem() {
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
    
    void imprimirEvaluacion() {
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
};

int main() {
    Evaluacion evaluacion;
    bool salir = false;

    while (!salir) {
        cout << "\nMenu Principal\n";
        cout << "1. Generar Evaluacion\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        int opcion;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                evaluacion.generar();
                break;
            case 2:
                salir = true;
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}