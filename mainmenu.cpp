#include "mainmenu.hpp"
mainmenu::mainmenu()
{
    //Setting Fonts
        font.loadFromFile(resourcePath() + "/Resources/Fonts/GameOfThrones.ttf");
    
        startGame.setFont(font);
        startSettings.setFont(font);
        startMP.setFont(font);
    
        startGame.setCharacterSize(30);
        startSettings.setCharacterSize(30);
        startMP.setCharacterSize(30);
    
        startSettings.setFillColor(Color::Black);
        startGame.setFillColor(Color::Black);
        startMP.setFillColor(Color::Black);
    
        startGame.setString("Classic Mode");
        startSettings.setString("Settings");
        startMP.setString("Multiplayer");
    
    //Setting the Background
        backgroundTexture.loadFromFile(resourcePath() + "/Resources/Menu/start.001.png");
        background.setTexture(backgroundTexture);
    
    //Play Button
        playButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/playbutton.png");
    
    //Button texture
        buttonTexture.loadFromFile(resourcePath() + "/Resources/Menu/MenuTexture.png");
    
    //Settings texture
        settingsButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/settingsbutton.png");
    
    //Volume Button Texture
        volumeButtonTexture.loadFromFile(resourcePath() + "/Resources/Menu/volumebutton.png");
    
    //Play Button
        box[0].setTexture(&buttonTexture);
        box[0].setPosition(Vector2f(350, 400));
        box[0].setSize(Vector2f(350,75));
        playButton.setTexture(&playButtonTexture);
        playButton.setPosition(Vector2f(350, 400));
        playButton.setSize(Vector2f(75,75));
        startGame.setPosition(430,420);
    
    //Multiplayer Button
        box[3].setTexture(&buttonTexture);
        box[3].setPosition(Vector2f(350, 500));
        box[3].setSize(Vector2f(350,75));
        MPButton.setTexture(&playButtonTexture);
        MPButton.setPosition(Vector2f(350, 500));
        MPButton.setSize(Vector2f(75,75));
        startMP.setPosition(430,520);
    
    //Settings Button
        box[1].setTexture(&buttonTexture);
        box[1].setPosition(Vector2f(350, 600));
        box[1].setSize(Vector2f(350,75));
        settingsButton.setTexture(&settingsButtonTexture);
        settingsButton.setPosition(Vector2f(350, 600));
        settingsButton.setSize(Vector2f(75,75));
        startSettings.setPosition(430,620);
    
    //Volume Button
        box[2].setTexture(&buttonTexture);
        box[2].setPosition(Vector2f(900, 50));
        box[2].setSize(Vector2f(75,75));
        volumeButton.setTexture(&volumeButtonTexture);
        volumeButton.setPosition(Vector2f(900, 50));
        volumeButton.setSize(Vector2f(75,75));
}

void mainmenu::draw(RenderWindow& window)
{
    window.clear();
    
    //Drawing the Background
        window.draw(background);
    
    //Drawing the boxes
        for(int i=0;i<4;i++)
        {
            window.draw(box[i]);
        }
    
    //Drawing the buttons
    window.draw(playButton);
    window.draw(settingsButton);
    window.draw(volumeButton);
    window.draw(MPButton);
    
    //Drawing the Text
    window.draw(startSettings);
    window.draw(startGame);
    window.draw(startMP);

    
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
        case 3: //MultiPlayer Button
            if (box[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
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

