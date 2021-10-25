#include "MainMenu.h"
#include <iostream>
#include <vector>
#include "Movie.h"
#include "Movies.h"
#include "MoviesCategoryMenu.h"

void get_all_library(std::vector<Movies> &category_library)
{
	if (category_library.size() == 0)
	{
		std::cout << "No cateogries registred." << std::endl;
	}
	else
	{
		for (size_t i = 0; i < category_library.size(); i++)
		{
			std::cout << "Category: " << category_library[i].get_name() << std::endl
				<< "Movies Avarage Ratings: " << category_library[i].get_avg_ratings() << std::endl;
		}
	}
}

void get_movies_library(std::vector<Movies> &category_library)
{
	if (category_library.size() == 0)
	{
		std::cout << "No cateogries registred." << std::endl;
	}
	else
	{
		std::string category_name{};
		std::cout << "What is the Category Name: ";
		std::cin >> category_name;
		std::cout << std::endl;

		for (size_t i = 0; i < category_library.size(); i++)
		{
			if (category_name == category_library[i].get_name() && category_library[i].get_movie_category().size() > 0)
			{
				category_library[i].get_movie_category();
			}
			else if (category_name == category_library[i].get_name() && category_library[i].get_movie_category().size() == 0)
			{
				std::cout << "No movies added" << std::endl;
			}
			else
			{
				std::cout << "Category not found" << std::endl;
			}
		}
	}
}

void create_new_movies_library(std::vector<Movies> &category_library)
{
	std::vector<Movie> movie_storage{};
	std::string category_name{};

	std::cout << "What is the Category Name: ";
	std::cin >> category_name;
	std::cout << std::endl;

	Movies new_movies_category{ movie_storage, category_name };

	category_library.push_back(new_movies_category);

	std::cout << "New Category '" << category_name << "' created." << std::endl;
}

void add_new_movie_to_cateogry(std::vector<Movies> &category_library)
{
	if (category_library.size() == 0)
	{
		std::cout << "No cateogries registred." << std::endl;
	}
	else
	{
		std::string category_name{};
		std::cout << "What is the Category Name to add a film: ";
		std::cin >> category_name;
		std::cout << std::endl;

		for (size_t i = 0; i < category_library.size(); i++)
		{
			if (category_name == category_library[i].get_name())
			{
				category_library[i].add_movie();
			}
			else
			{
				std::cout << "Category not found" << std::endl;
			}
		}
	}
}

void main_menu_text()
{
	std::cout << "Movie Fanatics Database" << std::endl
		<< "1 - See all categories." << std::endl
		<< "2 - See one movie Category." << std::endl
		<< "3 - Create a new Category." << std::endl
		<< "4 - Insert a new movie on a Category." << std::endl
		<< "5 - Category Menu." << std::endl
		<< "0 - Exit." << std::endl
		<< "Choose: ";
}

// Movie Cateogry Menu 

void category_menu(std::vector<Movies>& category_library)
{
	if (category_library.size() == 0)
	{
		std::cout << "No cateogries registred." << std::endl;
	}
	else
	{
		int choice{};
		Movies category_choosen{ get_category_for_modification(category_library) };

		do
		{
			movies_category_menu_text(category_choosen.get_name(), category_choosen.movie_storage_qty());
			
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				get_all_movies_stored(category_choosen);
				system("pause");
				system("CLS");
				break;

			case 2:
				get_movie_by_name(category_choosen);
				system("pause");
				system("CLS");
				break;

			case 3:
				modify_movie_view_count(category_choosen);
				system("pause");
				system("CLS");
				break;

			case 4:
				modify_movie_rating(category_choosen);
				system("pause");
				system("CLS");
				break;

			case 5:
				delete_movie(category_choosen);
				system("pause");
				system("CLS");
				break;

			case 0:
				system("CLS");
				break;

			default:
				system("CLS");
				break;
			}
		} while (choice != 0);
	}	
}


