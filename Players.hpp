#ifndef Players_hpp
#define Players_hpp

#include "UniversalHeader.hpp"

//Base Class: Player
    class Player
    {
    protected:
        int Lives;
        int Moves;
        Texture texture;
        Sprite sprite;
        
    public:
        Player();
        ~Player();
        virtual Sprite getSprite() const;
        virtual int getrow() const;
        virtual int getcol() const;
        virtual void addLives(int addedLives)
        {
            Lives+=addedLives;
        }
        virtual void addMoves(int addedMoves)
        {
            Moves+=addedMoves;
        }
        virtual bool move(int stepNumber, char direction)
        {
                switch(direction)
                {
                    case 'D':
                        sprite.move(0,stepNumber);
                        break;
                        
                    case 'U':
                        sprite.move(0, -stepNumber);
                        break;
                        
                    case 'R':
                        sprite.move(stepNumber, 0);
                        break;
                        
                    case 'L':
                        sprite.move(-stepNumber, 0);
                        break;
                }
        }
        virtual bool unmove(int stepNumber, char direction)
        {
            switch(direction)
            {
                case 'U':
                    sprite.move(0,stepNumber);
                    break;
                    
                case 'D':
                    sprite.move(0, -stepNumber);
                    break;
                    
                case 'L':
                    sprite.move(stepNumber, 0);
                    break;
                    
                case 'R':
                    sprite.move(-stepNumber, 0);
                    break;
            }
        }
        virtual int getLives()
        {
            return Lives;
        }
        
        virtual int getMoves()
        {
            return Moves;
        }
        
        virtual int consumeLive()
        {
            Lives--;
            Moves += 15;
        }
    };

//Derived Class: Arya
    class Arya: public Player
    {
    public:
        Arya();
        Arya(int l, int s, int x, int y);
        ~Arya();
    };

//Derived Class: Cersei
    class Cersei: public Player
    {
    public:
        Cersei();
        Cersei(int l, int s, int x, int y);
        ~Cersei();
    };

//Derived Class: Jon
    class Jon: public Player
    {
    public:
        Jon();
        Jon(int l, int s, int x, int y);
        ~Jon();
    };


#endif /* Players_hpp */