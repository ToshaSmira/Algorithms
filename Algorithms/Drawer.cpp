#include "error.h";
#include "Drawer.h"

#include <iostream>


void Drawer::print_line()
{
	std::string result = "";

	for (int i = 0; i < width_line; i++)
	{
		result += Drawer::filler;
	}

	std::cout << result << std::endl;
}

void Drawer::print_name()
{
	std::cout << name << std::endl;
}

void Drawer::print_empty_line(int count)
{
	//std::cout << Drawer::filler;
	//std::cout << empty_text(Drawer::width_empty_line);
	for (int i = 0; i <= count; i++)
	{
		std::cout << Drawer::filler;
		std::cout << empty_text(Drawer::width_empty_line);
		std::cout << Drawer::filler << std::endl;
	}
}

//void Drawer::print_empty_line()
//{
//	std::cout << Drawer::filler;
//	std::cout << empty_text(Drawer::width_empty_line);
//	std::cout << Drawer::filler << std::endl;
//}

void Drawer::print_text(std::string text, Position position)
{
	std::cout << Drawer::filler;
	
	switch (position)
	{
	    case(LEFT):  std::cout << left_position_text(text);
			break;
		case(MID):   std::cout << mid_position_text(text);
			break;
		case(RIGHT): std::cout << right_position_text(text);
			break;
	default:
		std::cout << "  Error Drawer::print_text  ";
		break;
	}

	std::cout << Drawer::filler << std::endl;
}

void Drawer::print_console_text(std::string text)
{
	std::cout << text;
}

void Drawer::print_rectangle(int hight)
{
	print_line();
	for (int i = 0; i < hight; i++)
	{
		print_empty_line();
	}
	print_line();
}

std::string Drawer::left_position_text(std::string text)
{
	std::string result = check_length_text(text);

	if (result.length() == 0) {
		result = empty_text(Drawer::tab) + text;

		int length_correction_txt = Drawer::width_empty_line - result.length();

		result = result + empty_text(length_correction_txt);
	}
		
	return result;
}

std::string Drawer::right_position_text(std::string text)
{
	std::string result = check_length_text(text);

	if (result.length() == 0) {
		result = text + empty_text(Drawer::tab);

		int length_correction_txt = Drawer::width_empty_line - result.length();

		result = empty_text(length_correction_txt) + result;
	}

	return result;
}

std::string Drawer::mid_position_text(std::string text)
{
	std::string result = check_length_text(text);
	
	if (result.length() == 0) {
		result = center_text(text, Drawer::width_empty_line);
	}

	return result;
}

std::string Drawer::empty_text(int count)
{
	std::string result = "";

	for (int i = 0; i < count; i++)
	{
		result += " ";
	}

	return result;
}

std::string Drawer::check_length_text(std::string text)
{
	std::string result = "";
	int length_text = text.length() + Drawer::tab;
	
	if (length_text > Drawer::width_empty_line) {
		result = " Error: exceeded text length ";
	}
	
	return result;
}

std::string Drawer::center_text(std::string text, size_t size_view)
{
	std::string result_text = "";
	
	size_t mid_text = text.length() / 2;
	size_t mid_view = size_view / 2;
	
	if (mid_view >= mid_text) {
		std::string befor_text = "";
		std::string after_text = "";
	
		size_t center_offset = mid_view - mid_text;
	
		for (size_t i = 0; i < center_offset; i++)
		{
			befor_text += " ";
			if (befor_text.length() < center_offset) {
				after_text += " ";
			}
		}
	
		result_text = befor_text + text + after_text;
	
		while (result_text.length() < size_view)
		{
			result_text += " ";
		}
	}
	
	return result_text;
}

Drawer::Drawer()
{
	filler = '*';
	name = "Default";

	tab = 1;
	width_line = 50;
	width_empty_line = width_line - 2;
}

Drawer::~Drawer()
{
	//log message
	std::cout << "Drawer memory has been cleaned. Good bye." << std::endl;
}

void Drawer::print_start_page()
{
	print_line();
	print_empty_line();
	print_text("Center text", MID);
	print_empty_line(3);
	print_line();
	print_console_text("Enter command: ");
}
