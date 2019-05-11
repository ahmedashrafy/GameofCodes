#include "MainFunctions.hpp"


void Display_Splash(RenderWindow& window)
{
    RectangleShape Splash;
    Texture SplashTexture;
    
    SplashTexture.loadFromFile(resourcePath()+"/Resources/Menu/SplashScreen.jpg");

    Splash.setTexture(&SplashTexture);
    Splash.setSize(Vector2f(1000,1000));
    Splash.setPosition(0, 0);
    
    window.clear();
    window.draw(Splash);
    window.display();
    
    Clock clock;
    while(clock.getElapsedTime()<seconds(10)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
    { };
}


bool Play_Game(RenderWindow& window, int Theme)
{
    Player* CurrentPlayer;
    Block* Map[15][15];
    Text text;
    
    bool GameOver = false;
    bool LevelWon = false;
    
    switch (Theme)
    {
        case 0:
            CurrentPlayer = new Arya;
            break;
        case 1:
            CurrentPlayer = new Jaime;
            break;
        case 2:
            CurrentPlayer = new Jon;
            break;
    }
    
    for (int level = 1; level <100; level++)
    {
        GameOver = false;
        LevelWon = false;
        
        Map_Parser(level, Map, CurrentPlayer);
        Change_Theme(Theme, Map);
        
        Render_Game(window, Map, CurrentPlayer, text);

        while(window.isOpen())
        {
            if(!GameOver && !LevelWon)
            {
                Handle_Game(window, CurrentPlayer, Map, text);
                Render_Game(window, Map, CurrentPlayer, text);
                
                LevelWon = playerWon(CurrentPlayer, Map);
                GameOver = isOver(CurrentPlayer, Map);
            }
        }
        if(GameOver) level = 10 ;
    }
    return true;
}
void Display_Menu(RenderWindow& window)
{
    //Menu Items
    mainmenu menu;
    settingsmenu settings;
    
    //Sound Items
    Sound SoundF[2];
    SoundBuffer Buffer[2];
    
    //Flags
    bool sound=true;
    bool main=true;
    
    //Play Sound
    Play_Sound(SoundF, Buffer, 1, sound);
    
    //Theme & Player Index
    int Theme = 0;
    
    //Check for button clicked
    while(window.isOpen())
    {
        //Wait for input
        Handle_Menu(window);
        
        //menu.mousePress(0, window);
        
        if(menu.mousePress(1, window))
        {
            Play_Sound(SoundF+1, Buffer+1, 5, sound);
            main=false;
            while(!main){
                settings.draw(window);
                if(settings.mousePressed(0, window))
                {
                    Theme = 0;
                    Play_Sound(SoundF, Buffer, 2, sound);
                    main = true;

                }
                if(settings.mousePressed(1, window))
                {
                    Theme = 1;
                    Play_Sound(SoundF, Buffer, 3, sound);
                    main = true;
                }
                if(settings.mousePressed(2, window))
                {
                    Theme = 2;
                    Play_Sound(SoundF, Buffer, 4, sound);
                    main = true;

                }
                if(settings.mousePressed(3, window))
                {
                    Play_Sound(SoundF+1, Buffer+1, 5, sound);
                    main=true;
                }
            }
        }
        
        if(menu.mousePress(0, window))
        {
            main = false;
            while(!main)
            {
                Play_Sound(SoundF+1, Buffer+1, 5, sound);
                main = Play_Game(window, Theme);
            }
        }
        if(menu.mousePress(2, window))
        {
            Play_Sound(SoundF+1, Buffer+1, 5, sound);
            menu.volumePress(sound);
            Play_Sound(SoundF, Buffer, 1, sound);
        }
        
        menu.draw(window);
    }
}
