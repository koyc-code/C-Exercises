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
	static int totalSellAmount;//static : �Ҧ��P��class�@�ΦP��, global ��l��
};

