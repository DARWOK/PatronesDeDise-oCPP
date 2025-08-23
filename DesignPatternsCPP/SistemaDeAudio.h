#pragma once
#include "IObserver.h"
#include "SoundEvent.h"

class SistemaDeAudio : public IObserver
{
public:
	void onNotify(const Personaje& personaje, Evento evento) override;
	
	SistemaDeAudio() : numPending_(0) {}
	void solicitarSonido(SoundEvent evento);
	void procesarEventos();

private:
	static const int MAX_PENDING = 16;
	SoundEvent pending_[MAX_PENDING];
	int numPending_;
	static const char* toString(SoundID id);
};

