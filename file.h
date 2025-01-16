//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 15-1-2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_

namespace seneca {
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}

#endif // !SENECA_FILE_H_
