#pragma once
#include <iostream>

class Personaje; // Forward declaration to avoid circular dependency

enum class Evento
{
	PERSONAJE_SALTA,
	PERSONAJE_DISPARA,
	PERSONAJE_RECIBE_DANO
};

class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void onNotify(const Personaje& personaje, Evento evento) = 0;
};

