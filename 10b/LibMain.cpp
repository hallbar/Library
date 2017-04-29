#include "Library.hpp"
#include <iostream>
using std::cout;
using std::endl;

void printItems(std::vector<LibraryItem *> itemsCheckedOut)
{
	for (int i = 0; i < itemsCheckedOut.size(); i++)
	{
		cout << (*itemsCheckedOut[i]).getIdCode() << endl;
	}
}

int main()
{
	Book Book1("8675309", "Carrie", "Stephen King");

	std::string bookTitle = Book1.getTitle();
	std::string bookId = Book1.getIdCode();
	std::string author = Book1.getAuthor();
	int lengthB = Book1.getCheckOutLength();
	Locale locationB = Book1.getLocation();
/*
	cout << "id " << bookId << " title " << bookTitle << " author " << author << endl;
	cout << "checkout length " << lengthB << "location " << locationB << endl;

	Book1.setLocation(ON_HOLD_SHELF);

	locationB = Book1.getLocation();
	cout << "location " << locationB << endl;
*/
	Album Album1("1001", "Revolver", "Beatles");
/*
	std::string albumId = Album1.getIdCode();
	std::string albumTitle = Album1.getTitle();
	std::string artist = Album1.getArtist();
	int lengthA = Album1.getCheckOutLength();

	cout << "id " << albumId << " title " << albumTitle << " artist " << artist << endl;
	cout << "checkout length " << lengthA << endl;
*/
	Movie Movie1("1002", "Empire Strikes Back", "George Lucas");
/*
	std::string movieId = Movie1.getIdCode();
	std::string movieTitle = Movie1.getTitle();
	std::string director = Movie1.getDirector();
	int lengthM = Movie1.getCheckOutLength();

	cout << "id " << movieId << " title " << movieTitle << " director " << director << endl;
	cout << "checkout length " << lengthM << endl;
*/
	Patron member1("1", "John Doe");
	Patron member2("2", "Jane Doe");
	Patron member3("3", "Peter Parker");
/*
	std::string memberId = member1.getIdNum();
	std::string memberName = member1.getName();

	cout << "id " << memberId << " name " << memberName << endl;

	member1.addLibraryItem(&Book1);
	printItems(member1.getCheckedOutItems());i
	member1.addLibraryItem(&Movie1);
	member1.addLibraryItem(&Album1);
	printItems(member1.getCheckedOutItems());

	member1.removeLibraryItem(&Movie1);
	printItems(member1.getCheckedOutItems());
*/
	Library library1;
	library1.addLibraryItem(&Book1);
	library1.addLibraryItem(&Movie1);
	library1.addLibraryItem(&Album1);

	library1.addPatron(&member1);
	library1.addPatron(&member2);
	library1.addPatron(&member3);

	cout << library1.checkOutLibraryItem("1", "1001") << endl;
	cout << library1.requestLibraryItem("2", "1001") << endl;
	cout << library1.checkOutLibraryItem("1", "2001") << endl;
	cout << library1.requestLibraryItem("3", "1001") << endl;
	cout << library1.checkOutLibraryItem("1", "1002") << endl;
	cout << Movie1.getDateCheckedOut() << endl;
	
	//printItems(member1.getCheckedOutItems());
	/*
	for (int i = 0; i < 23; i++)
	{
		library1.incrementCurrentDate();
	}

	double fine1 = member1.getFineAmount();
	cout << "fine 1" << fine1 << endl;
	library1.payFine("1", 1.0);
	fine1 = member1.getFineAmount();
	cout << "fine 1" << fine1 << endl;
	*/
	cout << library1.returnLibraryItem("1001") << endl;
	return 0;
}