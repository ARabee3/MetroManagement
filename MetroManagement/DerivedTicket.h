#pragma once
#include "Ticket.h"
class DistanceTicket : public Ticket {
private:
    double distance;
public:
    DistanceTicket(double price, double dist) : Ticket(price)
    {
        distance = dist;
    }

    double CalculateFare() {
        return basePrice + distance * 0.5; // fare: base + 0.5 per km
    }
};

class TimeTicket : public Ticket {
private:
    int durationMinutes;
public:
    TimeTicket(double price, int duration) : Ticket(price)
    {
        durationMinutes = duration;
    }

    double CalculateFare() {
        return basePrice + durationMinutes * 0.1; // fare: base + 0.1 per minute
    }
};

class SpecialTicket : public Ticket {
private:
    double multiplier; // for special events or VIP
public:
    SpecialTicket(double price, double mult) : Ticket(price)
    {
        multiplier = mult;
    }

    double CalculateFare() {
        return basePrice * multiplier; // fare: base * multiplier
    }
};
