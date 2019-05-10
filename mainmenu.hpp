//
//  mainmenu.hpp
//  menu
//
//  Created by Habeeba Mansour on 5/9/19.
//  Copyright © 2019 Habeeba Mansour. All rights reserved.
//

#ifndef mainmenu_hpp
#define mainmenu_hpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
using namespace std;
using namespace sf;
class mainmenu
{
private:
    Font font;
    Text startGame, startSettings;
    Sprite background;
    RectangleShape playButton, settingsButton, volumeButton, box[3];
    Texture playButtonTexture, settingsButtonTexture, volumeButtonTexture, backgroundTexture;
public:
    mainmenu();
    void draw(RenderWindow& window);
    bool mousePress(int buttonNum, RenderWindow& window);
    void volumePress(bool& soundOn);
};
#endif /* mainmenu_hpp */

