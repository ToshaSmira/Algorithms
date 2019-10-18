#include <iostream>
#include <conio.h>

#include "base.h"

//******** Start page ********//

//Show start page
void ShowStartPage() {
	std::cout << PROGRAM_NAME << "\n";
}

//******** Program menu ********//

//ZERO = Return to start page
void zero_input()
{
	//ShowStartPage();
}

//ONE  = Binary algorithms page
void one_input()
{

}

//default log user input from file
void default_input()
{
	//in future
}

//******** main ********//

int main()
{
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

