#include <vector>
#include <iostream>
#include <string>
#include "Movie.h"
#include "Movies.h"
#include "MainMenu.h"

int main()
{
	std::vector<Movies> category_library_main{};
	bool active_program{ true };

	while (active_program == true) {
		int choice{};
		main_menu_text();
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			get_all_library(category_library_main);
			system("pause");
			system("CLS");
			break;
		case 2:
			get_movies_library(category_library_main);
			system("pause");
			system("CLS");
			break;
		case 3:
			create_new_movies_library(category_library_main);
			system("pause");
			system("CLS");
			break;
		case 4:
			add_new_movie_to_cateogry(category_library_main);
			system("pause");
			system("CLS");
			break;
		case 5:
			category_menu(category_library_main);
			system("pause");
			system("CLS");
			break;
		case 0:
			active_program = false;
			break;
		default:
			system("CLS");
			break;
		};
	}
}

