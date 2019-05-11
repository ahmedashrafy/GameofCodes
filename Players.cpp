#include "Players.hpp"

//Parent Class
    Player::Player()
    {
        
    }

    Player::~Player()
    {
        
    }

    Sprite Player::getSprite() const
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


//Derived Class: Arya
    Arya::Arya()
    {
        texture.loadFromFile("res/Players/Arya.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(10, 10);
        Lives = 3;
        Moves = 15;
    }

    Arya::Arya(int l, int s, int x, int y)
    {
        texture.loadFromFile("res/Players/Arya.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(x, y);
        Lives = l;
        Moves = s;
    }

    Arya::~Arya()
    {
    }


//Derived Class: Cersei
    Cersei::Cersei()
    {
        texture.loadFromFile("res/Players/Cersei.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(10, 10);
        Lives = 3;
        Moves = 15;
    }

    Cersei::Cersei(int l, int s, int x, int y)
    {
        texture.loadFromFile("res/Players/Cersei.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(x, y);
        Lives = l;
        Moves = s;
    }

    Cersei::~Cersei()
    {
    }


//Derived Class: John 
    Jon::Jon()
    {
        texture.loadFromFile("res/Players/Jon.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(10, 10);
        Lives = 3;
        Moves = 15;
    }

    Jon::Jon(int l, int s, int x, int y)
    {
        texture.loadFromFile("res/Players/Jon.png");
        sprite.setTexture(texture);
        sprite.setScale(0.08, 0.08);
        sprite.setPosition(x, y);
        Lives = l;
        Moves = s;
        
    }

    Jon::~Jon()
    {
    }

