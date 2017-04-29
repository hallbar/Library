/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the Album class.  It has a
* default constructor, a static const int for check out length and get methods.
******************************************************************************/
#include "Album.hpp"

const int Album::CHECK_OUT_LENGTH = 14;

/******************************************************************************
*							default constructor
* The default constructor sets artist and passes the other strings to the
* LibraryItem class constructor.
******************************************************************************/
Album::Album(std::string id, std::string t, std::string a) : LibraryItem(id, t)	
{
	artist = a;
}

int Album::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

std::string Album::getArtist()
{
	return artist;
}