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
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Arya/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        
        Lives = 3;
        Moves = 15;
    }

    Arya::Arya(int l, int s, int x, int y)
    {
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Arya/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        sprite.setPosition(x, y);
        sprite.move(x, y);
        
        Lives = l;
        Moves = s;
    }


    Arya::~Arya()
    {
    }


//Derived Class: Cersei
    Jaime::Jaime()
    {
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Jaime/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        
        Lives = 3;
        Moves = 15;
    }

    Jaime::Jaime(int l, int s, int x, int y)
    {
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Jaime/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        sprite.setPosition(x, y);

        
        Lives = l;
        Moves = s;
    }

    Jaime::~Jaime()
    {
    }


//Derived Class: John 
    Jon::Jon()
    {
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Jon/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        
        Lives = 3;
        Moves = 15;
    }

    Jon::Jon(int l, int s, int x, int y)
    {
        ir = new IntRect(6, 4, 28, 46);
        texture.loadFromFile(resourcePath()+"/Resources/Players/Jon/Spritesheet.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(*ir);
        sprite.setScale(2, 2);
        sprite.setPosition(x, y);

        
        Lives = l;
        Moves = s;
        
    }

    Jon::~Jon()
    {
    }

