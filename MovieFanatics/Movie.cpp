#include "Movie.h"
#include <iostream>

Movie::Movie(std::string movie_name, int movie_view_count, int movie_rating)
	:name{ movie_name }, view_count{ movie_view_count }, rating{ movie_rating }{};

std::string Movie::get_name()
{
	return this->name;
}

void  Movie::set_name(std::string new_name)
{
	this->name = new_name;
}

int  Movie::get_view_count()
{
	return this->view_count;
}

void  Movie::increase_view_count()
{
	int choice{};

	do {

		std::cout << "1 - Increase by 1." << std::endl
			<< "2 - Insert new value." << std::endl
			<< "Choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			++this->view_count;
			break;

		case 2:
			std::cout << "New value: ";
			std::cin >> this->view_count;
			break;

		default:
			break;
		}

	} while (choice != 1 && choice != 2);
}

int  Movie::get_rating()
{
	return this->rating;
}

void  Movie::set_rating(int new_rating)
{
	this->rating = new_rating;
}


