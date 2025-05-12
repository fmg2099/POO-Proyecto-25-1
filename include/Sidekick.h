#pragma once
#include "GameObject.h"
#include "Player.h"
#include "raymath.h"

class Sidekick :public GameObject
{
public :
	float speed = 100;
	//referencia al gameobject al que sirve este sidekick
	GameObject* owner;

	//constructor heredado de GameObject
	Sidekick(Vector2 pos, std::string _name, Texture tex) :
		GameObject(pos, _name, tex) {
	}
	void update() override;

	void attack()
	{
		std::cout << name << "Atacando" << std::endl;
	}
	void flee()
	{
		std::cout << name << "Huye como cobarde" << std::endl;
	}
};