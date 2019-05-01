#include "Arya.h"

Arya::Arya()
{
	texture.loadFromFile("Arya.png");
	sprite.setTexture(texture);
	sprite.setScale(0.08, 0.08);
	sprite.setPosition(10, 10);
	Lives = 3;
	Steps = 15;
}

Arya::Arya(int l, int s, int x, int y)
{
	texture.loadFromFile("Arya.png");
	sprite.setTexture(texture);
	sprite.setScale(0.08, 0.08);
	sprite.setPosition(x, y);
	Lives = l;
	Steps = s;
}


Arya::~Arya()
{
}
