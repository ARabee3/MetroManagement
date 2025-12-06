#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Station.h"
using namespace std;

class Route {
protected:
    vector<Station*> stops;
    double totalDistance;

public:
    Route() { totalDistance = 0.0; }

    Route(vector<Station*> _stops, double _totalDistance) {
        set_stops(_stops);
        set_totalDistance(_totalDistance);
    }

    void Add_Station(Station* s) {
        if (s == nullptr) throw invalid_argument("Cannot add null Station pointer!");
        stops.push_back(s);
    }
    //set and get
    void set_stops(vector<Station*> _stops) {
        for (Station* s : _stops) {
            if (s == nullptr) throw invalid_argument("Stops vector contains null Station pointer!");
        }
        stops = _stops;
    }

    void set_totalDistance(double _totalDistance) {
        if (_totalDistance < 0) throw invalid_argument("Total distance cannot be negative!");
        totalDistance = _totalDistance;
    }

    void CalculateDistance() {
        totalDistance = stops.size() * 5.0;
    }
    double getDistance() {
        return totalDistance;
    }
    //Display
    void displayRoute() {
        cout << "Route Details: " << endl;
        for (int i = 0; i < stops.size(); i++) {
            cout << i + 1 << "- ";
            stops[i]->display();
            cout << endl;
        }
        cout << "Total Distance: " << totalDistance << " km" << endl;
    }
};
