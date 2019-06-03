#ifndef Functions_hpp
#define Functions_hpp

//#include "UniversalHeader.hpp"
#include "Blocks.hpp"

void Play_Sound(Sound* Sound, SoundBuffer* Buffer, int index, bool SoundOn);
void Change_Theme(int index, Block* Map [10] [10], Block* Background [10] [10], Texture temp[7]);
void Map_Parser(int level,Block* Map [10] [10], int Theme);
void Movement_Handler (Player* CurrentPlayer, Block* Map[10][10],int stepNumber, char direction, RenderWindow* window, Text text, Block* Background [10] [10]);
void Handle_Game(RenderWindow& window, Player* CurrentPlayer, Block* Map[10][10], Text text, Block* Background [10] [10], bool& RestartLevel, bool& Menu);
void Render_Game (RenderWindow& window, Block* Map[10][10], Player* CurrentPlayer, Text text, Block* Background [10] [10]);
void Handle_Menu(RenderWindow &window);
bool isOver(Player* CurrentPlayer, Block* Map[10][10]);
bool playerWon(Player* CurrentPlayer, Block* Map[10][10]);
void RandomLevelGenerator(Block* Map [10] [10]);
void SaveRecords (int Levels);
void DisplayHint (int Theme, RenderWindow& window);
void Render_Game_MP (RenderWindow& window, Block* Map[10][10], Player* Players[2], Text text, Block* Background[10][10]);
void Handle_Game_MP(RenderWindow& window, Player* Players[2], Block* Map[10][10], Text text, Block* Background [10] [10], bool& RestartLevel, bool& Menu);
Block* BlockRandomizer();


#endif /* Functions_hpp */
