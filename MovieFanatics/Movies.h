#pragma once

#include "Movies.h"
#include <vector>
#include <iostream>
#include "Movie.h"

class Movies {
private:
	std::string movie_category_name;
	std::vector<Movie> movies_stored;
	int movie_quantity;
	double overall_rating;
public:
	Movies(std::vector<Movie> new_movie_storage, std::string new_movie_category_name = "No-Name", int new_movie_quantity = 0, double new_overall_ratings = 0);

	std::string get_name();

	void set_name(std::string new_name);

	std::vector<Movie> get_movie_category();

	void add_movie();

	double get_avg_ratings();

	void calculate_new_avg_ratings();

	int movie_storage_qty();
};

