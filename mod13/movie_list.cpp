/*
 * =====================================================================================
 *
 *       Filename:  movie_list.cpp
 *
 *    Description:  Create a movie list program. Loads information from txt file
 *                  then, it presents the user with a menu to interact with the data.
 *
 *        Version:  1.0
 *        Created:  04/09/2019 09:41:40 AM
 *       Revision:  none
 *       Compiler (C++):  g++ movie_list.cpp Movie.cpp -o movie_list.out
 *          Usage:  ./movie_list.out 
 *
 *         Author:  Hugo Valle (), hugovalle1@weber.edu
 *   Organization:  WSU
 *
 * =====================================================================================
 */
#include <iostream>
#include <iomanip>      // pretty output
#include <vector>       // for vectors
#include <string>       // for strings
#include <fstream>      // for file stream
#include <sstream>      // to read strings with spaces
#include "Movie.h"
using namespace std;

// Constants and Globals
const string movie_file = "movies.txt";

// Function Prototypes
void display_menu();
vector<Movie> read_movies_from_file();
void view_movies(const vector<Movie>& movies);

// Main Function
int main(int argc, char* argv[])
{
    cout << "The Movie List program\n" << endl;
    vector<Movie> movies = read_movies_from_file();
    char command = 'v';
    while (command != 'x')
    {
        display_menu();
        cout << "Command: ";
        cin >> command;
        switch (command)
        {
            case 'v':
                view_movies(movies);
                break;
            case 'a':
                // add_movie(movies);
                break;
            case 'd':
                // delete_movie(movies);
                break;
            case 'x':
                cout << "Goodbye, amigo!" << endl;
                break;
            default:
                cout << "Not a valid command. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}

void view_movies(const vector<Movie>& movies)
{
    int width = 8;
    cout << left
        << setw(width / 2) << " "
        << setw(width * 4) << "TITLE"
        << setw(width) << "YEAR"
        << setw(width) << "STARS" << endl;
    // Loop over vector and get info using your getters
    int number = 1;
    for(Movie movie : movies)
    {
        cout << setw(width / 2) << number
            << setw(width*4) << movie.get_title()
            << setw(width) << movie.get_year()
            << setw(width) << movie.get_stars() << endl;
        number++;
    }
    cout << endl;
}

// Function Definitions
vector<Movie> read_movies_from_file()
{
    vector<Movie> movies;
    // Read file
    ifstream input_file(movie_file);
    if(input_file)
    {
        string line; 
        while(getline(input_file, line))
        {
            stringstream ss(line);
            string title, tmp;
            int year, stars;
            getline(ss, title, ',');
            getline(ss, tmp, ',');
            year = stoi(tmp);
            getline(ss, tmp, ',');
            stars = stoi(tmp);
            movies.push_back(Movie(title, year, stars));
        }
        input_file.close();
    }

    return movies;
}

void display_menu()
{
    cout << "COMMANDS" << endl
        << "v - View movie list" << endl
        << "a - Add a movie" << endl
        << "d - Delete a movie" << endl
        << "x - Exit" << endl << endl;
}