#include "settingsmenu.hpp"
#include <iostream>
using namespace std;
using namespace sf;
settingsmenu::settingsmenu()
{
    //Font
    if (!font.loadFromFile(resourcePath() + "GameOfThrones.ttf")) {
        cout<<"Error failed to load font"<<endl;
    }
    //Background
    if (!backgroundTexture.loadFromFile(resourcePath() + "settingsBackground.png")) {
        cout<<"Error failed to load splash screen"<<endl;
    }
    background.setTexture(backgroundTexture);
    
    //Seelcetions
    if (!textures[0].loadFromFile(resourcePath() + "Arya_selection.003.png")) {
        cout<<"Error failed to load arya selection"<<endl;
    }
    
    //Volume Button
    if (!volumeButtonTexture.loadFromFile(resourcePath() + "volumebutton.png"))
    {
        std::cout << "Failed to load volume button spritesheet!" << endl;
    }
    box[1].setFillColor(Color::White);
    box[1].setPosition(Vector2f(900, 50));
    box[1].setSize(Vector2f(75,75));
    volumeButton.setTexture(&volumeButtonTexture);
    volumeButton.setPosition(Vector2f(900, 50));
    volumeButton.setSize(Vector2f(75,75));
    
    //Home Button
    if (!homeButtonTexture.loadFromFile(resourcePath() + "homeButton.jpg")) {
        cout << "Failed to load home button spritesheet!" <<endl;
    }
    
    homeButton.setTexture(&homeButtonTexture);
    homeButton.setPosition(Vector2f(50, 50));
    homeButton.setSize(Vector2f(75,75));
    box[0].setPosition(Vector2f(50, 50));
    box[0].setSize(Vector2f(75,75));
    box[0].setFillColor(Color::White);
    
    //Text            //Red (167,14,14)   Brown (150,128,75)
    //Title
    texts[0].setFont(font);
    texts[0].setCharacterSize(30);
    texts[0].setFillColor(Color::White);
    texts[0].setPosition(325, 220);
    texts[0].setString("Theme Selection");
    //Theme Buttons
    for(int i=0;i<3;i++){
        themes[i].setFillColor(Color::White);
        themes[i].setPosition(Vector2f(250,270+ 200*i));
        themes[i].setSize(Vector2f(500,200));
        themes[i].setOutlineColor(Color(150,128,75));
        themes[i].setOutlineThickness(10);
    }
    //theme texts
    for(int i=1;i<4;i++){
        texts[i].setFont(font);
        texts[i].setCharacterSize(20);
        texts[i].setFillColor(Color(167,14,14));
    }
    texts[1].setString("Arya in Braavos");
    texts[1].setPosition(390, 200+ 230);
    texts[2].setString("Cersei in Kings Landing");
    texts[2].setPosition(340, 200+ 430);
    texts[3].setString("Jon North of the Wall");
    texts[3].setPosition(350, 200+ 640);
    
    //Theme sprites
    for(int i=0;i<3;i++){
        selections[i].setTexture(&textures[0]);
        selections[i].setPosition(Vector2f(425,275+ 200*i));
        selections[i].setSize(Vector2f(150,150));
    }
}

void settingsmenu::draw(RenderWindow& window) {
    window.clear();
    window.draw(background);
    window.draw(box[1]);
    window.draw(homeButton);
    window.draw(volumeButton);
    for(int i=0;i<3;i++){
        window.draw(themes[i]);
        window.draw(selections[i]);
    }
    for(int i=0;i<4;i++){
        window.draw(texts[i]);
    }
    window.display();
}

bool settingsmenu::mousePressed(int buttonNum, RenderWindow &window) {
    
    
    switch (buttonNum) {
        case 0: //Theme Arya button
            if (themes[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased){
                    if(themes[0].getFillColor()==Color::White)
                        themes[0].setFillColor(Color(128,128,128));
                    else
                        themes[0].setFillColor(Color::White);
                    return true;
                }
                return false;
            }
            break;
        case 1: //Theme Cersei button
            if (themes[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased){
                    if(themes[1].getFillColor()==Color::White)
                        themes[1].setFillColor(Color(128,128,128));
                    else
                        themes[1].setFillColor(Color::White);
                    return true;
                }
                return false;
            }
            break;
        case 2: //Theme Jon button
            if (themes[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased){
                    if(themes[2].getFillColor()==Color::White)
                        themes[2].setFillColor(Color(128,128,128));
                    else
                        themes[2].setFillColor(Color::White);
                    return true;
                }
                return false;
            }
            break;
        case 3: //Home button
            if (box[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased)
                    return true;
                return false;
            }
        case 4: //Volume button
            if (box[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased)
                    return true;
                return false;
            }
    }
     
    return false;
}
void settingsmenu::volumePress(bool& soundOn) {
    if (soundOn) {
        //Switch to off
        soundOn = false;
        Texture temp;
        if (!volumeButtonTexture.loadFromFile(resourcePath() + "novolumebutton.jpg"))
        {
            std::cout << "Failed to load no volume button spritesheet!" << endl;
        }
        volumeButtonTexture.update(temp);
    }
    else {
        //Switch to on
        soundOn = true;
        Texture temp;
        if (!volumeButtonTexture.loadFromFile(resourcePath() + "volumebutton.png"))
        {
            cout << "Failed to load volume button spritesheet!" << endl;
        }
        volumeButtonTexture.update(temp);
    }
    
}

