/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the declaration file for the Album class.  It inherits
* from the LibraryItem class.
******************************************************************************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "LibraryItem.hpp"
#include <string>

class Album : public LibraryItem
{
private:
	std::string artist;

public:
	static const int CHECK_OUT_LENGTH;
	Album(std::string, std::string, std::string);
	virtual int getCheckOutLength();
	std::string getArtist();
};

#endif
