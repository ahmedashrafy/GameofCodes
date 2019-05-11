#include "MainFunctions.hpp"


void Display_Splash(RenderWindow& window)
{
    RectangleShape Splash;
    Texture SplashTexture;
    
    SplashTexture.loadFromFile(resourcePath()+"/Resources/Menu/SplashScreen.png");

    Splash.setTexture(&SplashTexture);
    Splash.setSize(Vector2f(1000,1000));
    Splash.setPosition(0, 0);
    
    window.clear();
    window.draw(Splash);
    window.display();
}


void Play_Game(RenderWindow& window)
{
    Player CurrentPlayer;
    Block* Map[15][15];
    Text text;
    bool GameOver = false;
    bool LevelWon = false;
    
    for (int level = 1; level <8; level++)
    {
        GameOver = false;
        LevelWon = false;
        
        Map_Parser(level, Map, &CurrentPlayer);
        Render_Game(window, Map, &CurrentPlayer, text);

        while(window.isOpen())
        {
            if(!GameOver && !LevelWon)
            {
                Handle_Game(window, &CurrentPlayer, Map);
                Render_Game(window, Map, &CurrentPlayer, text);
                
                LevelWon = playerWon(&CurrentPlayer, Map);
                GameOver = isOver(&CurrentPlayer, Map);
            }
        }
        if(GameOver) level = 10 ;
    }
}
void Display_Menu(RenderWindow& window)
{
    mainmenu menu;
    settingsmenu settings;
    Sound Sound;
    SoundBuffer Buffer;
    
    bool sound=true;
    bool main=true;
    Play_Sound(&Sound, &Buffer, 1); 
    while(window.isOpen())
    {
        Handle_Menu(window); 
        menu.mousePress(0, window);
        if(menu.mousePress(1, window)){
            main=false;
            while(!main){
                settings.draw(window);
                settings.mousePressed(0, window);
                settings.mousePressed(1, window);
                settings.mousePressed(2, window);
                if(settings.mousePressed(3, window)){
                    main=true;
                }
            }
        }
        if(menu.mousePress(2, window)){
            menu.volumePress(sound);
        }
        menu.draw(window);
        
        
    }
}
