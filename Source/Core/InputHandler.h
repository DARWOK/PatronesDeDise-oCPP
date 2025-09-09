/**
 * @file InputHandler.h
 * @brief Mapeo de teclas a comandos (patrón Command) y utilidades de remapeo.
 */

#pragma once  
#include "..\Patterns/Command/Command.h"  
#include <string>  

 /**
  * @brief Gestiona la asignación de teclas a instancias de Command.
  * Permite remapear acciones en tiempo de ejecución sin acoplar la lógica de input con la lógica de juego.
  */

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* handleInput(char tecla);

	/**
	 * @brief Remapea una tecla a una nueva acción de comando.
	 * @param tecla El carácter de la tecla a remapear (ej. 'w').
	 * @param accion El nombre de la acción a asignar (ej. "saltar", "disparar").
	 */

	void remapearTecla(char tecla, const std::string& accion);
private:
	Command* cmdSaltar_;
	Command* cmdDisparar_;
	Command* cmdCrouchear_;

	Command* botonW_;
	Command* botonF_;
	Command* botonE_;
};
