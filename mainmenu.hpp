#ifndef mainmenu_hpp
#define mainmenu_hpp

#include "UniversalHeader.hpp"

class mainmenu
{
private:
    Font font;
    Text startGame, startSettings, startMP;
    Sprite background;
    RectangleShape playButton, settingsButton, volumeButton, MPButton, box[4];
    Texture playButtonTexture, settingsButtonTexture, volumeButtonTexture, backgroundTexture, buttonTexture;
public:
    mainmenu();
    void draw(RenderWindow& window);
    bool mousePress(int buttonNum, RenderWindow& window);
    void volumePress(bool& soundOn);
};
#endif /* mainmenu_hpp */

