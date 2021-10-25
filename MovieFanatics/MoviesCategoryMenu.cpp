#include "MoviesCategoryMenu.h"
#include <vector>
#include <iostream>
#include "Movie.h"
#include "Movies.h"



Movies get_category_for_modification(std::vector<Movies>& category_library)
{
	std::string category_name{};
	std::cout << "What is the Category Name: ";
	std::cin >> category_name;
	std::cout << std::endl;

	for (size_t i = 0; i < category_library.size(); i++)
	{
		if (category_name == category_library[i].get_name() && category_library[i].get_movie_category().size() > 0)
		{
			Movies movie_return(category_library[i]);
			return movie_return;
		}
		else if (category_name == category_library[i].get_name() && category_library[i].get_movie_category().size() == 0)
		{
			std::cout << "No movies added" << std::endl;
			break;
		}
		else
		{
			std::cout << "Category not found" << std::endl;
			break;
		}
	}
}

void get_all_movies_stored(Movies category)
{
	std::vector<Movie> category_storage = category.get_movie_category();

	for (size_t i = 0; i < category_storage.size(); i++)
	{
		std::cout << "Movie name: " << category_storage[i].get_name() << std::endl
			<< "Views: " << category_storage[i].get_view_count() << std::endl
			<< "Rating: " << category_storage[i].get_rating() << std::endl
			<< std::endl;
	}
}

void get_movie_by_name(Movies category)
{
	std::vector<Movie> category_storage = category.get_movie_category();

	std::string movie_name_choice{};

	do {
		std::cout << "Movie name(put 000 to exit): ";
		std::cin >> movie_name_choice;

		for (size_t i = 0; i < category_storage.size(); i++)
		{
			if (category_storage[i].get_name() == movie_name_choice)
			{
				std::cout << "Movie name: " << category_storage[i].get_name() << std::endl
					<< "Views: " << category_storage[i].get_view_count() << std::endl
					<< "Rating: " << category_storage[i].get_rating() << std::endl
					<< std::endl;
			}
			else if (i == (category_storage.size() -1) && category_storage[i].get_name() != movie_name_choice)
			{
				std::cout << "Movie not found";
			}
		}
	} while (movie_name_choice == "000");
}

void modify_movie_view_count(Movies category)
{
	std::vector<Movie> category_storage = category.get_movie_category();
	Movie movie_choosen{};

	std::string movie_name_choice{};

	do {
		std::cout << "Movie name(put 000 to exit): ";
		std::cin >> movie_name_choice;

		for (size_t i = 0; i < category_storage.size(); i++)
		{
			if (category_storage[i].get_name() == movie_name_choice)
			{
				movie_choosen = category_storage[i];	
				movie_choosen.increase_view_count();
			}
			else if (i == (category_storage.size() - 1) && category_storage[i].get_name() != movie_name_choice)
			{
				std::cout << "Movie not found";
			}
		}
	} while (movie_name_choice == "000");
}

void modify_movie_rating(Movies category)
{
	std::vector<Movie> category_storage = category.get_movie_category();
	Movie movie_choosen{};

	std::string movie_name_choice{};

	do {
		std::cout << "Movie name(put 000 to exit): ";
		std::cin >> movie_name_choice;

		for (size_t i = 0; i < category_storage.size(); i++)
		{
			if (category_storage[i].get_name() == movie_name_choice)
			{
				int new_rating{};

				movie_choosen = category_storage[i];

				do {
					std::cout << "New rating (0 to 5): ";
					std::cin >> new_rating;
				} while (new_rating < 0 && new_rating > 5);

				movie_choosen.set_rating(new_rating);
			}
			else if (i == (category_storage.size() - 1) && category_storage[i].get_name() != movie_name_choice)
			{
				std::cout << "Movie not found";
			}
		}
	} while (movie_name_choice == "000");
}

void delete_movie(Movies category)
{
	std::vector<Movie> category_storage = category.get_movie_category();
	Movie movie_choosen{};

	std::string movie_name_choice{};

	do {
		std::cout << "Movie name(put 000 to exit): ";
		std::cin >> movie_name_choice;

		for (size_t i = 0; i < category_storage.size(); i++)
		{
			if (category_storage[i].get_name() == movie_name_choice)
			{
				category_storage.erase(category_storage.begin() + i);
			}
			else if (i == (category_storage.size() - 1) && category_storage[i].get_name() != movie_name_choice)
			{
				std::cout << "Movie not found";
			}
		}
	} while (movie_name_choice == "000");
}

void movies_category_menu_text(std::string category_name, int movies_stored)
{
	std::cout << "Category Name: " << category_name << std::endl
		<< "Movies Added: " << movies_stored << std::endl
		<< std::endl
		<< "1 - See all Movies added." << std::endl
		<< "2 - See a specific Movie." << std::endl
		<< "3 - Modify Movie view count." << std::endl
		<< "4 - Modify Movie rating." << std::endl
		<< "5 - Remove Movie." << std::endl
		<< "0 - Go Back" << std::endl
		<< "Choose: ";
}

