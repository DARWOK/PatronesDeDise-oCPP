#include "Systems/SistemaDeAudio.h"
#include "Core/Personaje.h"
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

void SistemaDeAudio::solicitarSonido(SoundEvent evento) {
	if (numPending_ >= MAX_PENDING) {
		std::cout << "[AUDIO][WARN] Cola llena. Evento descartado.\n";
		return;
	}
	pending_[numPending_++] = evento;
}

void SistemaDeAudio::procesarEventos() {
	// Filtrado de duplicados
	SoundEvent unicos[MAX_PENDING];
	int numUnicos = 0;

	for (int i = 0; i < numPending_; ++i) {
		SoundEvent cur = pending_[i];
		bool existe = false;
		for (int j = 0; j < numUnicos; ++j) {
			if (unicos[j] == cur) { existe = true; break; }
		}
		if (!existe) {
			unicos[numUnicos++] = cur;
		}
	}

	// Procesamiento
	for (int i = 0; i < numUnicos; ++i) {
		std::cout << "[AUDIO] Procesando... Reproduciendo sonido " << toString(unicos[i].id) << ".\n";
	}

	// Limpieza
	numPending_ = 0;
}

const char* SistemaDeAudio::toString(SoundID id)
{
	switch (id) {
	case SoundID::HIT:  return "HIT";
	case SoundID::JUMP: return "JUMP";
	case SoundID::DEATH:return "DEATH";
	default:            return "UNKNOWN";
	}
}