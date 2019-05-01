#include "Player.h"

Player::Player()
{
	
}

Player::~Player()
{
}

Sprite Player::getsprite() const
{
	return sprite;
}

int Player::getrow() const
{
	return sprite.getPosition().x;
}

int Player::getcol() const
{
	return sprite.getPosition().y;
}
