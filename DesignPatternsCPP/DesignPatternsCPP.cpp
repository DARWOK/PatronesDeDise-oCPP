// DesignPatternsCPP.cpp : punto de entrada de la demo de consola.
#include <iostream>
#include "Personaje.h"
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
    printHelp();

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
