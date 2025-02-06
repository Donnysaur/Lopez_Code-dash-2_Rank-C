#include <iostream>
using namespace std;

void PhotoMenu() {
    cout << "\n--Select Photo type: --\n";
    cout << "1. Group Photo (300 PHP)\n"
        "2. Couple Photo (250 PHP)\n"
        "3. Solo Photo (200 PHP)\n"
        "4. Finish Selection\n";
}

int PhotoPrice(int choice) {
    if (choice == 1) return 300;
    if (choice == 2) return 250;
    if (choice == 3) return 200;
    return 0;
}

void processPayment(int totalPrice) {
    int payment = 0, change = 0;
    while (true) {
        cout << "Enter payment Amount: ";
        cin >> payment;
        if (payment >= totalPrice) {
            change = payment - totalPrice;
            cout << "Payment Successful! Change: " << change << " PHP\n";
            break;
        }
        else {
            cout << "Insufficient payment. Try again.\n";
        }
    }
}

int main() {
    char anotherUser;

    cout << "Welcome to the Photoshop Bundle!\n";

    do {
        int totalPrice = 0, choice, quantity;

        while (true) {
            PhotoMenu();
            cin >> choice;
            system("cls");

            if (choice == 4 && totalPrice > 0) break;
            if (choice == 4 && totalPrice == 0) {
                cout << "You must select at least one photo before finishing!\n";
                continue;
            }

            system("cls");
            if (choice >= 1 && choice <= 3) {
                cout << "Enter quantity:\n";
                cin >> quantity;
                if (quantity < 1) {
                    cout << "Invalid quantity! Must be at least 1.\n";
                    continue;
                }
                totalPrice += PhotoPrice(choice) * quantity;
            }
            else {
                cout << "Invalid choice! Try again..\n";
                continue;
            }
        }

        cout << "\n--Total Price: " << totalPrice << " PHP\n";
        processPayment(totalPrice);
        system("cls");

        cout << "Thank you for using Photoshop Bundle!\n";
        cout << "Would another user like to make a purchase? (Y/N): ";
        cin >> anotherUser;
        system("cls");

    } while (anotherUser == 'Y' || anotherUser == 'y');

    cout << "Goodbye! Thank you for using our service.\n";
    return 0;
}
