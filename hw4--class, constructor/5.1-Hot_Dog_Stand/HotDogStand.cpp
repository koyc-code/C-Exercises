#include "HotDogStand.h"
#include <iostream>
using namespace std;
int HotDogStand::totalSellAmount = 0;

//constructor
HotDogStand::HotDogStand()
{
	this->standId = (char*)"";//強制轉型(""為const char pointer)
	this->hotDogSellAmount = 0;

}

HotDogStand::HotDogStand(const char * id)
{
	this->standId = (char*)id;
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	this->standId = (char*)id;
	this->hotDogSellAmount = amount;
	totalSellAmount += amount;
}

//destructor : delete the class (需額外處理pointer)
HotDogStand::~HotDogStand()
{
	//delete [] this->standId; //delete pointer, add [] so that it delete the whole array
}

void HotDogStand::justSold()
{
	this->hotDogSellAmount += 1;
	totalSellAmount += 1;
}

void HotDogStand::print()
{
	cout << this->standId << " " << this->hotDogSellAmount<<endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
