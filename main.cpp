#include "settingsmenu.hpp"
#include "mainmenu.hpp"
#include "Functions.hpp"
#include "MainFunctions.hpp"

int main()
{
    RenderWindow win;
    win.create(VideoMode(1000, 1000), "Sobokan");
    
    Display_Menu(win);
}
