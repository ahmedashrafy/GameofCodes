#include "mainmenu.hpp"
mainmenu::mainmenu()
{
    //Text
    if (!font.loadFromFile(resourcePath() + "/Resources/Fonts/GameOfThrones.ttf")) {
        cout<<"Error failed to load font"<<endl;
    }
    startGame.setFont(font);
    startSettings.setFont(font);
    startGame.setCharacterSize(30);
    startSettings.setCharacterSize(30);
    startSettings.setFillColor(Color::Black);
    startGame.setFillColor(Color::Black);
    startGame.setString("Classic Mode");
    startSettings.setString("Settings");
    
    //Background
    if (!backgroundTexture.loadFromFile(resourcePath() + "/Resources/Menu/start.001.png")) {
        cout<<"Error failed to load splash screen"<<endl;
    }
    background.setTexture(backgroundTexture);
    
    //Play Button
    if (!playButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/playbutton.png")) {
        cout<<"Error failed to load play button"<<endl;
    }
    //Button texture
    if (!buttonTexture.loadFromFile(resourcePath() + "/Resources/Menu/MenuTexture.png")) {
        cout<<"Error failed to load play button"<<endl;
    }
    
    //box[0].setFillColor(Color::White);
    box[0].setTexture(&buttonTexture);
    box[0].setPosition(Vector2f(100, 600));
    box[0].setSize(Vector2f(350,75));
    playButton.setTexture(&playButtonTexture);
    playButton.setPosition(Vector2f(100, 600));
    playButton.setSize(Vector2f(75,75));
    startGame.setPosition(180,620);
    
    //Settings Button
    if (!settingsButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/settingsbutton.png"))
    {
        std::cout << "Failed to load settings button spritesheet!" << endl;
    }
    //box[1].setFillColor(Color::White);
    box[1].setTexture(&buttonTexture);
    box[1].setPosition(Vector2f(600, 600));
    box[1].setSize(Vector2f(275,75));
    settingsButton.setTexture(&settingsButtonTexture);
    settingsButton.setPosition(Vector2f(600, 600));
    settingsButton.setSize(Vector2f(75,75));
    startSettings.setPosition(680,620);
    //Volume Button
    if (!volumeButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/volumebutton.png"))
    {
        std::cout << "Failed to load volume button spritesheet!" << endl;
    }
    //box[2].setFillColor(Color::White);
    box[2].setTexture(&buttonTexture);
    box[2].setPosition(Vector2f(900, 50));
    box[2].setSize(Vector2f(75,75));
    volumeButton.setTexture(&volumeButtonTexture);
    volumeButton.setPosition(Vector2f(900, 50));
    volumeButton.setSize(Vector2f(75,75));
}

void mainmenu::draw(RenderWindow& window) {
    window.clear();
    window.draw(background);
    for(int i=0;i<3;i++)
        window.draw(box[i]);
    window.draw(playButton);
    window.draw(settingsButton);
    window.draw(volumeButton);
    window.draw(startSettings);
    window.draw(startGame);
    window.display();
}

bool mainmenu::mousePress(int buttonNum, RenderWindow &window) {
    switch (buttonNum) {
        case 0: //Play Button
            if (box[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased)
                    return true;
                return false;
            }
            break;
        case 1: //Settings Button
            if (box[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased)
                    return true;
                return false;
            }
            break;
        case 2: //Volume Button
            if (box[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
                if (Mouse::isButtonPressed(Mouse::Left) && Event::MouseButtonReleased)
                    return true;
                return false;
            }
            break;
    }
    return false;
    
}

void mainmenu::volumePress(bool& soundOn) {
    if (soundOn) {
        //Switch to off
        soundOn = false;
        Texture temp;
        if (!volumeButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/novolumebutton.jpg"))
        {
            std::cout << "Failed to load no volume button spritesheet!" << endl;
        }
        volumeButtonTexture.update(temp);
    }
    else {
        //Switch to on
        soundOn = true;
        Texture temp;
        if (!volumeButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/volumebutton.png"))
        {
            cout << "Failed to load volume button spritesheet!" << endl;
        }
        volumeButtonTexture.update(temp);
    }
    
}

