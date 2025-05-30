#pragma once
#include <iostream>
#include <vector>
#include "View.h"
#include "Label.h"

//Singleton para gestionar el sistema de interfaz de usuario UI
class UISystem
{
public:

	///////////////////////////////////////////////////
	// Patr�n Singleton: Asegura que solo exista una instancia de UISystem
	///////////////////////////////////////////////////

	static UISystem& getInstance()
	{
		if (!instance)
		{
			instance = new UISystem();
		}
		return *instance;
	}

	//metodo para probar el singleton
	void test()
	{
		std::cout << "Hola soy EL singleton de UI" << std::endl;
	}
	//tambien podemos exponer como estatico un metodo para acceder mas facilmente
	static void Test()  //es un wrapper o envoltura
	{
		getInstance().test(); 
	}

	///////////////////////////////////////////////////
	// Propiedades espec�ficas del sistema de UI
	///////////////////////////////////////////////////
	//lista de objetos de UI dibujables
	std::vector<View*> views;

	Label* createLabel(const char* text, int x, int y, int fontSize = 20);

	void draw();
	static void Draw()
	{
		getInstance().draw();
	}

	void update();
	static void Update()
	{
		getInstance().update();
	}

private:
	static UISystem* instance; 

	UISystem() = default; // Constructor privado para evitar instanciaci�n externa
	UISystem(const UISystem&) = delete; // Eliminar el constructor de copia
	UISystem& operator=(const UISystem&) = delete; // Eliminar el operador de asignaci�n

};
