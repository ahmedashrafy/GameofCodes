#ifndef Blocks_hpp
#define Blocks_hpp

//#include "UniversalHeader.hpp"
#include "Players.hpp"

//Base Class: Block
class Block
{
protected:
    RectangleShape Object;
    string ID;
    int nID;
    int Special;
    
public:
    virtual void setTheme(int themeNumber, Texture& temp)
    {
        
    };
    
    virtual void setTheme(Texture& BlockTexture)
    {
        Object.setTexture(&BlockTexture);
    };
    
    virtual void move(int stepNumber, char direction)
    {
        
    }
    virtual void unmove(int stepNumber, char direction)
    {
        
    }
    virtual string getID()
    {
        return ID;
    }
    virtual int getnID()
    {
        return nID;
    }
    void setPosition(int x, int y)
    {
        Object.setPosition(x, y);
    }
    virtual RectangleShape getRectangle()
    {
        return Object;
    }
    virtual bool playerHere(Player* MainPlayer)
    {
        return Object.getGlobalBounds().intersects(MainPlayer->getSprite().getGlobalBounds());
    }
    virtual bool blockHere(Block* Block)
    {
        return Object.getGlobalBounds().intersects(Block->getRectangle().getGlobalBounds());
    }
    virtual void Invoke(Player* CurrentPlayer)
    {
        
    }
    virtual bool isFull(Block* Map[10][10])
    {
        return false;
    }
    
    Block();
    ~Block();
};


//Derived Class: Moving Block
class MovingBlock: public Block
{
public:
    MovingBlock();
    ~MovingBlock();
    void move(int stepNumber, char direction);
    void unmove(int stepNumber, char direction);
    void setTheme(int themeNumber, Texture& temp);
};


//Derived Class: Wall Block
class WallBlock: public Block
{
public:
    WallBlock();
    ~WallBlock();
    void setTheme(int themeNumber, Texture& temp);
};


//Derived Class: Empty Block
class EmptyBlock: public Block
{
public:
    EmptyBlock();
    ~EmptyBlock();
    void setTheme(int themeNumber, Texture& temp);
};


//Derived Class: Target Block
class TargetBlock: public Block
{
public:
    TargetBlock();
    ~TargetBlock();
    void setTheme(int themeNumber, Texture& temp);
    bool isFull(Block* Map[10][10]);
};


//Derived Class: Sand Block
class SandBlock: public Block
{
public:
    SandBlock();
    ~SandBlock();
    void setTheme(int themeNumber, Texture& temp);
};

//Derived Class: Add Lives
class AddLives: public Block
{
public:
    AddLives();
    ~AddLives();
    void setTheme(int themeNumber, Texture& temp);
    void Invoke (Player* CurrentPlayer);
};


//Derived Class: Add Moves
class AddMoves: public Block
{
public:
    AddMoves();
    ~AddMoves();
    void setTheme(int themeNumber, Texture& temp);
    void Invoke(Player* CurrentPlayer);
};

#endif /* Blocks_hpp */
