#pragma once
#include <iostream>
#include "IObserver.h"

class Personaje
{
public:
    // Estados de la FSM
    enum class State { IDLE, JUMPING, ATTACKING };

public:
    // Constructores
    Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight);
    Personaje();
    ~Personaje() = default;

    // Nueva API de FSM
    // Gestiona la entrada según el estado actual y decide si cambiar de estado.
    void handleInput(char input);

    // Actualiza al personaje por "frame".
    // Si está en JUMPING o ATTACKING, regresa a IDLE tras un par de updates.
    void update();

    // Métodos existentes (quedan para compatibilidad con tareas previas)
    void Saltar();
    void Disparar();
    void Crouchear();

    // Utilidad
    const char* stateName() const;

    // Getters and Setters (existentes)
    float GetHealth();
    void SetHealth(float health);
    float GetMaxHealth();
    void SetMaxHealth(float maxHealth);
    float GetSpeed();
    void SetSpeed(float speed);
    int GetDamage();
    void SetDamage(int damage);
    float GetJmpHeight();
    void SetJmpHeight(float jmpHeight);

    // API de Subject
    void agregarObserver(IObserver* observer);

    // Evento de juego que dispara notificaciones
    void recibirDano(int dano);

private:
    // Datos "de juego" ya existentes
    float _health;
    float _maxHealth;
    float _speed;
    int   _damage;
    float _jumpHeight;

    // --- FSM ---
    State currentState_;
    int   stateTicks_;        // contador simple para simular tiempo en estado
    int   ticksToIdle_;       // cuántos updates permanecemos en JUMPING/ATTACKING antes de volver a IDLE
    
    // --- Observer (Subject) ---
    static const int MAX_OBSERVERS = 10;
    IObserver* observadores_[MAX_OBSERVERS] = { nullptr };
    int numObservadores_ = 0;

    void notificar(Evento evento);
};
