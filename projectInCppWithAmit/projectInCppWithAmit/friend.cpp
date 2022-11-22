#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "friend.h"
#include "Status.h"
#include <string.h>
//#include <cstdlib>
using namespace std;

bool Friend::setName(const char* n)
{
	if (strlen(name) >= NAME_LEN)
		return false;

	strcpy_s(name, n);
	return true;
}

bool Friend::setBirthDate(unsigned int d, unsigned int m, unsigned int y)
{
	if (d > 31 || d < 1)
		return false;
	else if (m > 12 || m < 1)
		return false;
	else if (y < 0)
		return false;

	birthDay[0] = d;
	birthDay[1] = m;
	birthDay[2] = y;
	return true;
}

bool Friend::addFriend(Friend* newFriend)
{

	if (checkExistFriend(newFriend) || newFriend == nullptr)
		return false;

	else if (logSizeFriends >= phySizeFriends || logSizeFriends == 0)
		myFriends = doRealloc();
	
	myFriends[logSizeFriends++] = newFriend;
	newFriend->addFriend(this);
	return true;

}
// check if the friend exist in the list
bool Friend::checkExistFriend(Friend* newFriend) const
{
	for (int i = 0; i < logSizeFriends; i++)
	{
		if (myFriends[i] == newFriend)
			return true;
	}
	return false;
}
bool Friend:: removeFriend(Friend* newFriend)
{
	if (!checkExistFriend(newFriend))
		return false;
	
	int index = 0;
	if (logSizeFriends == 0)
	{
		cout << "There is no friends" << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < logSizeFriends; i++)
		{
			if (myFriends[i] == newFriend)
			{
				myFriends[i] = myFriends[i+1];
				i++;
			}
		}
		logSizeFriends-=1;
		newFriend->removeFriend(this);
		return true;
	}
	
}
bool Friend::addStatus(Status& status)
{
	if (logSizeStatus >= phySizeStatus || logSizeStatus == 0)
	{
		myStatus = doReallocForStatus();
		return false;
	}
	myStatus[logSizeStatus++] = status;
	return true;

}
const char* Friend::getName() const
{
	return name;
}
const unsigned int* Friend::getBirthDay() const
{
	return birthDay;
}
void Friend::printFriends() const
{
	for(int i = 0; i < logSizeFriends; i++)
		cout << i+1 <<". " << myFriends[i]->getName() << endl;
}
void Friend::printStatus() const
{
	if(logSizeStatus == 0)
	{
		cout << "There are no statuses";
		return;
	}
	int index = 1;
	for(int i = logSizeStatus - 1; i >= 0 && index <= 10;  i--, index++)
		myStatus[i].printStatus();
	
}
void Friend::printAllStatus() const
{
	if(logSizeStatus == 0)
	{
		cout << "There are no statuses";
		return;
	}
	for(int i = logSizeStatus - 1; i >= 0; i--)
		myStatus[i].printStatus();
}

Friend** Friend::doRealloc()
{
	phySizeFriends *= 2;
	Friend** newArr = new Friend*[phySizeFriends];
	for (int i = 0; i < logSizeFriends; i++)
	{
		newArr[i] = myFriends[i];
	}
	delete[] myFriends;
	return newArr;

}
Status*::Friend::doReallocForStatus()
{
	
	phySizeStatus *= 2;
	Status* newArrToR = new Status[phySizeStatus];
	for (int i = 0; i < logSizeStatus; i++)
		newArrToR[i] = myStatus[i];
	delete[] myStatus;
	return newArrToR;
}
Friend::Friend(const char* n, unsigned int d,unsigned int m,unsigned int y)
{
	strcpy_s(name, n);
	setBirthDate(d, m, y);
	logSizeFriends = 0;
	phySizeFriends = 1;
	 myFriends= nullptr;
	likedPages = nullptr;
	numOfPages=0;
	myStatus = nullptr;
	phySizeStatus=1;
	logSizeStatus=0;

}
Friend::~Friend()
{
	delete[] likedPages;
	delete[] myStatus;
	delete[] myFriends;
}
void Friend::create(const char* n, unsigned int d, unsigned int m, unsigned int y)
{
	strcpy_s(name, n);
	setBirthDate(d, m, y);
	logSizeFriends = 0;
	phySizeFriends = 1;
	 myFriends= nullptr;
	likedPages = nullptr;
	numOfPages=0;
	myStatus = nullptr;
	phySizeStatus=1;
	logSizeStatus=0;
}