// ¿Recuerdas qué hace iostream? 
// Permite la entrada y salida de datos estándar en C++ (std::cout y std::cin).

#include <iostream>

// ¿Por qué este include usa comillas y no < >?
// Usa comillas " " porque es un archivo local del proyecto y no una librería estándar del sistema.

#include "utilerias.h"

// ¿por qué debe existir la función main()?
// Porque es el punto de entrada obligatorio donde el sistema operativo inicia la ejecución del programa.

int main() {
    // 1. Constante: cantidad de números a leer
    const int CANTIDAD = 5;

    // 2. Arreglo y contador (siempre inicializados)
    // TODO: declara el arreglo pares. ¿De qué tamaño en el peor caso?
    int pares[CANTIDAD]; 

    // TODO: declara totalPares. ¿Con qué valor empieza?
    int totalPares = 0;

    std::cout << "Guardar los numeros pares de " << CANTIDAD << " numeros\n";

    // 3. Ciclo: leer CANTIDAD números
    for (int contador = 0; contador < CANTIDAD; contador++) {
        // TODO: lee cada número con leerEntero("Escribe un numero: ")
        int numero = leerEntero("Escribe un numero: ");

        // TODO: si el número es par, guárdalo en la siguiente posición libre
        // ¿Qué variable te dice cuál es la siguiente posición libre? 
        // La variable 'totalPares' nos indica la siguiente posición libre.
        if (numero % 2 == 0) {
            pares[totalPares] = numero;
            totalPares++;
        }
    }

// 4. Salida (Versión final correcta)
    std::cout << "\nPares encontrados: " << totalPares << "\n";

    // Recorremos ÚNICAMENTE hasta totalPares
    for (int i = 0; i < totalPares; i++) {
        std::cout << "Par [" << i << "]: " << pares[i] << "\n";
    }
    return 0;
}
