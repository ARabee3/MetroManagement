#pragma once
#include <iostream>
#include <stdexcept>
#include "Route.h"
#include "Passenger.h"
using namespace std;

class Trip {
protected:
    Route* route;
    Passenger* passenger;
    double fare;

public:
    Trip(Passenger* _passenger, Route* _route, double _fare) {
        set_passenger(_passenger);
        set_route(_route);
        set_fare(_fare);
    }
    //set and get
    void set_passenger(Passenger* _passenger) {
        if (_passenger == nullptr) throw invalid_argument("Passenger cannot be null!");
        passenger = _passenger;
    }

    void set_route(Route* _route) {
        if (_route == nullptr) throw invalid_argument("Route cannot be null!");
        route = _route;
    }

    void set_fare(double _fare) {
        if (_fare < 0) throw invalid_argument("Fare cannot be negative!");
        fare = _fare;
    }

    Passenger* getPassenger() { return passenger; }
    Route* getRoute() { return route; }
    double getFare() { return fare; }

    void StartTrip() {
        cout << "Trip Started\n";
        cout << "Passenger: " << passenger->GetName() << endl;
        cout << "Route Distance: " << route->getDistance() << " km\n";
    }

    void EndTrip() {
        cout << "Trip Ended\n";
        if (passenger->GetCard()) {
            passenger->GetCard()->deduct(fare);
            cout << "Fare Deducted: " << fare << endl;
        }
        else {
            cout << "No SmartCard found! Payment Failed\n";
        }
    }
};