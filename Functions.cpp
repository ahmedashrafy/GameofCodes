#include "Functions.hpp"

void Map_Parser(int level, Block* Map [10] [10], int Theme)
{
    //Level switch
    
        fstream file;
        string LevelNumber = to_string((level%8));
        string LevelName = "Resources/Levels/level"+LevelNumber+".txt";
        string str[11];
        string temp;
        file.open(resourcePath()+LevelName);
        if (!file.is_open()){
            cout<<"Unable to open file";
        }
        getline(file, temp);
        for(int i=0;i<10;i++){
            getline(file, str[i]);
        }
        file.close();
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(str[i][j]=='#')
                {
                    Map[i][j]= new WallBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='!')
                {
                    Map[i][j]= new TargetBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='?')
                {
                    Map[i][j]= new MovingBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='@')
                {
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='/')
                {
                    Map[i][j]= new EmptyBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='$'){
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='+')
                {
                    Map[i][j]= new AddLives;
                    Map[i][j]->setPosition(j*100, i*100);
                }
                else if(str[i][j]=='x')
                {
                    Map[i][j]= new AddMoves;
                    Map[i][j]->setPosition(j*100, i*100);
                }
            }
        }
    if(level>7)
    {
        RandomLevelGenerator(Map);
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

void Change_Theme(int index, Block* Map [10] [10], Block* Background [10] [10], Texture temp[7])
{
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            Map[i][j]->setTheme(index, temp[(Map[i][j]->getnID())%7]);
            Background[i][j]->setTheme(index, temp[(Background[i][j]->getnID())%7]);
        }
    }
}


void Movement_Handler (Player* CurrentPlayer, Block* Map[10][10],int stepNumber, char direction, RenderWindow* window, Text text, Block* Background [10] [10])
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
            for (int i = 0; i<10; i++)
            {
                for (int j=0; j<10; j++)
                {
                        if(Map[i][j]->playerHere(CurrentPlayer))
                        {
                            int BlockType = Map[i][j]->getnID();
                            switch (BlockType)
                            {
                                case 1:
                                    //First Block Intersecting is Moved
                                    Map[i][j]->move(1, direction);
                                    
                                    
                                    for (int k = 0; k<10; k++)
                                    {
                                        for (int l=0; l<10; l++)
                                        {
                                            
                                            if((Map[k][l]->blockHere(Map[i][j])) && (Map[k][l]->getID()=="WallBlock" || Map[k][l]->getID()=="MovingBlock") && ((i != k) || (l != j))) //We check that the Block does not intersect a Wall-Block Now
                                            {
                                                Map[i][j]->unmove(1, direction); //if yes, reverse direction of block
                                                CurrentPlayer->unmove(1, direction); //if yes, reverse direction of player
                                                PlayerMoved = false; // Mark the Player as moved
                                            }
 
                                        }
                                    }
                                    break;
                                    
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
    
        //Display Changes
        Render_Game (*window, Map, CurrentPlayer, text, Background);

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

void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[10][10], Text text, Block* Background [10] [10], bool& RestartLevel, bool& Menu)
{
    int iX = CurrentPlayer->getSpriteAddress()->getPosition().x;
    int iY = CurrentPlayer->getSpriteAddress()->getPosition().y;

    Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window.close();
                break;
                
            case Event::KeyReleased:
                switch (event.key.code)
                {
                    case Keyboard:: Space:
                        RestartLevel = true;
                        break;
                    
                    case Keyboard:: Escape:
                        Menu = true;
                        break; 

                    case Keyboard::Down:
                        Movement_Handler (CurrentPlayer, Map, 100, 'D', &window, text, Background);
                        if(iX != CurrentPlayer->getSpriteAddress()->getPosition().x || iY != CurrentPlayer->getSpriteAddress()->getPosition().y) CurrentPlayer->removeMove();

                        break;
                    case Keyboard::Up:
                        Movement_Handler (CurrentPlayer, Map, 100, 'U', &window, text, Background);
                        if(iX != CurrentPlayer->getSpriteAddress()->getPosition().x || iY != CurrentPlayer->getSpriteAddress()->getPosition().y) CurrentPlayer->removeMove();


                        break;
                    case Keyboard::Right:
                        Movement_Handler (CurrentPlayer, Map, 100, 'R', &window, text, Background);
                        if(iX != CurrentPlayer->getSpriteAddress()->getPosition().x || iY != CurrentPlayer->getSpriteAddress()->getPosition().y) CurrentPlayer->removeMove();

                        break;
                    case Keyboard::Left:
                        Movement_Handler (CurrentPlayer, Map, 100, 'L', &window, text, Background);
                        if(iX != CurrentPlayer->getSpriteAddress()->getPosition().x || iY != CurrentPlayer->getSpriteAddress()->getPosition().y) CurrentPlayer->removeMove();

                        break;
                }
                break;
        }
    }
}

void Handle_Game_MP(RenderWindow& window, Player* Players[2], Block* Map[10][10], Text text, Block* Background [10] [10], bool& RestartLevel, bool& Menu)
{
    int iX0 = Players[0]->getSpriteAddress()->getPosition().x;
    int iY0 = Players[0]->getSpriteAddress()->getPosition().y;
    
    int iX1 = Players[1]->getSpriteAddress()->getPosition().x;
    int iY1 = Players[1]->getSpriteAddress()->getPosition().y;
    
    
    
    Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window.close();
                break;
                
            case Event::KeyReleased:
                switch (event.key.code)
            {
                case Keyboard:: Space:
                    RestartLevel = true;
                    break;
                    
                case Keyboard:: Escape:
                    Menu = true;
                    break;
                    
                    //Player 1 controls
                case Keyboard::S:
                    Movement_Handler (Players[0], Map, 100, 'D', &window, text, Background);
                    if(iX0 != Players[0]->getSpriteAddress()->getPosition().x || iY0 != Players[0]->getSpriteAddress()->getPosition().y) Players[0]->removeMove();
                    break;
                    
                case Keyboard::W:
                    Movement_Handler (Players[0], Map, 100, 'U', &window, text, Background);
                    if(iX0 != Players[0]->getSpriteAddress()->getPosition().x || iY0 != Players[0]->getSpriteAddress()->getPosition().y) Players[0]->removeMove();
                    break;
                    
                case Keyboard::D:
                    Movement_Handler (Players[0], Map, 100, 'R', &window, text, Background);
                    if(iX0 != Players[0]->getSpriteAddress()->getPosition().x || iY0 != Players[0]->getSpriteAddress()->getPosition().y) Players[0]->removeMove();
                    break;
                    
                case Keyboard::A:
                    Movement_Handler (Players[0], Map, 100, 'L', &window, text, Background);
                    if(iX0 != Players[0]->getSpriteAddress()->getPosition().x || iY0 != Players[0]->getSpriteAddress()->getPosition().y) Players[0]->removeMove();
                    break;
                    
                    //Player 2 controls
                case Keyboard::Down:
                    Movement_Handler (Players[1], Map, 100, 'D', &window, text, Background);
                    if(iX1 != Players[1]->getSpriteAddress()->getPosition().x || iY1 != Players[1]->getSpriteAddress()->getPosition().y) Players[1]->removeMove();
                    break;
                case Keyboard::Up:
                    Movement_Handler (Players[1], Map, 100, 'U', &window, text, Background);
                    if(iX1 != Players[1]->getSpriteAddress()->getPosition().x || iY1 != Players[1]->getSpriteAddress()->getPosition().y) Players[1]->removeMove();
                    break;
                    
                case Keyboard::Right:
                    Movement_Handler (Players[1], Map, 100, 'R', &window, text, Background);
                    if(iX1 != Players[1]->getSpriteAddress()->getPosition().x || iY1 != Players[1]->getSpriteAddress()->getPosition().y) Players[1]->removeMove();
                    break;
                case Keyboard::Left:
                    Movement_Handler (Players[1], Map, 100, 'L', &window, text, Background);
                    if(iX1 != Players[1]->getSpriteAddress()->getPosition().x || iY1 != Players[1]->getSpriteAddress()->getPosition().y) Players[1]->removeMove();
                    break;
            }
                break;
        }
    }
}


void Render_Game (RenderWindow& window, Block* Map[10][10], Player* CurrentPlayer, Text text, Block* Background[10][10])
{
    window.clear();
    
    //Draw Map
    for (int i = 0; i<10; i++)
    {
        for (int j = 0;  j<10; j++)
        {
            window.draw(Background[i][j]->getRectangle());
            if(!(Map[i][j]->getID()=="MovingBlock"))
            {
                window.draw(Map[i][j]->getRectangle());
            }
        }
    }
    
    //Draw Moveable Blocks
    for (int i = 0; i<10; i++)
    {
        for (int j = 0;  j<10; j++)
        {
            if(Map[i][j]->getID()=="MovingBlock") window.draw(Map[i][j]->getRectangle());
        }
    }
    
    //Draw Player
    window.draw(CurrentPlayer->getSprite());
    
    //Draw Text
    window.draw(text);
    
    window.display();
    
}

void Render_Game_MP (RenderWindow& window, Block* Map[10][10], Player* Players[2], Text text, Block* Background[10][10])
{
    window.clear();
    
    //Draw Map
    for (int i = 0; i<10; i++)
    {
        for (int j = 0;  j<10; j++)
        {
            window.draw(Background[i][j]->getRectangle());
            if(!(Map[i][j]->getID()=="MovingBlock"))
            {
                window.draw(Map[i][j]->getRectangle());
            }
        }
    }
    
    //Draw Moveable Blocks
    for (int i = 0; i<10; i++)
    {
        for (int j = 0;  j<10; j++)
        {
            if(Map[i][j]->getID()=="MovingBlock") window.draw(Map[i][j]->getRectangle());
        }
    }
    
    //Draw Player
    for (int i = 0; i<2; i++)
    {
        window.draw(Players[i]->getSprite());
    }
    
    //Draw Text
    window.draw(text);
    
    window.display();
    
}

bool isOver(Player* CurrentPlayer, Block* Map[10][10])
{
    if(CurrentPlayer->getLives()<0 || (CurrentPlayer->getMoves()<1 && CurrentPlayer->getLives()<0))
    {
        return true;
    }
    else if(CurrentPlayer->getMoves()<1 && CurrentPlayer->getLives()>0)
    {
        CurrentPlayer->consumeLive();
        return false;
    }
    return false;
}

bool playerWon(Player* CurrentPlayer, Block* Map[10][10])
{
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if(Map[i][j]->getnID()==4 && !Map[i][j]->isFull(Map))
            {
                return false;
            }
        }
    }
    return true;
}
void RandomLevelGenerator(Block* Map [10] [10])
{
    for(int i =0; i<10; i++)
    {
        for(int j =0; j<10; j++)
        {
            if(Map[i][j]->getnID()==2 || Map[i][j]->getnID()==3 || Map[i][j]->getnID()==6 ||Map[i][j]->getnID()==7)
            {
                Map[i][j]=BlockRandomizer();
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

void SaveRecords (int Levels)
{
    ofstream output;
    
    srand(time(NULL));
    int User_ID = rand()%1000000;
    
    time_t now = time(0);
    string date = ctime(&now);
    
    output.open(resourcePath() + "/Resources/User_Records/"+to_string(User_ID)+".txt");
    
    output<<"User ID: "<<User_ID;
    output<<"Completed Levels: "<<to_string(Levels);
    output<<"Date Attempted: "<<date;
}

void DisplayHint (int Theme, RenderWindow& window)
{
    RectangleShape Hint;
    Texture HintTexture;
    
    
    switch (Theme)
    {
        case 0:
            HintTexture.loadFromFile(resourcePath()+"/Resources/Hints/Hint1.png");
            break;
        case 1:
            HintTexture.loadFromFile(resourcePath()+"/Resources/Hints/Hint2.png");
            break;
        case 2:
            HintTexture.loadFromFile(resourcePath()+"/Resources/Hints/Hint3.png");
            break;
    }
    
    Hint.setSize(Vector2f(1000,1000));
    Hint.setPosition(0, 0);
    Hint.setTexture(&HintTexture);
    
    
    window.clear();
    window.draw(Hint);
    window.display();
    
    Clock clock;
    while(clock.getElapsedTime()<seconds(5)) //While loop that will run as long as the time elapsed is less than 600 milliseconds
    { };
}
