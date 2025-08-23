#include "SistemaDeAudio.h"
#include "Personaje.h"
#include <iostream>

void SistemaDeAudio::onNotify(const Personaje& personaje, Evento evento)
{
	switch (evento) {
		case Evento::PERSONAJE_SALTA:
			std::cout << "[AUDIO] Reproduciendo sonido de salto" << std::endl;
			break;
		case Evento::PERSONAJE_DISPARA:
			std::cout << "[AUDIO] Reproduciendo sonido de disparo" << std::endl;
			break;
		case Evento::PERSONAJE_RECIBE_DANO:
			std::cout << "[AUDIO] Notificado sobre PERSONAJE_RECIBE_DANO." << std::endl;
			break;
	}
}