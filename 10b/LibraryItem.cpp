/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the LibraryItem class. It
* has a default constructor and several get and set methods.
******************************************************************************/
#include "LibraryItem.hpp"

/******************************************************************************
*								default constructor
* The default constructor sets the idCode to the id string passed in.  It sets
* the title to the string passed in.  The checkedOutBy and requestedBy pointers
* are NULL and the location is on the shelf.
******************************************************************************/
LibraryItem::LibraryItem(std::string idc, std::string t)
{
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}

std::string LibraryItem::getIdCode()
{
	return idCode;
}

std::string LibraryItem::getTitle()
{
	return title;
}

Locale LibraryItem::getLocation()
{
	return location;
}

void LibraryItem::setLocation(Locale loc)
{
	location = loc;
}

Patron * LibraryItem::getCheckedOutBy()
{
	return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron * cob)
{
	checkedOutBy = cob;
}

Patron * LibraryItem::getRequestedBy()
{
	return requestedBy;
}

void LibraryItem::setRequestedBy(Patron *reqBy)
{
	requestedBy = reqBy;
}

int LibraryItem::getDateCheckedOut()
{
	return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int dateCO)
{
	dateCheckedOut = dateCO;
}
