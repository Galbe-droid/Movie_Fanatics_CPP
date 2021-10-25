#pragma once

#include "MainMenu.h"
#include <iostream>
#include <vector>
#include "Movie.h"
#include "Movies.h"
#include "MoviesCategoryMenu.h"

void get_all_library(std::vector<Movies> &category_library);

void get_movies_library(std::vector<Movies> &category_library);

void create_new_movies_library(std::vector<Movies> &category_library);

void add_new_movie_to_cateogry(std::vector<Movies>& category_library);

void main_menu_text();

// Movie Cateogry Menu 

void category_menu(std::vector<Movies>& category_library);

