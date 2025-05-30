#pragma once
#include "raylib.h"
#include "string"
#include <iostream>
#include <vector>

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

		//vector estatico que contiene todos los gameObject de la escena
		static std::vector<GameObject*> gameObjects;

		//constructor predeterminado
		GameObject() :
			position({ 0,0 }), 
			name("GameObject"), 
			texture({ 0 }) {
		}


		//constructor
		GameObject(Vector2 pos, std::string _name, Texture tex) :
			position(pos), name(_name), texture(tex) { }

		//actualizar posicion
		virtual void update();
		// dibujar o renderizar el objeto
		virtual void draw();

	};
}

