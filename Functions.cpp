#include "Functions.hpp"

void Map_Parser(int level, Block* Map [15] [15], Player* CurrentPlayer)
{
        fstream file;
        string LevelNumber = to_string((level%7)+1);
        string LevelName = "Resources/Levels/level"+LevelNumber+".txt";
        string str[15];
        string temp;
        file.open(resourcePath()+LevelName);
        if (!file.is_open()){
            cout<<"Unable to open file";
        }
        getline(file, temp);
        int counter=stoi(temp);
        for(int i=0;i<15;i++){
            getline(file, str[i]);
        }
        file.close();
        level = 1;
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                if(str[i+1][j]=='#')
                {
                    Map[i][j]= new WallBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='!')
                {
                    Map[i][j]= new TargetBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='?')
                {
                    Map[i][j]= new MovingBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='@')
                {
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='/')
                {
                    Map[i][j]= new EmptyBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='$'){
                    Map[i][j]= new SandBlock;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                    CurrentPlayer->getSprite().setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='+')
                {
                    Map[i][j]= new AddLives;
                    Map[i][j]->setPosition(j*50+100, i*50+100);
                }
                else if(str[i+1][j]=='x')
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
    /*if(level>7)
    {
        RandomLevelGenerator(level, Map, CurrentPlayer);
    }*/
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

void Change_Theme(int index, Block* Map [15] [15], Block* Background [15] [15])
{
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<15; j++)
        {
            Map[i][j]->setTheme(index);
            Background[i][j]->setTheme(index);
        }
    }
}

void Movement_Handler (Player* CurrentPlayer, Block* Map[15][15],int stepNumber, char direction, RenderWindow* window, Text text, Block* Background [15] [15])
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
                                case 1:
                                    //First Block Intersecting is Moved
                                    Map[i][j]->move(1, direction);
                                    
                                    
                                    //We check that the Block does not intersect a Wall-Block Now
                                    for (int k = 0; k<15; k++)
                                    {
                                        for (int l=0; l<15; l++)
                                        {
                                            if(Map[k][l]->blockHere(Map[i][j]))
                                            {
                                                cout<<Map[k][l]->getID()<<endl;
                                            }
                                            if((Map[k][l]->blockHere(Map[i][j])) && (Map[k][l]->getID()=="WallBlock"))
                                            {
                                                Map[i][j]->unmove(1, direction); //if yes, reverse direction of block
                                                CurrentPlayer->unmove(1, direction); //if yes, reverse direction of player
                                                PlayerMoved = false; // Mark the Player as moved
                                            }
                                            /*else if((Map[k][l]->blockHere(Map[i][j])) && (Map[k][l]->getID()=="MovingBlock") && (Map[i][j]->getID()=="MovingBlock"))
                                            {
                                                Map[i][j]->unmove(1, direction); //if yes, reverse direction of block
                                                CurrentPlayer->unmove(1, direction); //if yes, reverse direction of player
                                                PlayerMoved = false; // Mark the Player as moved
                                            }*/
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

void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[15][15], Text text, Block* Background [15] [15])
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
                        Movement_Handler (CurrentPlayer, Map, 25, 'D', &window, text, Background);
                        break;
                    case Keyboard::Up:
                        Movement_Handler (CurrentPlayer, Map, 25, 'U', &window, text, Background);
                        break;
                    case Keyboard::Right:
                        Movement_Handler (CurrentPlayer, Map, 25, 'R', &window, text, Background);
                        break;
                    case Keyboard::Left:
                        Movement_Handler (CurrentPlayer, Map, 25, 'L', &window, text, Background);
                        break;
                }
                break;
        }
    }
}

void Render_Game (RenderWindow& window, Block* Map[15][15], Player* CurrentPlayer, Text text, Block* Background[15][15])
{
    window.clear();
    
    //Draw Map
    for (int i = 0; i<15; i++)
    {
        for (int j = 0;  j<15; j++)
        {
            window.draw(Background[i][j]->getRectangle());
            if(!(Map[i][j]->getID()=="MovingBlock"))
            {
                window.draw(Map[i][j]->getRectangle());
            }
        }
    }
    
    //Draw Moveable Blocks
    for (int i = 0; i<15; i++)
    {
        for (int j = 0;  j<15; j++)
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
    return false;
}

bool playerWon(Player* CurrentPlayer, Block* Map[15][15])
{
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<15; j++)
        {
            if(Map[i][j]->getnID()==4 && !Map[i][j]->isFull(Map))
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
    string LevelName = "Resources/Level_Templates/level"+template_selection+".txt";
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
            if(str[i+1][j]=='#') //Wall Block - Randomized
                
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='!') //Target Block - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='?') //Moving Block - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='@') //Sand Path - left as is
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='/') //Empty Block - Randomized
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='$'){ //Player position - left as is
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
                CurrentPlayer->getSprite().setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='+') //Pickup - Randomized
            {
                Map[i][j]= BlockRandomizer();
                Map[i][j]->setPosition(j*50+100, i*50+100);
            }
            else if(str[i+1][j]=='x') //Pickup - Randomized
            {
                Map[i][j]= BlockRandomizer();
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
