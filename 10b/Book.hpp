/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the declaration file for the Book class.  It inherits
* from the LibraryItem class.
******************************************************************************/

#ifndef BOOK_HPP
#define BOOK_HPP

#include "LibraryItem.hpp"
#include <string>

class Book : public LibraryItem
{
private:
	std::string author;

public:
	static const int CHECK_OUT_LENGTH;
	Book(std::string, std::string, std::string);
	virtual int getCheckOutLength();
	std::string getAuthor();
};

#endif