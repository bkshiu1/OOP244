//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 15-1-2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_

namespace seneca {

	struct Movie {
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);

}

#endif // !SENECA_MOVIE_H_