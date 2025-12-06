#pragma once
#include <iostream>
using namespace std;
class Subscription {
protected:
	double Price;
	int ValidityDays;
	virtual double GetDiscount() = 0;
};

class MonthlyPass : public Subscription {
	MonthlyPass()
	{
		Price = 300;
		ValidityDays = 30;

	}
	double GetDiscount() override{
		return 0.15;
	}
};

class StudentPass : public Subscription {
	StudentPass()
	{
		Price = 600;
		ValidityDays = 120;
	}
	double GetDiscount() override {
		return 0.25;
	}
};
class SeniorPass : public Subscription {
	SeniorPass()
	{
		Price = 1000;
		ValidityDays = 240;
	}
	double GetDiscount() override {
		return 0.35;
	}

};