#pragma once
#include "Core/Personaje.h"

class Command
{
public:
	virtual ~Command();
	virtual void execute(Personaje& personaje) = 0; //Quiere decir que no tiene implementacin propia, se debe hacer en la clase que herede
};

// Comando concreto para la accin de Saltar
class SaltarCommand : public Command
{
public:
	virtual void execute(Personaje& personaje) override
	{
		personaje.Saltar();
	}
};

// Comando concreto para la accin de Disparar
class DispararCommand : public Command
{
public:
	virtual void execute(Personaje& personaje) override
	{
		personaje.Disparar(); // Llama a la accin especfica en el personaje
	}
};

class CrouchCommand : public Command
{
public:
	virtual void execute(Personaje& personaje) override
	{
		personaje.Crouchear(); // Llama a la accin especfica en el personaje
	}
};
