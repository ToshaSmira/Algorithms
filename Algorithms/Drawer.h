#pragma once
#include <string>
#include "PositionEnum.h"

//example using
//print_text("Left text");
//print_text("Right text", RIGHT);
//print_text("Center text", MID);

class Drawer
{
	private:
		int tab = 0;
		int width_line = 0;
		int width_empty_line = 0;
		
		void print_line();
		void print_empty_line(int count = 0);

		void print_name();
		void print_rectangle(int);
				
		void print_text(std::string, Position = LEFT);
		void print_console_text(std::string text);
		
		std::string left_position_text(std::string);
		std::string mid_position_text(std::string);
		std::string right_position_text(std::string);

		std::string empty_text(int);
		std::string check_length_text(std::string);//length == 0 is OK
		std::string center_text(std::string text, size_t size_view);
	public:
		char filler;
		std::string name;
		
		Drawer();
		~Drawer();

		void print_start_page();
};

