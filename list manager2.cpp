#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Needed for std::find
#include <limits>    // Needed for std::numeric_limits

class ListManager {
private:
    std::vector<std::string> items;

public:
    // Function to add an item to the list
    void addItem(const std::string& item) {
        items.push_back(item);
        std::cout << "Item added: " << item << std::endl;
    }

    // Function to remove an item from the list by index
    void removeItemByIndex(int index) {
        if (index >= 0 && index < items.size()) {
            std::cout << "Item removed: " << items[index] << std::endl;
            items.erase(items.begin() + index);
        } else {
            std::cout << "Error: Index out of range" << std::endl;
        }
    }

    // Function to remove an item from the list by value
    void removeItemByValue(const std::string& item) {
        auto it = std::find(items.begin(), items.end(), item);
        if (it != items.end()) {
            std::cout << "Item removed: " << *it << std::endl;
            items.erase(it);
        } else {
            std::cout << "Error: Item not found" << std::endl;
        }
    }

    // Function to display all items in the list
    void displayItems() const {
        if (items.empty()) {
            std::cout << "The list is empty." << std::endl;
        } else {
            std::cout << "List of items:" << std::endl;
            for (int i = 0; i < items.size(); ++i) {
                std::cout << i << ": " << items[i] << std::endl;
            }
        }
    }
};

void showMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add item" << std::endl;
    std::cout << "2. Remove item by index" << std::endl;
    std::cout << "3. Remove item by value" << std::endl;
    std::cout << "4. Display items" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ListManager listManager;
    int choice;

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handling invalid input type for choice
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        std::cin.ignore(); // Ignore the newline character left in the buffer

        if (choice == 1) {
            std::string item;
            std::cout << "Enter item to add: ";
            std::getline(std::cin, item);
            listManager.addItem(item);
        } else if (choice == 2) {
            int index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;

            // Handling invalid input type for index
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid index." << std::endl;
                continue;
            }

            listManager.removeItemByIndex(index);
        } else if (choice == 3) {
            std::string item;
            std::cout << "Enter item to remove: ";
            std::getline(std::cin, item);
            listManager.removeItemByValue(item);
        } else if (choice == 4) {
            listManager.displayItems();
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

