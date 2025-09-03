#include "Systems/SistemaDeLogros.h"
#include "Core/Personaje.h"
#include <iostream>

void SistemaDeLogros::onNotify(const Personaje& /*personaje*/, Evento evento) {
	if (evento == Evento::PERSONAJE_RECIBE_DANO) {
		std::cout << "[LOGROS] Notificado sobre PERSONAJE_RECIBE_DANO. "
			"Logro 'Primer Golpe' desbloqueado!\n";
	}
}