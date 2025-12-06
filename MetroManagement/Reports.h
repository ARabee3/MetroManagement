#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Train.h"
#include "Trip.h"
#include "Passenger.h"

using namespace std;

// ==========================================
// Base Report Interface
// ==========================================
class Report {
public:
    virtual void Generate() = 0; // Pure virtual function
    virtual ~Report() {}
};

// ==========================================
// 1. Train Health & Maintenance Report
// ==========================================
// Analyzes a specific Train object to report its status, mileage, and costs.
class TrainHealthReport : public Report {
private:
    Train* train;

public:
    TrainHealthReport(Train* _train) {
        train = _train;
    }

    void Generate() override {
        if (!train) return;

        cout << "\n+---------------------------------------------+" << endl;
        cout << "|            TRAIN HEALTH REPORT              |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "  Train ID       : " << train->getID() << endl;
        cout << "  Engine Type    : " << train->getEngine().getType() << endl;
        cout << "  Current Mileage: " << train->getMileage() << " km" << endl;

        // Logic: Calculate health based on mileage (example logic)
        string healthStatus = "Excellent";
        if (train->getMileage() > 10000) healthStatus = "Needs Inspection";
        if (train->requiresMaintenance()) healthStatus = "CRITICAL - Maintenance Required";

        cout << "  Health Status  : " << healthStatus << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "  Maintenance Log Summary:" << endl;
        cout << "  Total Records  : " << train->getMaintenanceRecordCount() << endl;
        cout << "  Total Spent    : $" << fixed << setprecision(2) << train->getTotalMaintenanceCost() << endl;
        cout << "+---------------------------------------------+\n" << endl;
    }
};

// ==========================================
// 2. Trip Receipt / Summary
// ==========================================
// Takes a completed Trip object and generates a receipt for the passenger.
class TripReceipt : public Report {
private:
    Trip* trip;

public:
    TripReceipt(Trip* _trip) {
        trip = _trip;
    }

    void Generate() override {
        if (!trip) return;

        Passenger* p = trip->getPassenger();
        Route* r = trip->getRoute();

        cout << "\n+---------------------------------------------+" << endl;
        cout << "|              OFFICIAL TRIP RECEIPT          |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "  Passenger : " << p->GetName() << endl;
        cout << "  ID        : " << p->GetNationalID() << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "  Route Dist: " << r->getDistance() << " km" << endl;
        cout << "  Total Fare: $" << fixed << setprecision(2) << trip->getFare() << endl;
        cout << "  Status    : PAID via SmartCard" << endl;
        cout << "+---------------------------------------------+\n" << endl;
    }
};

// ==========================================
// 3. Financial Revenue Report
// ==========================================
// Accumulates data. In a real system, this would look at a database.
// Here, we can pass it a list of fares collected.
class FinancialReport : public Report {
private:
    vector<double> transactions;

public:
    void AddTransaction(double amount) {
        transactions.push_back(amount);
    }

    void Generate() override {
        double total = 0;
        for (double t : transactions) total += t;

        cout << "\n+---------------------------------------------+" << endl;
        cout << "|           DAILY FINANCIAL REPORT            |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "  Total Trips Processed : " << transactions.size() << endl;
        cout << "  Total Revenue         : $" << fixed << setprecision(2) << total << endl;
        cout << "  Average Fare          : $" << (transactions.empty() ? 0 : total / transactions.size()) << endl;
        cout << "+---------------------------------------------+\n" << endl;
    }
};