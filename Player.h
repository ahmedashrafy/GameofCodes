#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Player
{
protected:
	//fakart ahot virtual int scale factor 3ashan laqa 3ozna neghayaro odam ne3melha mara wahda
	//mesh f kol player's constructor, bas kont nasy el syntax senna
	//fa hasebha zai ma heya and we can change it
	int Lives;
	int Steps;
	Texture texture;
	Sprite sprite;

public:
	Player();
	~Player();
	//to access sprite
	virtual Sprite getsprite() const;
	//not sure if needed, but just in case maslan .contains() ?
	virtual int getrow() const;
	virtual int getcol() const;
};

