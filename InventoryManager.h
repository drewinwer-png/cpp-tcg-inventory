#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <vector>
#include <string> 
#include "Card.h"

class InventoryManager {
private:
    std::vector<Card> database;

public:
    void addCard(const Card& card);
    void displayAllCards() const;
    double calculateTotalValue() const;

    void exportToCSV(const std::string& filename) const;
};

#endif // INVENTORY_MANAGER_H