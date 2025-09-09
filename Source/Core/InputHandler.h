/**
 * @file InputHandler.h
 * @brief Mapeo de teclas a comandos (patr�n Command) y utilidades de remapeo.
 */

#pragma once  
#include "..\Patterns/Command/Command.h"  
#include <string>  

 /**
  * @brief Gestiona la asignaci�n de teclas a instancias de Command.
  * Permite remapear acciones en tiempo de ejecuci�n sin acoplar la l�gica de input con la l�gica de juego.
  */

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* handleInput(char tecla);

	/**
	 * @brief Remapea una tecla a una nueva acci�n de comando.
	 * @param tecla El car�cter de la tecla a remapear (ej. 'w').
	 * @param accion El nombre de la acci�n a asignar (ej. "saltar", "disparar").
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
