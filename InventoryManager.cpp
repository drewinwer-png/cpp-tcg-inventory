#include "InventoryManager.h"
#include <iostream>
#include <fstream> 

void InventoryManager::addCard(const Card& card) {
    database.push_back(card);
}

void InventoryManager::displayAllCards() const {
    if (database.empty()) {
        std::cout << "The inventory is currently empty." << std::endl;
        return;
    }

    std::cout << "\n=== Inventory List ===" << std::endl;
    for (const Card& c : database) {
        c.printCardInfo();
    }
    std::cout << "======================" << std::endl;
}

double InventoryManager::calculateTotalValue() const {
    double total = 0.0;
    for (const Card& c : database) {
        total += c.getPrice();
    }
    return total;
}

void InventoryManager::exportToCSV(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    outFile << "ID,Name,Set,Rarity,Price\n";

    for (const Card& c : database) {
        outFile << c.getId() << ","
            << c.getName() << ","
            << c.getSetName() << ","
            << c.getRarity() << ","
            << c.getPrice() << "\n";
    }

    outFile.close();
    std::cout << "Success! Database exported to " << filename << std::endl;
}