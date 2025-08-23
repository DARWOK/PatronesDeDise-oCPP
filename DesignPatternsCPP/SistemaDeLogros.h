#pragma once
#include "IObserver.h"
class SistemaDeLogros : public IObserver
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;
};

