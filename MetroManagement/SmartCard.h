#pragma once
#include <iostream>
#include<string>
#include <random> 
using namespace std;
class SmartCard {
private:
	double Balance = 0;
	int CardID;
	static int CardCount;
	

public:
	SmartCard()
	{
		CardID = GetRandomNumber();
		CardCount++;
	}
	 int GetRandomNumber() {
		random_device rd;
		mt19937 gen(rd());

		// 3. Define the range [min, max] (inclusive)
		// For integers:
		std::uniform_int_distribution<> distr(100000, 999999);
		int random_number = distr(gen);

		return random_number;
	}
	

	void Recharge(double _balance) {
		if (_balance < 0)
			throw invalid_argument("Balance cannot be negative!");
		Balance += _balance;
	}
	bool deduct(double _withdrawl) {
		if (Balance - _withdrawl < 0) {
			return false;
		}
		Balance -= _withdrawl;
		return true;
	}
	// Operator Overloading needs Payment Module Still

};


