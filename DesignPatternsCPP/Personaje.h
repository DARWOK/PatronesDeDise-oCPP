#pragma once
class Personaje
{
public:
	Personaje(float health, float maxHealth, float speed, int damage, float jumpHeight);
	Personaje();
	~Personaje();

	// Getters and Setters
	void Saltar();
	void Disparar();
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
private:
	float _health;
	float _maxHealth;
	float _speed;
	int _damage;
	float _jumpHeight;
};

