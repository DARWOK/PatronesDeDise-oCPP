/**
 * @file SistemaDeAudio.h
 * @brief Parte del portafolio de patrones. Define SistemaDeAudio.
 */
#pragma once
#include "../Patterns/Observer/IObserver.h"
#include "../Patterns/SoundEvent/SoundEvent.h"

 /**
  * @brief Sistema de Audio con Observer + Event Queue filtrada.
  */
class SistemaDeAudio : public IObserver
{
public:
	/**
	 * @brief Responde a eventos del Personaje (Observer sincrono).
	 * @param personaje Referencia constante al emisor.
	 * @param evento Tipo de evento emitido.
	 */
	void onNotify(const Personaje& personaje, Evento evento) override;

	SistemaDeAudio() : numPending_(0) {}
	/**
	 * @brief Encola una solicitud de sonido para procesarse al final del frame.
	 * @param evento Evento de sonido a encolar.
	 */
	void solicitarSonido(SoundEvent evento);
	/**
	 * @brief Filtra duplicados y reproduce una sola vez cada sonido por frame.
	 * Reinicia la cola al terminar.
	 */
	void procesarEventos();

private:
	static const int MAX_PENDING = 16;
	SoundEvent pending_[MAX_PENDING];
	int numPending_;
	static const char* toString(SoundID id);
};

