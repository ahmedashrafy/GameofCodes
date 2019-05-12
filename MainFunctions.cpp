#include "MainFunctions.hpp"

bool Play_Game(RenderWindow& window, int Theme)
{
    Player* CurrentPlayer = new Arya;
    Block* Map[10][10];
    Block* Background[10][10];
    
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
        
        Map_Parser(level, Map, CurrentPlayer, Theme);
        Change_Theme(Theme, Map, Background);
        Render_Game(window, Map, CurrentPlayer, text, Background);

        while(window.isOpen() && !LevelWon && !GameOver &&!RestartLevel)
        {
                text.setString("LeveL: "+to_string(level)+" - "+"Lives: "+to_string(CurrentPlayer->getLives())+" - "+"Moves: "+to_string(CurrentPlayer->getMoves()));
                Handle_Game(window, CurrentPlayer, Map, text, Background, RestartLevel, Menu);
            
                Render_Game(window, Map, CurrentPlayer, text, Background);
                
                LevelWon = playerWon(CurrentPlayer, Map);
                GameOver = isOver(CurrentPlayer, Map);
            
                if(Menu) return true;
                if(RestartLevel) level--;
        }
        if(GameOver) level = 101 ;
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
