// Tarea 1 Grupo10
#include <iostream>
#include <cstring>
#include <cctype>

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

    void crearPregunta(char* nivelTaxonomia) {
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