#pragma once

#define NAME_LEN 31

class Friend;
class Stauts;

class Page
{
private:
	char name[NAME_LEN];
	Stauts** pageStatus;
	int numOfStatus;
	Friend** myFriend;
	unsigned int numOfFriends;
public:
	bool setPage(char* name);
	bool addFriend(Friend* newFriend);
	bool removeFriend(Friend* removeFriend);
	bool addStatus(char* status);

	void printFriends() const;
	void printAllStatus() const;

};

