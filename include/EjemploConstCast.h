#pragma once
#include <iostream>

class EjemploConstCast
{

	static void ejemploConstCast()
	{
		const int x = 10;
		int* p = const_cast<int*>(&x); // Eliminar la constancia
		x = 25; //no se puede porque lo marcamos como const

		*p = 20; // Modificar el valor apuntado
		std::cout << "Valor de x: " << x << std::endl; // Imprime 20
	}

};

