#pragma once
#include "raylib.h"
#include <iostream>

namespace LoW
{
	class World
	{
	private:
		static World* instance; // Singleton instancia
		World() = default; // Constructor privado para evitar instanciación externa
		World(const World&) = delete; // Eliminar el constructor de copia
		World& operator=(const World&) = delete; // Eliminar el operador de asignación

	public:
		Texture background;
		Texture collisionMask;
		Image collisionMaskImg;

		static World& getInstance()
		{
			if (!instance)
			{
				instance = new World();
				instance->InitWorld(); // Inicializar el mundo predeterminado
			}
			return *instance;
		}

		//cargar mundo default
		void InitWorld()
		{
			background = LoadTexture("world1.jpg");
			//collisionMask = LoadTexture("world1_mask.png");
			collisionMaskImg = LoadImage("world1_mask.png");
			//para que cada byte represente un pixel en escala de grises
			ImageFormat(&collisionMaskImg, PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);


		}

		void Draw()
		{
			DrawTexture(background, 0, 0, WHITE);
		}

		//checa si el pixel en la posicion point tiene bloqueo
		bool CheckCollision(Vector2 point) 
		{
			//acceder al pixel en particular
			int index = (point.y * collisionMaskImg.width + point.x);

			char* imgdata = (char*)collisionMaskImg.data; //acceder a los datos de la imagen

			std::cout << "valor en pixel ( " << point.x << "," << point.y << "): " << (int)imgdata[index] << std::endl;

			return (imgdata[index] != 0); // si el valor es menor a 128, no hay colision

		}
	};
}



