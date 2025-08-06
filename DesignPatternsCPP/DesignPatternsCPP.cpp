// DesignPatternsCPP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Personaje.h"
#include "InputHandler.h"

int main()
{
	char tecla;
	Personaje* personaje = new Personaje(20,20,10,10,10);
    InputHandler inputHandler;

	std::cout << "=========================\n";
	std::cout << "Bienvenido al juego!\n";
    std::cout << "Controles: 'w' = Saltar, 'f' = Disparar\n";
	std::cout << "Aprieta una tecla para jugar\n";
	std::cout << "=========================\n";
	
	// Update
	while (true)
	{
        std::cin >> tecla;

        // Pasamos la tecla al InputHandler para obtener un comando
        Command* command = inputHandler.handleInput(tecla);

        if (command != nullptr)
        {
            command->execute(*personaje); // El bucle principal no sabe qué acción se ejecuta, solo ejecuta el comando.
        }
        else
        {
            std::cout << "=======================================\n";
            std::cout << "Esa tecla no es valida\n";
            std::cout << "=======================================\n";
        }

        std::cout << "\n\n\n*************Next Frame***********\n";
        tecla = ' ';
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
