#ifndef mainmenu_hpp
#define mainmenu_hpp

#include "UniversalHeader.hpp"

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

