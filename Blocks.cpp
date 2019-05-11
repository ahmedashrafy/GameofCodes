#include "Blocks.hpp"

//Parent Class: Block
    Block::Block()
    {
        Object.setSize(Vector2f(100,100));
        Special = 0;
    }

    Block::~Block()
    {
        
    }


//Derived Class: MovingBlock
    MovingBlock::MovingBlock()
    {
        ID = "MovingBlock";
        nID = 1;
        Texture temp;
        temp.loadFromFile(resourcePath()+"Resources/Blocks/Theme_1/MoveableBlock.png");
        
        Object.setTexture(&temp);
    }

    MovingBlock::~MovingBlock()
    {
        
    }

    bool MovingBlock::move(int stepNumber, char direction)
    {
        switch(direction)
        {
            case 'D':
                Object.move(0, stepNumber);
                break;
            
            case 'U':
                Object.move(0, -stepNumber);
                break;
            
            case 'R':
                Object.move(stepNumber, 0);
                break;
            
            case 'L':
                Object.move(-stepNumber, 0);
                break;
        }
    }
    bool MovingBlock::unmove(int stepNumber, char direction)
    {
        switch(direction)
        {
            case 'U':
                Object.move(0, stepNumber);
                break;
                
            case 'D':
                Object.move(0, -stepNumber);
                break;
                
            case 'L':
                Object.move(stepNumber, 0);
                break;
                
            case 'R':
                Object.move(-stepNumber, 0);
                break;
        }
    }

    void MovingBlock::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/MovingBlock_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/MovingBlock_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/MovingBlock_3.png");
        }
        
        Object.setTexture(&temp);
    }


//Derived Class: WallBlock
    WallBlock::WallBlock()
    {
        ID = "WallBlock";
        nID = 2;
        Texture temp;
        temp.loadFromFile("Resources/Blocks/Theme_1/WallBlock.png");
        
        Object.setTexture(&temp);
    }

    WallBlock::~WallBlock()
    {
        
    }

    void WallBlock::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/WallBlock_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/WallBlock_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/WallBlock_3.png");
        }
        
        Object.setTexture(&temp);
    }


//Derived Class: EmptyBlock
    EmptyBlock::EmptyBlock()
    {
        ID = "EmptyBlock";
        nID = 3;
        Object.setFillColor(Color::White);
    }

    EmptyBlock::~EmptyBlock()
    {
        
    }

    void EmptyBlock::setTheme(int themeNumber)
    {
        
    }


//Derived Class: Target Block
    TargetBlock::TargetBlock()
    {
        ID = "TargetBlock";
        nID = 4;
        Texture temp;
        temp.loadFromFile("Resources/Blocks/Theme_1/TargetBlock.png");
        
        Object.setTexture(&temp);
    }

    TargetBlock::~TargetBlock()
    {
        
    }

    void TargetBlock::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/TargetBlock_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/TargetBlock_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/TargetBlock_3.png");
        }
        
        Object.setTexture(&temp);
    }
    bool TargetBlock::isFull(Block* Map[15][15])
    {
        for (int i =0; i<15; i++)
        {
            for (int j=0; j<15; j++)
            {
                if (Map[i][j]->getID()=="MovingBlock" && blockHere(Map[i][j]))
                {
                    return true;
                }
            }
        }
        return false; 
    }

//Derived Class: Sand Block
    SandBlock::SandBlock()
    {
        ID = "SandBlock";
        nID = 5;
        Texture temp;
        temp.loadFromFile("Resources/Blocks/Theme_1/SandBlock.png");
        
        Object.setTexture(&temp);
    }
    SandBlock::~SandBlock()
    {
        
    }

    void SandBlock::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/SandBlock_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/SandBlock_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/SandBlock_3.png");
        }
        
        Object.setTexture(&temp);
    }

//Derived Class: Add Lives
    AddLives::AddLives()
    {
        ID = "AddLives";
        nID = 6;
        Texture temp;
        temp.loadFromFile("Resources/Blocks/Theme_1/AddLives.png");
        
        Object.setTexture(&temp);
        
        Special = 1;
    }

    AddLives::~AddLives()
    {
        
    }

    void AddLives::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/AddLives_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/AddLives_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/AddLives_3.png");
        }
        
        Object.setTexture(&temp);
    }
    void AddLives::Invoke (Player* CurrentPlayer)
    {
        CurrentPlayer->addLives(1); 
        Object.setPosition(100000, 100000); //Set's the objects position outside of the window (make-shift solution
    }


//Derived Class: Add Moves
    AddMoves::AddMoves()
    {
        ID = "AddMoves";
        nID = 7;
        Texture temp;
        temp.loadFromFile("Resources/Blocks/Theme_1/AddMoves.png");
        
        Object.setTexture(&temp);
        
        Special = 2;
    }

    AddMoves::~AddMoves()
    {
        
    }

    void AddMoves::setTheme(int themeNumber)
    {
        Texture temp;
        
        switch(themeNumber)
        {
            case 1:
                temp.loadFromFile("res/Blocks/AddMoves_1.png");
            case 2:
                temp.loadFromFile("res/Blocks/AddMoves_2.png");
            case 3:
                temp.loadFromFile("res/Blocks/AddMoves_3.png");
        }
        
        Object.setTexture(&temp);
    }
    void AddMoves::Invoke (Player* CurrentPlayer)
    {
        CurrentPlayer->addMoves(3);
        Object.setPosition(100000, 100000); //Set's the objects position outside of the window (make-shift solution
    }


