#include "MainFunctions.hpp"

bool Play_Game(RenderWindow& window, int Theme)
{
    Player* CurrentPlayer = NULL;
    Block* Map[10][10];
    Block* Background[10][10];
    Texture temp [7];

    
    for (int i =0; i<10;i++)
        {
            for (int j =0; j<10; j++)
            {
                Background[i][j] = new SandBlock;
                Background[i][j]->setPosition(j*100, i*100);
            }
        }
    
    bool GameOver = false;
    bool LevelWon = false;
    bool RestartLevel = false;
    bool Menu = false;
    
    Text text;
    Font font;
    
    
    font.loadFromFile(resourcePath() + "/Resources/Fonts/Counter.otf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(Color::Black);
    text.setPosition(600, 20);

    for (int level = 1; level <100; level++)
    {
        
        GameOver = false;
        LevelWon = false;
        
        //Encapsulation into a function FAILED - not sure why but the pointer is nullified after function returns.
            if(Theme == 0)
            {
                CurrentPlayer = new Arya;
            }
            else if(Theme == 1)
            {
                CurrentPlayer = new Jaime;
            }
            else if (Theme == 2)
            {
                CurrentPlayer = new Jon;
            }
        
        Map_Parser(level, Map, CurrentPlayer, Theme);
        Change_Theme(Theme, Map, Background, temp);
        Render_Game(window, Map, CurrentPlayer, text, Background);

        while(window.isOpen() && !LevelWon && !GameOver)
        {
                text.setString("LeveL: "+to_string(level)+" - "+"Lives: "+to_string(CurrentPlayer->getLives())+" - "+"Moves: "+to_string(CurrentPlayer->getMoves()));
                Handle_Game(window, CurrentPlayer, Map, text, Background, RestartLevel, Menu);
            
                Render_Game(window, Map, CurrentPlayer, text, Background);
                
                LevelWon = playerWon(CurrentPlayer, Map);
                GameOver = isOver(CurrentPlayer, Map);
            
                if(Menu) return true;
                if(RestartLevel)
                {
                    DisplayHint (Theme, window);
                    RestartLevel = false;
                }
        }
        
        if(GameOver)
        {
            SaveRecords(level);
            level = 101 ;
        }
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
    
    //Clock
    Clock clock;
    
    //Main menu event
    Event event;
    
    //Check for button clicked
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            Handle_Menu(window);
            if(menu.mousePress(1, window))
            {
                Play_Sound(SoundF+1, Buffer+1, 5, sound);
                main=false;
                clock.restart();
                while(clock.getElapsedTime()<seconds(2)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                { };
                settings.draw(window);

                while(!main){
                    settings.draw(window);
                    
                    while(window.pollEvent(event))
                    {
                        if(settings.mousePressed(0, window))
                        {
                            Theme = 0;
                            DisplayHint (0, window);
                            Play_Sound(SoundF, Buffer, 2, sound);
                            clock.restart();
                            while(clock.getElapsedTime()<seconds(3)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                            { };
                            main = true;

                        }
                        if(settings.mousePressed(1, window))
                        {
                            Theme = 1;
                            DisplayHint (1, window);
                            Play_Sound(SoundF, Buffer, 3, sound);
                            clock.restart();
                            while(clock.getElapsedTime()<seconds(3)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                            { };
                            main = true;
                        }
                        if(settings.mousePressed(2, window))
                        {
                            Theme = 2;
                            DisplayHint (2, window);
                            Play_Sound(SoundF, Buffer, 4, sound);
                            clock.restart();
                            while(clock.getElapsedTime()<seconds(3)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                            { };
                            main = true;

                        }
                        if(settings.mousePressed(3, window))
                        {
                            Play_Sound(SoundF+1, Buffer+1, 5, sound);
                            clock.restart();
                           while(clock.getElapsedTime()<seconds(1)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                            { };
                            main=true;
                        }
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
                clock.restart();
                while(clock.getElapsedTime()<seconds(1.5)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
                { };
            }
        }
        menu.draw(window);
    }
}

void Display_Splash(RenderWindow& window)
{
    RectangleShape Splash;
    Texture SplashTexture;
    
    
    SplashTexture.loadFromFile(resourcePath()+"Resources/Menu/SplashScreen.jpg");

    
    Splash.setSize(Vector2f(1000,1000));
    Splash.setPosition(0, 0);
    Splash.setTexture(&SplashTexture);
    
    
    window.clear();
    window.draw(Splash);
    window.display();
    
    Clock clock;
    while(clock.getElapsedTime()<seconds(10)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
    { };
}

