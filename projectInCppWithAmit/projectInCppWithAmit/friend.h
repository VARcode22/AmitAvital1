//#ifdef __FRIEND_H
//#define __FRIEND_H
#pragma once
#define NAME_LEN 31

class Pages;
class Status;


class Friend
{
private:
	char name[NAME_LEN];
	unsigned int birthDay[3];//[0]day,[1]mouth,[2]year
	Friend** myFriends;
	unsigned int logSizeFriends = 0;
	unsigned int phySizeFriends = 1;
	Pages** likedPages;
	unsigned int numOfPages = 0;
	Status* myStatus;
	unsigned int phySizeStatus = 1;
	unsigned int logSizeStatus = 0;
public:
	Friend() = default;
	Friend(const char* n, unsigned int d, unsigned int m, unsigned int y);
	~Friend();
	bool setName(const char* n);
	bool setBirthDate(unsigned int d, unsigned int m, unsigned int y);
	bool addFriend(Friend* newFriend);
	bool removeFriend(Friend* newFriend);
	bool addStatus(Status& status);


	const char* getName()	const;
	const unsigned int* getBirthDay() const;
	void printFriends() const;
	void printStatus() const;
	void printAllStatus() const;
	bool checkExistFriend(Friend* newFriend) const;
	Friend** doRealloc();
	Status* doReallocForStatus();
	void create(const char* n, unsigned int d, unsigned int m, unsigned int y);
};
//#endif //__FRIEND_H