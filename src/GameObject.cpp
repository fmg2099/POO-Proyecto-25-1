#include "GameObject.h"

void LoW::GameObject::update()
{
	//std::cout << name << " update" << std::endl;
}

void LoW::GameObject::draw()
{

	DrawTexture(texture, position.x, position.y, WHITE);

	if (DisplayName)
	{
		DrawText(name.c_str(), position.x, position.y - 20, 10, YELLOW);
	}
} 
