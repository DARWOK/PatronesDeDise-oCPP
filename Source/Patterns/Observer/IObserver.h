/**
 * @file IObserver.h
 * @brief Parte del portafolio de patrones. Define IObserver.
 */
#pragma once
#include <iostream>

class Personaje; // Forward declaration to avoid circular dependency

enum class Evento
{
	PERSONAJE_SALTA,
	PERSONAJE_DISPARA,
	PERSONAJE_RECIBE_DANO
};

/**
 * @brief Interfaz Observer para notificaciones 1-a-muchos.
 */
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void onNotify(const Personaje& personaje, Evento evento) = 0;
};

