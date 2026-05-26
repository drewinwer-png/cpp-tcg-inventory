#include "Card.h"
#include <iomanip> // For formatting output (like setting decimal precision)

// Constructor implementation
Card::Card(int cardId, std::string cardName, std::string cardSet, std::string cardRarity, double cardPrice) {
    id = cardId;
    name = cardName;
    setName = cardSet;
    rarity = cardRarity;
    price = cardPrice;
}

// Getters implementation
int Card::getId() const { return id; }
std::string Card::getName() const { return name; }
std::string Card::getSetName() const { return setName; }
std::string Card::getRarity() const { return rarity; }
double Card::getPrice() const { return price; }

// Print functionality
void Card::printCardInfo() const {
    std::cout << "[" << id << "] "
        << name << " | Set: " << setName
        << " | Rarity: " << rarity
        << " | Value: $" << std::fixed << std::setprecision(2) << price
        << std::endl;
}