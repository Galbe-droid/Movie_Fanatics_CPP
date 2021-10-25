#pragma once

#include "MoviesCategoryMenu.h"
#include <vector>
#include <iostream>
#include "Movie.h"
#include "Movies.h"

Movies get_category_for_modification(std::vector<Movies>& category_library);

void get_all_movies_stored(Movies category);

void get_movie_by_name(Movies category);

void modify_movie_view_count(Movies category);

void modify_movie_rating(Movies category);

void delete_movie(Movies category);

void movies_category_menu_text(std::string category_name, int movies_stored);
