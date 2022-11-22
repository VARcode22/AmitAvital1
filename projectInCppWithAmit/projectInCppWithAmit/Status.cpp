#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include"Status.h"
#include <string.h>
#include <iostream>

void Status::createStatus(char* status)
{
	strcpy_s(content, status);
	statusType = 0;
}
Status::Status(const Status& other)
{
	strcpy_s(content,other.content);
	statusType = other.statusType;
}
void Status:: printStatus() const
{
	std::cout << content << std::endl;
}