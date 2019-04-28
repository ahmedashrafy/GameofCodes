#ifndef Blocks_hpp
#define Blocks_hpp

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Block
{
protected:
    RectangleShape Object;
    string ID;
    int Special;
    
public:
    virtual void setTheme(int themeNumber) = 0 ;
    virtual bool moveBlock(int stepNumber, char direction)
    {
        
    }
    virtual string getID()
    {
        return ID;
    }
    void setPosition(int x, int y)
    {
        Object.setPosition(x, y);
    }
    Block();
    ~Block();
};

class MovingBlock: public Block
{
public:
    MovingBlock();
    ~MovingBlock();
    bool moveBlock(int stepNumber, char direction);
    void setTheme(int themeNumber);
};

class WallBlock: public Block
{
public:
    WallBlock();
    ~WallBlock();
    void setTheme(int themeNumber);
};

class EmptyBlock: public Block
{
public:
    EmptyBlock();
    ~EmptyBlock();
    void setTheme(int themeNumber);
};

class TargetBlock: public Block
{
public:
    TargetBlock();
    ~TargetBlock();
    void setTheme(int themeNumber);
};

class SandBlock: public Block
{
public:
    SandBlock();
    ~SandBlock();
    void setTheme(int themeNumber);
};

class AddLives: public Block
{
public:
    AddLives();
    ~AddLives();
    void setTheme(int themeNumber);
};

class AddMoves: public Block
{
public:
    AddMoves();
    ~AddMoves();
    void setTheme(int themeNumber);
};
#endif /* Blocks_hpp */
