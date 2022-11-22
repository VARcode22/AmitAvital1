#pragma once

#include "Facebook.h"
#include"friend.h"

#include <iostream>
using namespace std;

void Facebook::addMember(const char* n, unsigned int d, unsigned int m, unsigned int y)
{
	if(logSizeMem >= phySizeMem || logSizeMem == 0)
	{
		members = doReallocMember();
	}

	members[logSizeMem] = new Friend{ n,d,m,y };
	//members[logSizeMem]->create(n, d, m, y);
	logSizeMem++;
}
Friend** Facebook::doReallocMember()
{
	phySizeMem *= 2;
	Friend** newArr = new Friend*[phySizeMem];
	for (int i = 0; i < logSizeMem; i++)
		newArr[i] = members[i];
	delete[]members;
	return newArr;
}
void Facebook::printAllMembers()
{
	for (int i = 0; i <logSizeMem; i++)
		cout <<i+1<<". " << members[i]->getName() <<endl;
}