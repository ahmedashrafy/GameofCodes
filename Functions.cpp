#include "Functions.hpp"

void Map_Parser(int level, Block* Map [15] [15], Player* CurrentPlayer)
{
    if(level<8)
    {
        fstream file;
        string LevelNumber = to_string(level);
        string LevelName = "/Resources/Levels/level"+LevelNumber+".txt";
        string str[16];
        file.open(resourcePath()+LevelName);
        if (!file.is_open()){
            cout<<"Unable to open file";
        }
        for(int i=0;i<15;i++){
            getline(file, str[i]);
        }
        file.close();
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                if(str[i][j]=='#')
                {
                    Map[i][j]= new WallBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='!')
                {
                    Map[i][j]= new TargetBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='?')
                {
                    Map[i][j]= new MovingBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='@')
                {
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='/')
                {
                    Map[i][j]= new EmptyBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='$'){
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                    CurrentPlayer->getSprite().setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='+')
                {
                    Map[i][j]= new AddLives;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i][j]=='x')
                {
                    Map[i][j]= new AddMoves;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else
                {
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
            }
        }
    }
    else
    {
        RandomLevelGenerator(level, Map, CurrentPlayer);
    }
}
void Play_Sound(Sound* Sound, SoundBuffer* Buffer, int index, bool SoundOn)
{
    if(!SoundOn)
    {
        Sound->stop();
    }
    
    else
    {
        switch(index) //TO BE COMPLETED AS AUDIO FILES ARE FINALIZED
        {
            case 1:
                Buffer->loadFromFile(resourcePath()+"Resources/Music/Track_1.ogg");
                Sound->setBuffer(*Buffer);
                Sound->setLoop(true);
                break;
                
            case 2:
                Buffer->loadFromFile(resourcePath()+"Resources/Music/Track_2.ogg");
                Sound->setBuffer(*Buffer);
                Sound->setLoop(true);
                break;
            
            case 3:
                Buffer->loadFromFile(resourcePath()+"Resources/Music/Track_3.ogg");
                Sound->setBuffer(*Buffer);
                Sound->setLoop(true);
                break;
                
            case 4:
                Buffer->loadFromFile(resourcePath()+"Resources/Music/Track_4.ogg");
                Sound->setBuffer(*Buffer);
                Sound->setLoop(true); 
                break;
            case 5:
                Buffer->loadFromFile(resourcePath()+"Resources/Music/Track_5.ogg");
                Sound->setBuffer(*Buffer);
                break;
        }
        Sound->play();
    }
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

void Movement_Handler (Player* CurrentPlayer, Block* Map[15][15],int stepNumber, char direction, RenderWindow* window, Text text)
{
    bool PlayerMoved;
    
    do
    {
        //Resetting Flag
            PlayerMoved = true;
        
        //Player Movement
            //1) Move the Player
            CurrentPlayer->move(1, direction);
        
            //2) Check if collides with un-collideable Block (wall)
            for (int i = 0; i<15; i++)
            {
                for (int j=0; j<15; j++)
                {
                        if(Map[i][j]->playerHere(CurrentPlayer))
                        {
                            int BlockType = Map[i][j]->getnID();
                            switch (BlockType)
                            {
                                case 2: //Wall Block
                                    CurrentPlayer->unmove(1, direction); //if yes, reverse direction
                                    PlayerMoved = false; // Mark the Player as moved
                                    break;
                                case 7: //Add Moves
                                    Map[i][j]->Invoke(CurrentPlayer);
                                    CurrentPlayer -> animate(direction);
                                    break; 
                                case 6: //Add Lives
                                    Map[i][j]->Invoke(CurrentPlayer);
                                    CurrentPlayer -> animate(direction);
                                    break;
                                default:
                                    CurrentPlayer -> animate(direction);
                                    break;
                            }

                        }
                }
            }
        //Interesected Block Movement (Only if Player Moved)
            if (PlayerMoved)
            {
                for (int i = 0; i<15; i++)
                {
                    for (int j = 0; j<15; j++)
                    {
                        if(Map[i][j]->playerHere(CurrentPlayer))
                        {
                            //First Block Intersecting is Moved
                                Map[i][j]->move(1, direction);
                            
                            //We check that the Block does not intersect a Wall-Block Now
                                for (int k = 0; k<15; k++)
                                {
                                    for (int l=0; l<15; l++)
                                    {
                                        if(Map[k][l]->blockHere(Map[i][j]) && Map[k][l]->getID()=="Wall Block")
                                        {
                                            Map[i][j]->unmove(1, direction); //if yes, reverse direction of block
                                            CurrentPlayer->unmove(1, direction); //if yes, reverse direction of player
                                            PlayerMoved = false; // Mark the Player as moved
                                        }
                                    }
                                }
                        }
                    }
                }
            }
        
        //Display Changes
        Render_Game (*window, Map, CurrentPlayer, text);
        
        //Decrementing the stepNumber
        stepNumber--;
        

    }
    while(stepNumber>0 && PlayerMoved);

        
}
void Handle_Menu(RenderWindow &window)
{
    Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch (event.key.code)
            {
                case Keyboard::Escape:
                    window.close();
                    break;
            }
                break;
                
        }
    }
}

void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[15][15], Text text)
{
    Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window.close();
                break;
                
            case Event::KeyPressed:
                switch (event.key.code)
                {

                    case Keyboard::Down:
                        Movement_Handler (CurrentPlayer, Map, 25, 'D', &window, text);
                        break;
                    case Keyboard::Up:
                        Movement_Handler (CurrentPlayer, Map, 25, 'U', &window, text);
                        break;
                    case Keyboard::Right:
                        Movement_Handler (CurrentPlayer, Map, 25, 'R', &window, text);
                        break;
                    case Keyboard::Left:
                        Movement_Handler (CurrentPlayer, Map, 25, 'L', &window, text);
                        break;
                }
                break;
        }
    }
}

void Render_Game (RenderWindow& window, Block* Map[15][15], Player* CurrentPlayer, Text text)
{
    window.clear();
    
    //Draw Player
    window.draw(CurrentPlayer->getSprite());
    
    //Draw Map
    for (int i = 0; i<15; i++)
    {
        for (int j = 0;  j<15; j++)
        {
            window.draw(Map[i][j]->getRectangle());
        }
    }
    
    //Draw Text
    window.draw(text);
    
    window.display();
    
}

bool isOver(Player* CurrentPlayer, Block* Map[15][15])
{
    if(CurrentPlayer->getLives()==0 && CurrentPlayer->getMoves()==0)
    {
        return true;
    }
    else if(CurrentPlayer->getMoves()==0)
    {
        CurrentPlayer->consumeLive();
        return false;
    }
}

bool playerWon(Player* CurrentPlayer, Block* Map[15][15])
{
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<15; j++)
        {
            if(Map[i][j]->getID()=="Target Block" && !Map[i][j]->isFull(Map))
            {
                return false;
            }
        }
    }
    return true;
}
void RandomLevelGenerator(int level, Block* Map [15] [15], Player* CurrentPlayer)
{
    
    //Stage 1: Solution Template Randomizer
    int template_number;
    
    srand(time(NULL));
    template_number = rand() % 6;
    template_number++;
    
    string template_selection = to_string(template_number);
    
    //Stage 2: Using the pre-created levels as templates
    fstream file;
    string LevelNumber = to_string(level);
    string LevelName = "/Resources/Level_Templates/level"+template_selection+".txt";
    string str[16];
    file.open(resourcePath()+LevelName);
    if (!file.is_open()){
        cout<<"Unable to open file";
    }
    for(int i=0;i<15;i++){
        getline(file, str[i]);
    }
    file.close();
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(str[i][j]=='#') //Wall Block - Randomized
                
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='!') //Target Block - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='?') //Moving Block - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='@') //Sand Path - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='/') //Empty Block - Randomized
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='$'){ //Player position - left as is
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
                CurrentPlayer->getSprite().setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='+') //Pickup - Randomized
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i][j]=='x') //Pickup - Randomized
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            
        }
    }
}

Block* BlockRandomizer()
{
    srand(time(NULL));
    int RandomNumber = rand() % 6;
    
    if(RandomNumber == 0) //
    {
        return new WallBlock;
    }
    else if(RandomNumber == 1) //Sand Path - left as is
    {
        return new SandBlock;
    }
    else if(RandomNumber == 2)
    {
        return new EmptyBlock;
    }
    else if(RandomNumber == 3){ //Player position - left as is
        return new SandBlock;
    }
    else if(RandomNumber == 4)
    {
        return new AddLives;
    }
    else if(RandomNumber == 5)
    {
        return new AddMoves;
    }
}
