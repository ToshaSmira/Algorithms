#include <iostream>
#include <conio.h>

#include "base.h"
#include "Drawer.h"
#include "PositionEnum.h"
//#include <Drawe>

using namespace std;

//******** Singletons ********//
Drawer _drawer;

//******** Start page ********//
void LoadSingletons() {
	string name = PROGRAM_NAME;

	_drawer.name = name + "_drawer";
	_drawer.filler = SHARP;
}

//Show start page
void ShowStartPage() {
	_drawer.print_start_page();
}

//******** Program menu ********//

//ZERO = Return to start page
void zero_input()
{
	std::cout << "0";
}

//ONE  = Binary algorithms page
void one_input()
{
	std::cout << "1";
}

//default log user input from file
void default_input()
{
	//in future update...
}

//******** main ********//

int main()
{
	LoadSingletons();
	ShowStartPage();

	//Init Program menu
	char user_input = 0;
	while (user_input != ESC) {
		user_input = _getch();
		switch (user_input)
		{
			case ZERO: zero_input();
				break;

			case ONE: one_input();
				break;

			default: default_input();
				break;
		}
	}
}

