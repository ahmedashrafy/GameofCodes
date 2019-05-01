#include "Cersei.h"

Cersei::Cersei()
{
	texture.loadFromFile("Cersei.png");
	sprite.setTexture(texture);
	sprite.setScale(0.08, 0.08);
	sprite.setPosition(10, 10);
	Lives = 3;
	Steps = 15;
}

Cersei::Cersei(int l, int s, int x, int y)
{
	texture.loadFromFile("Cersei.png");
	sprite.setTexture(texture);
	sprite.setScale(0.08, 0.08);
	sprite.setPosition(x, y);
	Lives = l;
	Steps = s;
}


Cersei::~Cersei()
{
}
