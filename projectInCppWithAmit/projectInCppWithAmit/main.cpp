#pragma once
#include <iostream>
using namespace std;
#include "Pages.h"
#include "Status.h"
#include "friend.h"
#include "Facebook.h"

void printMenu();
void addMember(Facebook& facebook);
void makeNewFriends(Facebook& facebook);
void printFreinds(Facebook& facebook);
void printMemberFriends(Facebook& facebook);

int main()
{
	
	Facebook facebook;
	facebook.addMember("Asaf Loz", 22, 1, 1999);
	facebook.addMember("Amit Avital", 3, 8, 1998);

	int choose;
	cout << "Welcome to facebook!"<< endl;
	do{
		printMenu();
		cin >> choose;
		switch(choose)
		{
			case 1:
				addMember(facebook);
				break;
			case 6:
				makeNewFriends(facebook);
				break;
			case 11: 
				printFreinds(facebook);
				break;
		}

	} while (choose >= 1 && choose <= 11);
}
void printFreinds(Facebook& facebook)
{
	int choose;
	cout << "Choose print friends from members or from pages:" << endl;
	cout << "1. Members" << endl;
	cout << "2. Group" << endl;
	cin >> choose;
	if (choose == 1)
		printMemberFriends(facebook);
	else
		return;
		//צריך עוד לממש
	
}
void printMemberFriends(Facebook& facebook)
{
	int choose;
	cout << "Choose member:" << endl;
	facebook.printAllMembers();
	cin >> choose;
	facebook.members[choose - 1]->printFriends();
}
void addMember(Facebook& facebook)
{
	char name[NAME_LEN];
	int d, m, y;
	cout << flush;
	cout << "Enter name of member:" << endl;
	cin >> name;
	cout << "Enter BirthDay Format: Day/Mounth/Year:" << endl;
	cin >> d >> m >> y;
	facebook.addMember(name, d, m, y);
}
void makeNewFriends(Facebook& facebook)
{
	int first, second;
	cout << "Choose the 1st member:" << endl;
	facebook.printAllMembers();
	cin >> first;
	cout << "Choose the 2st friend:"<< endl;
	facebook.printAllMembers();
	cin >> second;
	while(second == first)
	{
		cout << "You chose the same member please chose another" << endl;
		facebook.printAllMembers();
		cin >> second;
	}
	facebook.members[first-1]->addFriend(facebook.members[second-1]);


}

void printMenu()
{
		cout << "Welcome to facebook Main Menu:" << endl;
		cout << "Choose methode:" << endl;
		cout << "1. Add member" << endl;
		cout << "2. Add page" << endl;
		cout << "3. Add status member/page" << endl;
		cout << "4. Show all statuses of member/page" << endl;
		cout << "5. Show recent 10 statuses of member/page" << endl;
		cout << "6. Make new friends" << endl;
		cout << "7. Cancel friends" << endl;
		cout << "8. Add friends to page" << endl;
		cout << "9. Remove friends from page" << endl;
		cout << "10. Show all entity of the system" << endl;
		cout << "11. Show all friends of member/page" << endl;
		cout << endl;
		cout << "12. EXIT" << endl;
}