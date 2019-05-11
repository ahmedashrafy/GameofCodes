#ifndef settingsmenu_hpp
#define settingsmenu_hpp

#include "UniversalHeader.hpp"

class settingsmenu{
private:
    Font font;
    Text texts[4];
    RectangleShape themes[3], homeButton, box[2], selections[3], volumeButton;
    Sprite background;
    Texture homeButtonTexture, backgroundTexture, textures[3], volumeButtonTexture;
    
public:
    settingsmenu();
    void draw(RenderWindow&);
    bool mousePressed(int, RenderWindow&);
    void volumePress(bool&);
};
#endif /* settingsmenu_hpp */
