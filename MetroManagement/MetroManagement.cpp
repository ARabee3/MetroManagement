#include <iostream>
#include <vector>
#include <string>

// Include all your provided header files
// Assuming all headers are in the same directory
#include "Brakes.h"
#include "Engine.h"
#include "MaintenanceRecord.h"
#include "MaintenanceLog.h"
#include "Train.h"
#include "Station.h" // The class you provided in the prompt
#include "Route.h"
#include "SmartCard.h"
#include "Passenger.h"
#include "Ticket.h"
#include "DerivedTicket.h" // DistanceTicket, TimeTicket, etc.
#include "Subscription.h"
#include "FareCalculator.h"
#include "Trip.h"
#include "Reports.h"

using namespace std;


int SmartCard::CardCount = 0;


class TestPassenger : public Passenger {
public:
    TestPassenger(string n, string id, string email) : Passenger(n, id, email) {
        this->card = nullptr;
    }

    void assignCard(SmartCard* newCard) {
        this->card = newCard;
        cout << "[System] SmartCard assigned to Passenger: " << this->GetName() << endl;
    }
};


int main() {
    cout << "*************************************************" << endl;
    cout << "*      METRO MANAGEMENT SYSTEM INTEGRATION      *" << endl;
    cout << "*************************************************" << endl << endl;

    try {
        
        // 1. INFRASTRUCTURE SETUP (Stations & Route)
        cout << "--- STEP 1: Setting up Route ---" << endl;
        Station* s1 = new Station("Central Station", "Downtown - Zone A");
        Station* s2 = new Station("University Park", "Uptown - Zone B");
        Station* s3 = new Station("Tech Hub", "Industrial District - Zone C");

        vector<Station*> stationList = { s1, s2, s3 };

        // Create Route and add stations
        Route* metroRoute = new Route();
        metroRoute->set_stops(stationList);
        metroRoute->CalculateDistance(); // Logic: stops * 5.0

        metroRoute->displayRoute();
        cout << "-------------------------------------------------\n" << endl;


        // 2. TRAIN & MAINTENANCE OPERATIONS
        cout << "--- STEP 2: Train Operations & Maintenance ---" << endl;
        // Create a train with specific engine and brakes
        Train metroTrain(
            "M-101",
            500, // Capacity 
            "Siemens-V2",
            2000,
            EngineType::ELECTRIC,
            "Hydra-Disc",
            BrakeType::REGENERATIVE
        );

        // Train Lifecycle
        metroTrain.start();
        metroTrain.travel(50);   // Travel some distance
        metroTrain.stop();       // Stop at a station

        // Simulate Maintenance
        // Train traveled enough to need a checkup, or we force it
        metroTrain.performQuickMaintenance("Brake Pad Check", 150.50, "Tech-Steve");
        metroTrain.performMaintenance("Engine Filter", 200.00, "2023-10-25", "Routine cleanup", "Tech-Alice");

        // View Logs
        metroTrain.showMaintenanceSummary();
        cout << "-------------------------------------------------\n" << endl;


        // 3. PASSENGER & SMARTCARD SETUP
        
        cout << "--- STEP 3: Passenger & SmartCard ---" << endl;

        // Create Passenger (Using helper class to allow card assignment)
        TestPassenger* passenger = new TestPassenger("Alice Johnson", "987654321", "alice@example.com");
        passenger->ViewProfile();

        // Create and setup SmartCard
        SmartCard* myCard = new SmartCard();
        cout << "[Card] Recharging card with $100..." << endl;
        myCard->Recharge(100.0); // Add money

        // Give card to passenger
        passenger->assignCard(myCard);
        cout << "-------------------------------------------------\n" << endl;


        
        // 4. TICKETING & FARE CALCULATION
        cout << "--- STEP 4: Ticketing Logic ---" << endl;

        // Create a Ticket based on Distance
        double routeDist = metroRoute->getDistance(); // 15 km (3 stations * 5)
        Ticket* ticket = new DistanceTicket(5.0, routeDist); // Base price $5

        // Create a Subscription (e.g., Student gets discount)
        Subscription* studentSub = new StudentPass(); // 25% discount

        // Calculate Final Fare
        double rawFare = ticket->CalculateFare();
        double finalFare = FareCalculator::ComputeFare(ticket, studentSub);

        cout << "Ticket Type: Distance Based" << endl;
        cout << "Base Calculation: $" << rawFare << endl;
        cout << "Applied Subscription: Student (25% off)" << endl;
        cout << "Final Fare to Pay: $" << finalFare << endl;
        cout << "-------------------------------------------------\n" << endl;


        // 5. TRIP EXECUTION
        
        cout << "--- STEP 5: Executing the Trip ---" << endl;

        // Initialize Trip
        Trip currentTrip(passenger, metroRoute, finalFare);

        // Run Trip
        currentTrip.StartTrip();
        cout << "... Traveling ..." << endl;
        currentTrip.EndTrip(); // This should deduct money from SmartCard

        cout << "-------------------------------------------------\n" << endl;


        
         // --- STEP 6: REAL REPORT GENERATION (NEW CODE) ---
         
        cout << "\n--- STEP 6: System Reports ---" << endl;

        // 1. Generate Train Health Report
        // We pass the actual 'metroTrain' object. The report pulls the data inside.
        TrainHealthReport healthReport(&metroTrain);
        healthReport.Generate();

        // 2. Generate Trip Receipt
        // We pass the 'currentTrip' object. It pulls passenger and fare info.
        TripReceipt receipt(&currentTrip);
        receipt.Generate();

        // 3. Generate Financial Report
        // We simulate adding today's transactions to the report
        FinancialReport finance;
        finance.AddTransaction(finalFare);       // The trip we just did
        finance.AddTransaction(15.50);           // Hypothetical previous trip
        finance.AddTransaction(7.25);            // Hypothetical previous trip
        finance.Generate();

        // Cleanup Memory
        delete s1; delete s2; delete s3;
        delete metroRoute;
        delete passenger; // Destructor prints message
        delete myCard;
        delete ticket;
        delete studentSub;

    }
    catch (const exception& e) {
        cerr << "\n[CRITICAL ERROR] Exception occurred: " << e.what() << endl;
    }

    return 0;
}