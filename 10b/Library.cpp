/******************************************************************************
* Author:  Barry Hall
* Date: November 30, 2015
* Description:  This is the implementation file for the Library class.
******************************************************************************/
#include "Library.hpp"

// default constructor sets current date to 0
Library::Library()
{
	currentDate = 0;
}

/******************************************************************************
*							addLibraryItem
* Description:  This method takes a pointer to a LibraryItem object and pushes
* it onto the vector of holdings in the Library object.
******************************************************************************/
void Library::addLibraryItem(LibraryItem * item)
{
	holdings.push_back(item);
}

/******************************************************************************
*							addPatron
* Description:  This method takes a pointer to a Patron object and pushes
* it onto the vector of members in the Library object.
******************************************************************************/
void Library::addPatron(Patron *person)
{
	members.push_back(person);
}

/******************************************************************************
*						checkOutLibraryItem
* Description:  This method is used to check out an item from the library.  It
* checks to see if the item is in the library using the getLibraryItem method.
* It checks to see if the patron is in the library using the getPatron method.
* It checks the location of the item using the getLocation mehtod.  If all
* of the proper criteria are met, then the item is checked out to the patron.
******************************************************************************/
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
	LibraryItem *item = getLibraryItem(ItemID);
	Patron *member = getPatron(patronID);

	if (item == NULL)
	{
		return "item not found";
	}
	else if (member == NULL)
	{
		return "patron not found";
	}
	else if ((*item).getRequestedBy() != NULL)
	{
		return "item on hold by other patron";
	}
	else if ((*item).getLocation() == CHECKED_OUT)
	{
		return "item already checked out";
	}
	else
	{
		(*item).setLocation(CHECKED_OUT);
		(*item).setCheckedOutBy(member);
		(*item).setDateCheckedOut(currentDate);
		if ((*item).getRequestedBy() == member)
		{
			(*item).setRequestedBy(NULL);
		}
		(*member).addLibraryItem(item);
		return "check out successful";
	}
}

/******************************************************************************
*							returnLibraryItem
* Description:  This method checks to see if the item is part of the library.
* It then checks that the item is actually checked out.  If the right criteria
* are met, then ithe item is either returned to the shelf or put on hold.
******************************************************************************/
std::string Library::returnLibraryItem(std::string ItemID)
{
	LibraryItem *item = getLibraryItem(ItemID);
	if (item == NULL)
	{
		return "item not found";
	}
	else if ((*item).getLocation() != CHECKED_OUT)
	{
		return "item already in library";
	}
	else
	{
		Patron *member = (*item).getCheckedOutBy();
		(*member).removeLibraryItem(item);
		if ((*item).getRequestedBy() != NULL)
		{
			(*item).setLocation(ON_HOLD_SHELF);
		}
		else
		{
			(*item).setLocation(ON_SHELF);
		}
		(*item).setCheckedOutBy(NULL);

		return "return successful";
	}
	
}

/******************************************************************************
*							requestLibraryItem
* Description:  This method checks to see if the item is part of the library.
* It then checks to see if the patron is a member of the library.  The next
* check is to see if the item has already been requested. If the right criteria
* are met, then the patron is assigned to the requestedBy pointer.
******************************************************************************/
std::string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
	LibraryItem *item = getLibraryItem(ItemID);
	Patron *member = getPatron(patronID);

	if (item == NULL)
	{
		return "item not found";
	}
	else if (member == NULL)
	{
		return "patron not found";
	}
	else if ((*item).getRequestedBy() != NULL)
	{
		return "item already on hold";
	}
	else
	{
		(*item).setRequestedBy(member);
		if ((*item).getLocation() == ON_SHELF)
		{
			(*item).setLocation(ON_HOLD_SHELF);
		}
		return "request successful";
	}
}

/******************************************************************************
*								payFine
* Description:  This method checks to see if a patron is a member before
* applying the payment to that patron's account.
******************************************************************************/
std::string Library::payFine(std::string patronID, double payment)
{
	Patron * member = getPatron(patronID);
	if (member == NULL)
	{
		return "patron not found";
	}
	(*member).amendFine(-payment);

	return "payment successful";
}

/******************************************************************************
*							incrementCurrentDate
* Description:  This method increases the current date by one.  It then adjusts
* the fine for all members who have an item checked out for a length of time
* longer than the maximum check out length for that item type.
******************************************************************************/
void Library::incrementCurrentDate()
{
	currentDate += 1;
	std::cout << currentDate << std::endl;
	std::vector<LibraryItem*> checkedOutItems;
	for (int i = 0; i < members.size(); i++)
	{
		checkedOutItems = (*members[i]).getCheckedOutItems();
		for (int j = 0; j < checkedOutItems.size(); j++)
		{
			if (currentDate - (*checkedOutItems[j]).getDateCheckedOut()
				>(*checkedOutItems[j]).getCheckOutLength())
			{
				(*members[i]).amendFine(0.10);
			}
		}
	}
}

/******************************************************************************
*							getPatron
* Description:  This method searches for an id number to determine if a patron
* is a member of the library.  If the id number is not found, NULL is returned
******************************************************************************/
Patron * Library::getPatron(std::string patronID)
{
	for (int i = 0; i < members.size(); i++)
	{
		if ((*members[i]).getIdNum() == patronID)
		{
			return members[i];
		}
	}
	return NULL;
}

/******************************************************************************
*							getLibraryItem
* Description:  This method searches the holdings for an id to determine if an
* item is part of the library.  If the id is not found, NULL is returned.
******************************************************************************/
LibraryItem * Library::getLibraryItem(std::string ItemID)
{
	for (int i = 0; i < holdings.size(); i++)
	{
		if ((*holdings[i]).getIdCode() == ItemID)
		{
			return holdings[i];
		}
	}
	return NULL;
}
