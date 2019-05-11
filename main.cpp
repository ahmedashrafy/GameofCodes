#include "UniversalHeader.hpp"

#include "settingsmenu.hpp"
#include "mainmenu.hpp"
#include "Functions.hpp"
#include "MainFunctions.hpp"

int main()
    {
        RenderWindow window;
        window.create(VideoMode(1000,1000),"Sokoban");
        
        Play_Game(window); 
    }


