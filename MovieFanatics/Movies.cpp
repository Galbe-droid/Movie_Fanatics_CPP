#include "Movies.h"
#include <vector>
#include <iostream>
#include "Movie.h"


Movies::Movies(std::vector<Movie> new_movie_storage, std::string new_movie_name, int new_movie_quantity, double new_overall_ratings)
	:movies_stored{ new_movie_storage }, movie_category_name{ new_movie_name }, movie_quantity{ new_movie_quantity }, overall_rating{ new_overall_ratings }{};

std::string Movies::get_name()
{
	return this->movie_category_name;
}

void Movies::set_name(std::string new_name)
{
	this->movie_category_name = new_name;
}

std::vector<Movie> Movies::get_movie_category()
{
	return this->movies_stored;
}

void Movies::add_movie()
{
	std::string movie_name{};
	int view_count{};
	int rating{};

	std::cout << "Category: " << this->get_name() << std::endl;

	std::cout << "What is the movie name: ";
	std::cin >> movie_name;
	std::cout << std::endl;

	std::cout << "How many times did you see it: ";
	std::cin >> view_count;
	std::cout << std::endl;

	do {
		std::cout << "Score (0 to 5): ";
		std::cin >> rating;
		std::cout << std::endl;
	} while (rating < 0 || rating > 5);

	Movie movie{ movie_name, view_count, rating };

	this->movies_stored.push_back(movie);
	this->calculate_new_avg_ratings();
}

double Movies::get_avg_ratings()
{
	return this->overall_rating;
}

void Movies::calculate_new_avg_ratings()
{
	int sum{ 0 };
	int quantity{ 0 };
	

	for (size_t i = 0; i < this->movies_stored.size(); i++)
	{
		sum += this->movies_stored[i].get_rating();
		quantity++;
	}

	double avarage{ (double)sum / (double)quantity };

	this->overall_rating = avarage;
}

int Movies::movie_storage_qty()
{
	int quantity{};

	for (size_t i = 0; i < this->movies_stored.size(); i++)
	{
		quantity++;
	}

	return quantity;
}
