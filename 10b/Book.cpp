/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the Book class.  It has a
* default constructor, a static const int for check out length and get methods.
******************************************************************************/

#include "Book.hpp"

const int Book::CHECK_OUT_LENGTH = 21;

/******************************************************************************
*							default constructor
* The default constructor sets author and passes the other strings to the
* LibraryItem class constructor.
******************************************************************************/
Book::Book(std::string id, std::string t, std::string a) : LibraryItem(id, t)
{
	author = a;
}

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

std::string Book::getAuthor()
{
	return author;
}