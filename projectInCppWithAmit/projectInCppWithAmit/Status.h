#pragma once 
#define STATUS_LEN 256

class Status
{
private:
	char content[STATUS_LEN];
	int  statusType;
public:
	Status() = default;
	Status(const Status& other);
	void createStatus(char* status);
	void printStatus() const;
};
