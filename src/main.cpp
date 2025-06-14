/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/
#include <iostream>
#include <string>
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "GameObject.h"
#include "Player.h"
#include "Sidekick.h"
#include <vector>
#include "UISystem.h"
#include "World.h"

using namespace LoW;

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	std::cout << "Initializando sistema de juego " << std::endl;

	// Create the window and OpenGL context
	InitWindow(1280, 800, "JUego con Objectos");

	//SetWindowSize(512, 512);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	//cargar el mundo
	World::getInstance();

	//arreglo o lista de gameobjects en la escena
	// comentado porque fue movido a GameObject.h
	//std::vector<GameObject*> gameObjects; //vector de punteros a GameObject

	//crear nuestro objeto de prueba 
	GameObject* myObj = new GameObject({ 200,200 }, "myObj", LoadTexture("mono.png"));
	myObj->DisplayName = true;
	//push_back agrega un elemento al final del arreglo
	GameObject::gameObjects.push_back(myObj);  //cast implicito a GameObject*

	//El jugador
	// este constructor ya no existe, ahora el Player establece su textura
	//Player* playerCharacter = new Player({ 0,0 }, "Player1", LoadTexture("boy.png"));
	Player* playerCharacter = new Player({270, 480}, "Player1");
	playerCharacter->speed = 200.0f;
	//agregando el player pero con un cast explicito estatico
	// estatico quiere decir que se realiza en tiempo de compilacion
	GameObject::gameObjects.push_back( static_cast<GameObject*>( playerCharacter ) );

	//prueba de arma
	Weapon* w = new Weapon({ 200, 200 }, "Sword", LoadTexture("sword.png"));
	//playerCharacter->SetWeapon(w); //asignar el arma al jugador
	GameObject::gameObjects.push_back(w); //agregar el arma al arreglo de gameobjects

	Sidekick* sidekick = new Sidekick({500,0 }, "Foo", LoadTexture("sidekick.png"));
	//sidekick->owner = playerCharacter;
	playerCharacter->SetSidekick(sidekick,0); 
	sidekick->DisplayName = true;
	sidekick->speed = 199.0f;
	GameObject::gameObjects.push_back(sidekick);

	Sidekick* sidekick2 = new Sidekick({ 800,600 }, "Bar", LoadTexture("karateka.png"));
	//sidekick2->owner = playerCharacter;
	playerCharacter->SetSidekick(sidekick2, 1);
	sidekick2->DisplayName = true;
	sidekick2->speed = 190.0f;
	GameObject::gameObjects.push_back(sidekick2);

	//Ejemplo de dynamic_cast
	for (GameObject* obj : GameObject::gameObjects)
	{
		//esta conversion es en tiempo de ejecucion
		Player* p = dynamic_cast<Player*>(obj);
		if (p)
		{
			p->attack();
		}

		Sidekick* sk = dynamic_cast<Sidekick*>(obj);
		if (sk  != nullptr )
		{
			sk->flee();
		}
	}

	// inicializar los elementos de UI
	UISystem::getInstance().test(); // probar el singleton de UI
	UISystem::Test(); // probar el metodo estatico del singleton de UI

	/*for (int i = 0; i < 20; i++)
	{
		UISystem::getInstance().createLabel(TextFormat("weeeeee %d", i), 100+i*10, 100 + i * 30, 12);
	}*/

	///UISystem::getInstance().createLabel("Bienbenido a mi juej0", 400, 400, 48);


	// game loop a 60 fps
	while (!WindowShouldClose())// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		//aqui van los update
		//actualizar todos los gameobjects
		for ( GameObject* obj : GameObject::gameObjects)
		{
			obj->update();
		}
		//actualizar el sistema de UI
		UISystem::Update(); //actualizar el sistema de UI


		// despues de beginDrawing consideraremos los draw
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(SKYBLUE);

		//dibujar el mundo es lo primero que hacemos
		World::getInstance().Draw();

		// draw some text using the default font
		DrawText("Ejemplo de Juego con GameObjects", 10,10,24,YELLOW);
		for (GameObject* obj : GameObject::gameObjects)
		{
			obj->draw();
		}
		
		//arriba de todo dibujamos el sistema de UI
		UISystem::Draw();
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}


	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
