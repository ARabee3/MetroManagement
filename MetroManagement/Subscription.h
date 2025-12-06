#pragma once
#include <iostream>
using namespace std;
class Subscription {
protected:
	double Price;
	int ValidityDays;
public:
	virtual double GetDiscount() = 0;
	virtual ~Subscription() {};
};

class MonthlyPass : public Subscription {
public:
	MonthlyPass()
	{
		Price = 300;
		ValidityDays = 30;

	}
	double GetDiscount() {
		return 0.15;
	}
};

class StudentPass : public Subscription {
public:
	StudentPass()
	{
		Price = 600;
		ValidityDays = 120;
	}
public:
	double GetDiscount()  {
		return 0.25;
	}
};
class SeniorPass : public Subscription {
public:
	SeniorPass()
	{
		Price = 1000;
		ValidityDays = 240;
	}

	double GetDiscount()  {
		return 0.35;
	}

};