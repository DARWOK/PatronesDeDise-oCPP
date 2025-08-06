#include "InputHandler.h"
#include <iostream>
#include <algorithm>

InputHandler::InputHandler()
{
    cmdSaltar_ = new SaltarCommand();
    cmdDisparar_ = new DispararCommand();
    cmdCrouchear_ = new CrouchCommand();

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
    if (tecla == 'e') return botonE_;

    // Si no es una tecla mapeada, no devolvemos ningún comando
    return nullptr;
}

void InputHandler::remapearTecla(char tecla, const std::string& accion)
{
    // Normalizar acción a minúsculas
    std::string a = accion;
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);

    Command* nuevo = nullptr;
    if (a == "saltar")      nuevo = cmdSaltar_;
    else if (a == "disparar") nuevo = cmdDisparar_;
    else if (a == "agacharse") nuevo = cmdCrouchear_;
    else
    {
        std::cout << "Acción \"" << accion << "\" no reconocida.\n";
        return;
    }

    // Remapear la tecla indicada
    if (tecla == 'w')       botonW_ = nuevo;
    else if (tecla == 'f')  botonF_ = nuevo;
    else if (tecla == 'e')  botonE_ = nuevo;
    else
    {
        std::cout << "Tecla '" << tecla << "' no válida para remapear.\n";
        return;
    }

    std::cout << "Tecla '" << tecla << "' remapeada a acción \"" << a << "\" correctamente.\n";
}