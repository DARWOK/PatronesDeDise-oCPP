#include "InputHandler.h"

InputHandler::InputHandler()
{
    // Al crear el InputHandler, creamos las instancias de nuestros comandos
    botonW_ = new SaltarCommand();
    botonF_ = new DispararCommand();
    botonE_ = new CrouchCommand();
}

InputHandler::~InputHandler()
{
    // Es crucial liberar la memoria que asignamos para evitar memory leaks
    delete botonW_;
    delete botonF_;
    delete botonE_;
}

Command* InputHandler::handleInput(char tecla)
{
    if (tecla == 'w') return botonW_;
    if (tecla == 'f') return botonF_;
    if (tecla == 'i') return botonE_;

    // Si no es una tecla mapeada, no devolvemos ningún comando
    return nullptr;
}