#include <iostream>
#include <string>
#include "Card.h"
#include "InventoryManager.h"

void showMenu() {
    std::cout << "\n=== TCG Inventory System ===" << std::endl;
    std::cout << "1. Add a new card" << std::endl;
    std::cout << "2. Display all cards" << std::endl;
    std::cout << "3. Show total collection value" << std::endl;
    std::cout << "4. Export database to CSV" << std::endl;
    std::cout << "0. Exit program" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    InventoryManager myInventory;
    int choice = -1;

    while (choice != 0) {
        showMenu();
        std::cin >> choice;

        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1: {
            int id;
            std::string name, set, rarity;
            double price;

            std::cout << "Enter Card ID: ";
            std::cin >> id;
            std::cin.ignore(10000, '\n'); 

            std::cout << "Enter Card Name: ";
            std::getline(std::cin, name); 

            std::cout << "Enter Set Name: ";
            std::getline(std::cin, set);

            std::cout << "Enter Rarity: ";
            std::getline(std::cin, rarity);

            std::cout << "Enter Price ($): ";
            std::cin >> price;

            myInventory.addCard(Card(id, name, set, rarity, price));
            std::cout << "Card added successfully!" << std::endl;
            break;
        }
        case 2:
            myInventory.displayAllCards();
            break;
        case 3:
            std::cout << "Total Value: $" << myInventory.calculateTotalValue() << std::endl;
            break;
        case 4:
            myInventory.exportToCSV("collection.csv");
            break;
        case 0:
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
