# 🧠 Generador de Evaluaciones - Grupo 10

Este proyecto en C++ permite crear evaluaciones académicas estructuradas en ítems según los niveles de la **Taxonomía de Bloom**. Cada ítem puede contener múltiples preguntas de distintos tipos, con tiempos asignados automáticamente según el nivel cognitivo requerido.

## 📚 Funcionalidades

- Crear evaluaciones compuestas por varios ítems.
- Asignar a cada ítem un nivel taxonómico (de Recordar a Crear).
- Agregar distintos tipos de preguntas según el nivel taxonómico:
  - Respuesta corta
  - Correspondencia
  - Texto incompleto
  - Opción múltiple
  - Verdadero/Falso
  - Analogías / Gráficos / Ensayo
- Calcular automáticamente el tiempo estimado para responder cada pregunta.
- Consultar ítems y preguntas individualmente.
- Ver evaluación completa.

## 🧮 Niveles Taxonómicos

| Nivel | Nombre       | Tiempo estimado por pregunta |
|-------|--------------|------------------------------|
| 1     | Recordar     | 1 minuto                     |
| 2     | Comprender   | 2 minutos                    |
| 3     | Aplicar      | 3 minutos                    |
| 4     | Analizar     | 4 minutos                    |
| 5     | Evaluar      | 5 minutos                    |
| 6     | Crear        | 8 minutos                    |

## ▶️ Uso del Programa

1. Ejecuta el programa.
2. Ingresa la cantidad total de preguntas y la cantidad de ítems a incluir.
3. Define el nivel taxonómico para cada ítem.
4. Desde el menú interactivo, puedes:
   - Agregar preguntas a un ítem.
   - Consultar preguntas por ítem.
   - Buscar ítems por nivel taxonómico.
   - Imprimir la evaluación completa.
   - Finalizar el programa.

## 💡 Estructura del Código

El programa se basa en 3 clases principales:

- **Pregunta**: almacena enunciado, respuesta, tipo, año y tiempo estimado.
- **Item**: contiene un nivel taxonómico y un conjunto de preguntas.
- **Evaluacion**: administra múltiples ítems y controla el flujo del sistema.

## 📌 Requisitos

- Compilador C++ compatible con el estándar C++11 o superior.
- Terminal de entrada/salida para interacción por consola.

## 🛠️ Compilación

Puedes compilar el código usando `g++`:

```bash
g++ -o evaluador main.cpp
./evaluador

## Autores

 - Ricardo Henriquez
 - Benja Rojas
 - Paulo Maldonado