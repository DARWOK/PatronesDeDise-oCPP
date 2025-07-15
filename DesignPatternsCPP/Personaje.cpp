#include "Personaje.h"
#include <iostream>

Personaje::Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight)
{
	std::cout << "Llamando Constructor de Personaje con Variables" << std::endl;
	_health = health;
	_maxHealth = maxHealth;
	_speed = speed;
	_damage = damage;
	_jumpHeight = jumpHeight;
}

Personaje::Personaje()
{
	std::cout << "Llamando Constructor por Defecto de Personaje" << std::endl;
	_health = 100;
	_maxHealth = 100;
	_speed = 10;
	_damage = 10;
	_jumpHeight = 10;
}

void Personaje::Saltar()
{
	std::cout << "Saltando" << std::endl;
}

void Personaje::Disparar()
{
	std::cout << "Disparando" << std::endl;
}

Personaje::~Personaje()
{
	std::cout << "Llamando Destructor de Personaje" << std::endl;
}

float Personaje::GetHealth()
{
	return _health;
}

void Personaje::SetHealth(float health)
{
	_health = health;
}

float Personaje::GetMaxHealth()
{
	return _maxHealth;
}

void Personaje::SetMaxHealth(float maxHealth)
{
	_maxHealth = maxHealth;
}

float Personaje::GetSpeed()
{
	return _speed;
}

void Personaje::SetSpeed(float speed)
{
	_speed = speed;
}

int Personaje::GetDamage()
{
	return _damage;
}

void Personaje::SetDamage(int damage)
{
	_damage = damage;
}

float Personaje::GetJmpHeight()
{
	return _jumpHeight;
}

void Personaje::SetJmpHeight(float jmpHeight)
{
	_jumpHeight = jmpHeight;
}