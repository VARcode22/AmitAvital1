#pragma once

class Friend;
class Pages;
class Facebook
{
public:
		Friend** members;
		unsigned int logSizeMem = 0;
		unsigned int phySizeMem = 1;
		Pages** pages;
		unsigned int logSizePage = 0;
		unsigned int phySizePage = 1;

		Facebook() { pages = nullptr; members = nullptr;};
		~Facebook() { delete[] members; delete pages;};

		void addMember(const char* n, unsigned int d, unsigned int m, unsigned int y);
		void addPage(Pages* page);
		Friend** doReallocMember();
		void printAllMembers();

	
};