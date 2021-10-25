#pragma once

#include "Movie.h"
#include <iostream>

class Movie {
private:
	std::string name;
	int view_count;
	int rating;
public:
	Movie(std::string movie_name = "untitled", int movie_view_count = 0, int movie_rating = 0);

	std::string get_name();

	void set_name(std::string new_name);
	
	int get_view_count();

	void increase_view_count();

	int get_rating();

	void set_rating(int new_rating);
};
