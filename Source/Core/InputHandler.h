#pragma once  
#include "Patterns/Command/Command.h"  
#include <string>  

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* handleInput(char tecla);
	void remapearTecla(char tecla, const std::string& accion);
private:
	Command* cmdSaltar_;
	Command* cmdDisparar_;
	Command* cmdCrouchear_;

	Command* botonW_;
	Command* botonF_;
	Command* botonE_;
};
