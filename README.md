***

# 🚇 Metro Management System

A comprehensive C++ simulation of a modern Metro Rail Network. This project demonstrates advanced **Object-Oriented Programming (OOP)** concepts including Composition, Aggregation, Inheritance, Polymorphism, and Exception Handling to manage trains, passengers, ticketing, and maintenance infrastructure.

## 📋 Features

### 🚄 Train & Infrastructure Management
*   **Train Lifecycle**: Start, stop, emergency braking, and travel simulation.
*   **Component Composition**: Trains are composed of complex `Engine` and `Brake` systems (Hydraulic, Regenerative, etc.).
*   **Maintenance Logging**: detailed logs for repairs, tracking costs, parts, and technicians.
*   **Route Logic**: Dynamic calculation of distances between `Stations`.

### 🎫 Ticketing & Fares
*   **Polymorphic Ticketing**: Support for different ticket types:
    *   `DistanceTicket` (Price based on km)
    *   `TimeTicket` (Price based on duration)
    *   `SpecialTicket` (VIP/Events)
*   **Subscription Models**: Discounts for Students, Seniors, and Monthly Pass holders.
*   **Fare Calculator**: Logic to compute final price based on ticket type + subscription status.

### 👤 Passenger & Payment
*   **SmartCard System**: Rechargeable cards with balance validation and deduction logic.
*   **Passenger Profiles**: Management of user data with validation (ID, Email).

### 📊 Reporting System
*   **Train Health Reports**: Auto-generated status based on mileage and maintenance history.
*   **Financial Reports**: Tracking of revenue and operational costs.
*   **Trip Receipts**: Detailed breakdown of travel costs for passengers.

---

## 🛠️ Technical Architecture

This project strictly adheres to OOP principles:

*   **Encapsulation**: All data members are private with validated Getters/Setters.
*   **Inheritance**: Used for `Ticket` types, `Subscription` models, and `Report` generators.
*   **Polymorphism**: Virtual functions allow generic handling of tickets (`CalculateFare()`) and reports (`Generate()`).
*   **Composition**: A `Train` *owns* its `Engine` and `Brakes` (they share the same lifecycle).
*   **Aggregation**: A `Trip` *uses* a `Passenger` and a `Route` (they exist independently).

### Class Structure Overview
```text
├── Infrastructure
│   ├── Station
│   └── Route (List of Stations)
├── Train System
│   ├── Train (Composite Root)
│   ├── Engine
│   ├── Brakes
│   └── MaintenanceLog (Aggregate of Records)
├── Users
│   ├── Passenger
│   └── SmartCard
├── Finance
│   ├── Ticket (Base) -> DistanceTicket, TimeTicket
│   ├── Subscription (Base) -> StudentPass, MonthlyPass
│   └── FareCalculator
└── Reporting
    └── Report (Base) -> TrainHealthReport, FinancialReport
```

---

## 🚀 How to Run

### Prerequisites
*   A C++ Compiler (GCC, Clang, or MSVC).
*   Standard C++11 support or higher.

### Compilation
Since the project uses a modular header structure, compile the `main.cpp` file. Ensure all `.h` files are in the same directory.

**Using g++ (Linux/Mac/MinGW):**
```bash
g++ main.cpp -o MetroSystem
./MetroSystem
```

**Using Visual Studio:**
1.  Create a new "Empty C++ Project".
2.  Import all `.h` files and `main.cpp`.
3.  Build and Run (Ctrl + F5).

---

## 📂 File List

| File | Description |
| :--- | :--- |
| `main.cpp` | Entry point. Demonstrates the workflow of the system. |
| `Train.h` | Manages the train entity and its components. |
| `Engine.h` / `Brakes.h` | Component classes for the train. |
| `MaintenanceLog.h` | Handles repair history and costs. |
| `Passenger.h` | User profile management. |
| `SmartCard.h` | Payment and balance logic. |
| `Ticket.h` / `DerivedTicket.h` | Ticket hierarchy and pricing logic. |
| `Reports.h` | Generates system summaries and receipts. |

---

## 🔮 Future Improvements
*   Add a file I/O system to save Maintenance Logs and Passenger data to `.txt` or `.csv` files permanently.
*   Implement a proper specific `Time` class to schedule train departures.
*   Add a GUI (using Qt or SFML) for a visual representation of the network.

---
