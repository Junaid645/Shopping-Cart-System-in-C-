#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Class representing an item node
class Item {
public:
    int id;
    string name;
    float price;
    int quantity;
    Item* next;

    Item(int itemId, string itemName, float itemPrice, int itemQuantity) {
        id = itemId;
        name = itemName;
        price = itemPrice;
        quantity = itemQuantity;
        next = nullptr;
    }
};

// Class representing the linked list of items (shopping cart)
class ShoppingCart {
private:
    Item* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    // Function to add a new item to the cart
    void add_new_Item(int itemId, string itemName, float itemPrice, int itemQuantity) {
        // Check if item already exists
        Item* temp = head;
        while (temp != nullptr) {
            if (temp->id == itemId) {
                temp->quantity += itemQuantity;
                cout << "Existing item updated. New quantity: " << temp->quantity << endl;
                return;
            }
            temp = temp->next;
        }

        // Item doesn't exist, add new item node
        Item* newItem = new Item(itemId, itemName, itemPrice, itemQuantity);
        newItem->next = head;
        head = newItem;
        cout << "Item added successfully." << endl;
    }

    // Function to remove an item from the cart
    void removeing_Item(int itemId) {
        if (head == nullptr) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        Item* temp = head;
        Item* prev = nullptr;

        while (temp != nullptr && temp->id != itemId) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Item with ID " << itemId << " not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Item with ID " << itemId << " removed successfully." << endl;
    }

    // Function to update quantity for an item in the cart
    void update_Quantity_info(int itemId, int newQuantity) {
        if (head == nullptr) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        Item* temp = head;
        while (temp != nullptr && temp->id != itemId) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Item with ID " << itemId << " not found." << endl;
            return;
        }

        temp->quantity = newQuantity;
        cout << "Quantity updated for item with ID " << itemId << ": " << newQuantity << endl;
    }

    // Function to calculate total price for the shopping cart
    float calculate_Total_Price() {
        float total = 0.0;
        Item* temp = head;
        while (temp != nullptr) {
            total += temp->price * temp->quantity;
            temp = temp->next;
        }
        return total;
    }

    // Function to display the contents of the cart
    void display_Cart_list() {
        if (head == nullptr) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        cout << "Shopping Cart:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        Item* temp = head;
        while (temp != nullptr) {
            cout << setw(5) << temp->id << setw(20) << temp->name << setw(10) << temp->price << setw(10) << temp->quantity << endl;
            temp = temp->next;
        }
        cout << "Total Price: " << calculate_Total_Price() << endl;
    }
};

int main() {
    ShoppingCart cart;
    int num;
    int id, quantity;
    string name;
    float price;

    do {
        cout << "\n*** WELCOME to Shopping Cart Menu ***\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Quantity\n";
        cout << "4. Display Cart\n";
        cout << "5. Exit\n";
        cout << "Enter number of the any above tasks you want to perform: ";
        cin >> num;

        switch (num) {
            case 1:
                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Item Price: ";
                cin >> price;
                cout << "Enter Item Quantity: ";
                cin >> quantity;
                cart.add_new_Item(id, name, price, quantity);
                break;
            case 2:
                cout << "Enter Item ID to Remove: ";
                cin >> id;
                cart.removeing_Item(id);
                break;
            case 3:
                cout << "Enter Item ID to Update Quantity: ";
                cin >> id;
                cout << "Enter New Quantity: ";
                cin >> quantity;
                cart.update_Quantity_info(id, quantity);
                break;
            case 4:
                cart.display_Cart_list();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid Task Number! Please try the correct number." << endl;
        }
    } while (num != 5);

    return 0;
}
