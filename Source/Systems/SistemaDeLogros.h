/**
 * @file SistemaDeLogros.h
 * @brief Parte del portafolio de patrones. Define SistemaDeLogros.
 */
#pragma once
#include "../Patterns/Observer/IObserver.h"
 /**
  * @brief Sistema de Logros que reacciona a eventos del Personaje.
  */
class SistemaDeLogros : public IObserver
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;
};

