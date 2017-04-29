/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the declaration file for the Book class.  It inherits
* from the LibraryItem class.
******************************************************************************/

#ifndef MOVIE_HPP
#define MOVIEHPP

#include "LibraryItem.hpp"
#include <string>

class Movie : public LibraryItem
{
private:
	std::string director;

public:
	static const int CHECK_OUT_LENGTH;
	Movie(std::string, std::string, std::string);
	virtual int getCheckOutLength();
	std::string getDirector();
};

#endif
