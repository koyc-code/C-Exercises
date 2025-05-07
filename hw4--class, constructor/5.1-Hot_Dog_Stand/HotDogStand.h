#pragma once
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();//destructor
	void justSold();
	void print();
	int thisStandSoldAmount();
    static int allStandSoldAmount(); //return static int 
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;//static : 所有同種class共用同值, global 初始化
};

