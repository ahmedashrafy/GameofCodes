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
    
    Texture temp;
    temp.loadFromFile("MovingBlock_1.png");
    
    Object.setTexture(&temp);
}

MovingBlock::~MovingBlock()
{
    
}

bool MovingBlock::moveBlock(int stepNumber, char direction)
{
    switch(direction)
    {
        case 'D':
            Object.move(0, 25);
            break;
        
        case 'U':
            Object.move(0, -25);
            break;
        
        case 'R':
            Object.move(25, 0);
            break;
        
        case 'L':
            Object.move(-25, 0);
            break;
    }
}

void MovingBlock::setTheme(int themeNumber)
{
    Texture temp;
    
    switch(themeNumber)
    {
        case 1:
            temp.loadFromFile("MovingBlock_1.png");
        case 2:
            temp.loadFromFile("MovingBlock_2.png");
        case 3:
            temp.loadFromFile("MovingBlock_3.png");
    }
    
    Object.setTexture(&temp);
}


//Derived Class: WallBlock
WallBlock::WallBlock()
{
    ID = "WallBlock";
    
    Texture temp;
    temp.loadFromFile("WallBlock_1.png");
    
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
            temp.loadFromFile("WallBlock_1.png");
        case 2:
            temp.loadFromFile("WallBlock_2.png");
        case 3:
            temp.loadFromFile("WallBlock_3.png");
    }
    
    Object.setTexture(&temp);
}


//Derived Class: EmptyBlock
EmptyBlock::EmptyBlock()
{
    ID = "EmptyBlock";
    Object.setFillColor(Color::White);
}

EmptyBlock::~EmptyBlock()
{
    
}

void EmptyBlock::setTheme(int themeNumber)
{
    
}

//Derived Class: EmptyBlock
TargetBlock::TargetBlock()
{
    ID = "TargetBlock";
    
    Texture temp;
    temp.loadFromFile("TargetBlock_1.png");
    
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
            temp.loadFromFile("TargetBlock_1.png");
        case 2:
            temp.loadFromFile("TargetBlock_2.png");
        case 3:
            temp.loadFromFile("TargetBlock_3.png");
    }
    
    Object.setTexture(&temp);
}

//Derived Class: EmptyBlock
SandBlock::SandBlock()
{
    ID = "SandBlock";
    
    Texture temp;
    temp.loadFromFile("SandBlock_1.png");
    
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
            temp.loadFromFile("SandBlock_1.png");
        case 2:
            temp.loadFromFile("SandBlock_2.png");
        case 3:
            temp.loadFromFile("SandBlock_3.png");
    }
    
    Object.setTexture(&temp);
}

//Derived Class: EmptyBlock
AddLives::AddLives()
{
    ID = "AddLives";
    
    Texture temp;
    temp.loadFromFile("AddLives_1.png");
    
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
            temp.loadFromFile("AddLives_1.png");
        case 2:
            temp.loadFromFile("AddLives_2.png");
        case 3:
            temp.loadFromFile("AddLives_3.png");
    }
    
    Object.setTexture(&temp);
}


//Derived Class: EmptyBlock
AddMoves::AddMoves()
{
    ID = "AddMoves";
    
    Texture temp;
    temp.loadFromFile("AddMoves_1.png");
    
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
            temp.loadFromFile("AddMoves_1.png");
        case 2:
            temp.loadFromFile("AddMoves_2.png");
        case 3:
            temp.loadFromFile("AddMoves_3.png");
    }
    
    Object.setTexture(&temp);
}

