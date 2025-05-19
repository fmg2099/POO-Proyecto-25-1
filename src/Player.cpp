#include "Player.h"

using namespace LoW;
//sobrecargar la funcion update de GameObject
//para mover el objecto con las teclas
void Player::update()
{
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed * GetFrameTime();
	}
}

void Player::Fire()
{
	//checar qe el player tiene un IAttacker y 
	//entonces llamar a su fire
}

IAttacker* Player::SetWeapon(IAttacker* newWeapon)
{
	if (newWeapon)
	{
		weapon = newWeapon;
		Weapon* w = dynamic_cast<Weapon*>(weapon);
		if (w)
			std::cout << "cambiando arma a " << w->name << std::endl;

		//notificar a los sidekicks
		//for (int i = 0; i < 3; i++)
		//{
		//	if (sidekicks[i])
		//	{
		//		//sidekicks[i]->SetWeapon(newWeapon);
		//	}
		//}

		return weapon;
	}
	return nullptr;
}

//void Player::SetSidekick(Sidekick* newSidekick, int index)
//{
//	//if (index >= 0 && index < 3)
//	//{
//	//	sidekicks[index] = newSidekick;
//	//}
//	//else
//	//{
//	//	std::cout << "Indice de sidekick invalido" << std::endl;
//	//}
//}
