// DesignPatternsCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Personaje.h"
#include "InputHandler.h"

int main()
{
	char tecla;
	Personaje* personaje = new Personaje(20,20,10,10,10);
    InputHandler inputHandler;

    std::cout << "=======================================\n";
    std::cout << "Bienvenido al juego (Patron Command)\n";
    std::cout << "Controles: 'w' = Saltar, 'f' = Disparar, 'e' = Agacharse\n";
    std::cout << "Presiona 'r' para entrar en Modo Remapeo\n";
    std::cout << "=======================================\n";
	
	// Update
	while (true)
	{
        std::cout << "\nIngresa una tecla: ";
        std::cin >> tecla;

        if (tecla == 'r')
        {
            std::cout << "¿Que tecla quieres remapear? ";
            char t; std::cin >> t;
            std::cout << "¿A que accion? (saltar, disparar, agacharse): ";
            std::string accion; std::cin >> accion;
            inputHandler.remapearTecla(t, accion);
        }
        else
        {
            Command* cmd = inputHandler.handleInput(tecla);
            if (cmd)
                cmd->execute(*personaje);
            else
                std::cout << "=======================================\n"
                << "Tecla no valida\n"
                << "=======================================\n";
        }
        std::cout << "\n\n************* Next Frame ***********\n";
	}
    delete personaje;
    return 0;
}