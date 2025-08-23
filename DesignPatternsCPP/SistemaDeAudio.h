#pragma once
#include "IObserver.h"

class SistemaDeAudio : public IObserver
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;
};

