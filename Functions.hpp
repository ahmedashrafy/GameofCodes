#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
#include "Blocks.cpp"

void Play_Sound(int index);
void Display_Splash();
void Change_Theme(int index, Block* Map [15] [15]);
void Map_Parser(ifstream &file,Block* Map [15] [15], int levelNum);
#endif /* Functions_hpp */
