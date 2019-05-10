//
//  settingsmenu.hpp
//  menu
//
//  Created by Habeeba Mansour on 5/10/19.
//  Copyright © 2019 Habeeba Mansour. All rights reserved.
//

#ifndef settingsmenu_hpp
#define settingsmenu_hpp
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using namespace std;
using namespace sf;
class settingsmenu{
private:
    Font font;
    Text texts[4];
    RectangleShape themes[3], homeButton, box, selections[3];
    Sprite background;
    Texture homeButtonTexture, backgroundTexture, textures[3];
    
public:
    settingsmenu();
    void draw(RenderWindow&);
    bool mousePressed(int, RenderWindow&);
};

#endif /* settingsmenu_hpp */
