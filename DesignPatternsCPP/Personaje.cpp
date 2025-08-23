#include "Personaje.h"
#include <iostream>

// Constructores
Personaje::Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight)
    : _health(health), _maxHealth(maxHealth), _speed(speed), _damage(damage), _jumpHeight(jumpHeight),
      currentState_(State::IDLE), stateTicks_(0), ticksToIdle_(2)
{
}

Personaje::Personaje()
    : Personaje(20.f, 20.f, 10.f, 10, 10.f)
{
}

// --- FSM ---
void Personaje::handleInput(char input)
{
    switch (currentState_)
    {
    case State::IDLE:
        if (input == 'w') {
            currentState_ = State::JUMPING;
            stateTicks_ = 0;
            std::cout << "Personaje salta.\n";
        } else if (input == 'f') {
            currentState_ = State::ATTACKING;
            stateTicks_ = 0;
            std::cout << "Personaje ataca.\n";
        } else {
            // Ignoramos otras teclas en IDLE sin quejarse
        }
        break;

    case State::JUMPING:
        // En el aire ignoramos cualquier input
        if (input != '\0') {
            std::cout << "Personaje esta en el aire y no puede realizar acciones.\n";
        }
        break;

    case State::ATTACKING:
        // Atacando ignoramos cualquier input
        if (input != '\0') {
            std::cout << "Personaje esta atacando y no puede realizar acciones.\n";
        }
        break;
    }
}

void Personaje::update()
{
    // Si está en JUMPING o ATTACKING, contamos "tiempo" y volvemos a IDLE tras X ticks
    if (currentState_ == State::JUMPING || currentState_ == State::ATTACKING) {
        ++stateTicks_;
        if (stateTicks_ >= ticksToIdle_) {
            currentState_ = State::IDLE;
            stateTicks_ = 0;
            // Volver a IDLE no requiere mensaje por el enunciado; si quieres, descomenta:
            // std::cout << "Personaje vuelve a IDLE.\n";
        }
    }
}

// Métodos existentes (compatibilidad con patrón Command anterior)
// No cambian de estado por sí mismos, solo muestran acciones base.
void Personaje::Saltar()     { std::cout << "SALTAR (API antigua)\n"; }
void Personaje::Disparar()   { std::cout << "DISPARAR (API antigua)\n"; }
void Personaje::Crouchear()  { std::cout << "AGACHARSE (API antigua)\n"; }
// API antigua para moverse, ahora se maneja con FSM, lo dejo para testeo.

const char* Personaje::stateName() const
{
    switch (currentState_) {
    case State::IDLE:      return "IDLE";
    case State::JUMPING:   return "JUMPING";
    case State::ATTACKING: return "ATTACKING";
    default:               return "?";
    }
}

// Getters / Setters ya existentes
float Personaje::GetHealth() { return _health; }
void  Personaje::SetHealth(float health) { _health = health; }
float Personaje::GetMaxHealth() { return _maxHealth; }
void  Personaje::SetMaxHealth(float maxHealth) { _maxHealth = maxHealth; }
float Personaje::GetSpeed() { return _speed; }
void  Personaje::SetSpeed(float speed) { _speed = speed; }
int   Personaje::GetDamage() { return _damage; }
void  Personaje::SetDamage(int damage) { _damage = damage; }
float Personaje::GetJmpHeight() { return _jumpHeight; }
void  Personaje::SetJmpHeight(float jmpHeight) { _jumpHeight = jmpHeight; }

// ==================== Observer (Subject) ====================
void Personaje::agregarObserver(IObserver* observer) {
    if (!observer) return;
    if (numObservadores_ >= MAX_OBSERVERS) {
        std::cout << "[Subject] No se pueden agregar mas observadores (MAX_OBSERVERS alcanzado).\n";
        return;
    }
    observadores_[numObservadores_++] = observer;
}

void Personaje::notificar(Evento evento) {
    for (int i = 0; i < numObservadores_; ++i) {
        if (observadores_[i]) {
            observadores_[i]->onNotify(*this, evento);
        }
    }
}

void Personaje::recibirDano(int dano) {
    if (dano <= 0) return;
    _health -= dano;
    if (_health < 0) _health = 0;
    std::cout << "[Personaje] Recibe " << dano << " de dano. Salud actual: " << _health << "/" << _maxHealth << "\n";
    notificar(Evento::PERSONAJE_RECIBE_DANO);
}