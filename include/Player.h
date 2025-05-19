#pragma once
#include "GameObject.h"
#include "IAttacker.h"
#include "Weapon.h"
#include "Sidekick.h"

namespace LoW
{
	class Player :
		public GameObject, public IAttacker
	{
	private:
		//instrumento que le permite atacar
		IAttacker* weapon;
		//Sidekick* coso;
	public: 
		float speed = 10.0f;

		//constructor heredado de GameObject
		Player(Vector2 pos, std::string _name, Texture tex) :
			GameObject(pos, _name, tex), 
			weapon(nullptr)
			//sidekicks{ nullptr, nullptr, nullptr }
		{ }


		void update() override;

		void attack()
		{
			std::cout << name << "Atacando" << std::endl;
		}

		//hay que sobrecargar esta funcion a fuerzas
		void Fire();

		IAttacker* SetWeapon(IAttacker* newWeapon);
		//void SetSidekick(Sidekick* newsidekick, int index);



	};

}
