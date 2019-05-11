#ifndef Functions_hpp
#define Functions_hpp

#include "UniversalHeader.hpp"
#include "Blocks.hpp"
#include "Players.hpp"

void Play_Sound(Sound* Sound, SoundBuffer* Buffer, int index);
void Change_Theme(int index, Block* Map [15] [15]);
void Map_Parser(int level,Block* Map [15] [15], Player* CurrentPlayer);
void Movement_Handler (Player* CurrentPlayer, Block* Map[15][15],int stepNumber, char direction);
void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[15][15]);
void Render_Game (RenderWindow& window, Block* Map[15][15], Player* CurrentPlayer, Text text);
void Handle_Menu(RenderWindow &window);
bool isOver(Player* CurrentPlayer, Block* Map[15][15]);
bool playerWon(Player* CurrentPlayer, Block* Map[15][15]);


#endif /* Functions_hpp */
