#include "Functions.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
void Map_Parser(ifstream &file,Block* Map [15] [15], int levelNum){
    string str[16];
    file.open("level" + to_string(levelNo) + ".txt");
    if (!file.is_open()){
        cout<<"Unable to open file";
    }
    for(int i=0;i<16;i++){
        getline(file, str[i]);
    }
    int counter=stoi(str[0]);
    file.close();
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(str[i][j]=='#'){
                Map[i][j]= new WallBlock;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='!'){
                Map[i][j]= new TargetBlock;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='?'){
                Map[i][j]= new MovingBlock;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='@'){
                Map[i][j]= new SandBlock;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='/'){
                Map[i][j]= new EmptyBlock;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
           /* else if(str[i][j]=='$'){
                Map[i][j]= new CurrentPlayer;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }*/
            else if(str[i][j]=='+'){
                Map[i][j]= new AddLives;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='x'){
                Map[i][j]= new AddMoves;
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            
    }
}
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
void Change_Theme(int index, Block* Map [15] [15])
{
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<15; j++)
        {
            Map[i][j]->setTheme(index);
        }
    }
}
