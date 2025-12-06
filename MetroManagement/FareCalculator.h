#include "Ticket.h"
#include "Subscription.h"
class FareCalculator {
public:
    static double ComputeFare(Ticket* ticket, Subscription* subscription = nullptr) {
        double fare = ticket->CalculateFare();
        if (subscription) {
            fare *= (1 - subscription->GetDiscount());
        }
        return fare;
    }
};