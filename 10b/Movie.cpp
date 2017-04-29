/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the Book class.  It has a
* default constructor, a static const int for check out length and get methods.
******************************************************************************/

#include "Movie.hpp"

const int Movie::CHECK_OUT_LENGTH = 7;

/******************************************************************************
*							default constructor
* The default constructor sets director and passes the other strings to the
* LibraryItem class constructor.
******************************************************************************/
Movie::Movie(std::string id, std::string t, std::string d) : LibraryItem(id, t)
{
	director = d;
}

int Movie::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

std::string Movie::getDirector()
{
	return director;
}