#ifndef Functions_hpp
#define Functions_hpp

//#include "UniversalHeader.hpp"
#include "Blocks.hpp"

void Play_Sound(Sound* Sound, SoundBuffer* Buffer, int index, bool SoundOn);
void Change_Theme(int index, Block* Map [15] [15], Block* Background [15] [15]);
void Map_Parser(int level,Block* Map [15] [15], Player* CurrentPlayer);
void Movement_Handler (Player* CurrentPlayer, Block* Map[15][15],int stepNumber, char direction, RenderWindow* window, Text text, Block* Background [15] [15]);
void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[15][15], Text text, Block* Background [15] [15]);
void Render_Game (RenderWindow& window, Block* Map[15][15], Player* CurrentPlayer, Text text, Block* Background [15] [15]);
void Handle_Menu(RenderWindow &window);
bool isOver(Player* CurrentPlayer, Block* Map[15][15]);
bool playerWon(Player* CurrentPlayer, Block* Map[15][15]);
void RandomLevelGenerator(int level, Block* Map [15] [15], Player* CurrentPlayer);
Block* BlockRandomizer();


#endif /* Functions_hpp */
