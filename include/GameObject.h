#pragma once
#include "raylib.h"
#include "string"
#include <iostream>

namespace LoW
{
	class GameObject
	{
	public:
		Vector2 position;
		std::string name;
		//imagen del objeto
		Texture texture;
		bool DisplayName = false;

		//constructor
		GameObject(Vector2 pos, std::string _name, Texture tex) :
			position(pos), name(_name), texture(tex) { }

		//actualizar posicion
		virtual void update();
		// dibujar o renderizar el objeto
		void draw();

	};
}

