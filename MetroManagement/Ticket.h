#pragma once
class Ticket {
protected:
    double basePrice;
public:
    Ticket(double price)
    {
        basePrice = price;
    }
    virtual ~Ticket() {}

    virtual double CalculateFare() = 0; // pure virtual
    double GetBasePrice() { return basePrice; }
};
