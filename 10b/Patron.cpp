/******************************************************************************
* Author: Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the Patron class.  It has 
* a default constructor, some get and set methods, a remove method and a method
* to amend a fine.
******************************************************************************/
#include "Patron.hpp"

/******************************************************************************
* 							default constructor
* The id number is set to the string passed in.  The name is set to the string
* passed in.  The fine is set to 0.
******************************************************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;
}

std::string Patron::getIdNum()
{
	return idNum;
}

std::string Patron::getName()
{
	return name;
}

std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
	return checkedOutItems;
}

/******************************************************************************
*								addLibraryItem
* Description:  This method adds a library item to the vector of checked out
* items.
******************************************************************************/
void Patron::addLibraryItem(LibraryItem * b)
{
	checkedOutItems.push_back(b);
}

/******************************************************************************
*								addLibraryItem
* Description:  This method erases a library item from the vector of checked 
* out items.
******************************************************************************/
void Patron::removeLibraryItem(LibraryItem * b)
{
	for (int i = 0; i < checkedOutItems.size(); i++)
	{
		if (checkedOutItems[i] == b)
		{
			checkedOutItems.erase(checkedOutItems.begin()+i);
		}
	}
	
}

double Patron::getFineAmount()
{
	return fineAmount;
}

/******************************************************************************
*								amendFine
* Description:  This method increases the amount of the fine if a positive
* value is passed in and decreases the fine if a negative value is passed in.
******************************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}
