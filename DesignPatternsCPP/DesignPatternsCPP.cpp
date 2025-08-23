// DesignPatternsCPP.cpp : punto de entrada de la demo de consola.
#include <iostream>
#include "Personaje.h"
#include "SistemaDeLogros.h"
#include "SistemaDeAudio.h"
#include "SoundEvent.h"
// Dejamos InputHandler y Command en el proyecto por compatibilidad.

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
    SistemaDeAudio audioSystem;


    // --- Demo del Patron Observer ---
    SistemaDeLogros logros;
    SistemaDeAudio  audio;
    personaje.agregarObserver(&logros);
    personaje.agregarObserver(&audio);

    std::cout << "== Disparando evento de damage para demostrar Observer ==" << std::endl;
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

        // --- Event Queue demo: solicitamos sonidos (con duplicados) y luego procesamos ---
        audioSystem.solicitarSonido({ SoundID::HIT });
        audioSystem.solicitarSonido({ SoundID::JUMP });
        audioSystem.solicitarSonido({ SoundID::HIT });  // Duplicado
        audioSystem.solicitarSonido({ SoundID::HIT });  // Duplicado
        std::cout << "--- Fin del Frame de Logica ---\n";
        audioSystem.procesarEventos();
        // -------------------------------------------------------------------------------
		// Ya testeado puedo agregar más sonidos y eventos según requiera el juego y se manejan perfectamente los duplicados.
		// Por ahora solo tenemos HIT y JUMP, hice testeo anteriormente con 10 solicitudes de HIT y 5 de JUMP y funcionó perfecto.
        // Dejo sólo 4 solicitudes para no saturar el código.


        std::cout << "---------------------------------------\n";
    }

    std::cout << "Fin.\n";
    return 0;
} 
