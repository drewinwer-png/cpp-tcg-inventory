#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

/*
 * Represents a single Trading Card Game (TCG) item.
 * Stores essential attributes like name, set origin, and market value.
 */
class Card {
private:
    int id;
    std::string name;
    std::string setName;   // e.g., "Black Crystal Blaze", "Trick or Trade"
    std::string rarity;    // e.g., "Holo Rare", "Common"
    double price;

public:
    // Constructor to initialize a new card object
    Card(int cardId, std::string cardName, std::string cardSet, std::string cardRarity, double cardPrice);

    // Getters (Functions to read private data)
    int getId() const;
    std::string getName() const;
    std::string getSetName() const;
    std::string getRarity() const;
    double getPrice() const;

    // Display function to print card details to the console
    void printCardInfo() const;
};

#endif // CARD_H
