#include "Functions.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

void Play_Sound(int index)
{
    SoundBuffer Buffer;
    Sound Output;
    
    switch(index) //TO BE COMPLETED AS AUDIO FILES ARE FINALIZED
    {
        case 1:
            Buffer.loadFromFile("Sound_1.wav");

    }
    Output.setBuffer(Buffer);
    Output.play();
}

void Display_Splash(RenderWindow& window)
{
    RectangleShape Splash;
    Texture SplashTexture;
    
    SplashTexture.loadFromFile("SplashScreen.png");
    Splash.setTexture(&SplashTexture);
    
    window.draw(Splash);
    window.display();
    
    Clock clock;
    while(clock.getElapsedTime()<seconds(5))
    { };
}
void Change_Theme(int index, Block* Map [9] [9])
{
    for (int i = 0; i<9; i++)
    {
        for (int j = 0; j<9; j++)
        {
            Map[i][j]->setTheme(index);
        }
    }
}
