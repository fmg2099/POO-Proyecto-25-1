#pragma once
#include "GameObject.h"

namespace LoW
{
	class Player :
		public GameObject
	{
	public:
		float speed = 10.0f;

		//constructor heredado de GameObject
		Player(Vector2 pos, std::string _name, Texture tex) :
			GameObject(pos, _name, tex) {
		}


		void update() override;

		void attack()
		{
			std::cout << name << "Atacando" << std::endl;
		}
	};

}