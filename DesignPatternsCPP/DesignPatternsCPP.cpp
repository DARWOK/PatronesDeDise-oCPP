// DesignPatternsCPP.cpp : punto de entrada de la demo de consola.
#include <iostream>
#include "Personaje.h"
#include "SistemaDeLogros.h"
#include "SistemaDeAudio.h"
// Dejamos InputHandler y Command en el proyecto por compatibilidad, pero no se usan en esta tarea.

static void printHelp()
{
    std::cout << "=======================================\n";
    std::cout << "Controles: 'w' = Saltar, 'f' = Atacar, 'q' = Salir\n";
    std::cout << "Cada entrada procesa un frame: primero handleInput(), luego update().\n";
    std::cout << "Estados: IDLE, JUMPING, ATTACKING. Tras 2 updates, vuelve a IDLE.\n";
    std::cout << "=======================================\n";
}

int main()
{
    Personaje personaje; // por defecto

    // --- Demo del Patron Observer ---
    SistemaDeLogros logros;
    SistemaDeAudio  audio;
    personaje.agregarObserver(&logros);
    personaje.agregarObserver(&audio);

    std::cout << "== Disparando evento de dano para demostrar Observer ==" << std::endl;
    personaje.recibirDano(10);
    std::cout << "== Fin de la demostracion Observer ==" << std::endl;

	// --------------------------------

	printHelp(); // Instrucciones de teclas disponibles. Estados agregados: IDLE, JUMPING, ATTACKING.
    // Puedo agregar más estados y teclas según requiera, por ahora funciona todo... creo...

    while (true) {
        std::cout << "\nEstado actual: " << personaje.stateName() << "\n";
        std::cout << "Ingresa tecla: ";

        char tecla = '\0';
        std::cin >> tecla;
        if (!std::cin) break;
        if (tecla == 'q') break;

        // 1) Gestionar input según el estado actual (FSM)
        personaje.handleInput(tecla);

        // 2) Avanzar simulación un frame
        personaje.update();

        std::cout << "---------------------------------------\n";
    }

    std::cout << "Fin.\n";
    return 0;
} 
