#include <iostream>
using namespace std;

const float CLUB_CARD_DISCOUNT = 0.1;
const float HALF_OFF_DISCOUNT = 0.5;

int main() {
    // integers initialized to -1 to trigger positive integer checks
    double firstItemPrice = -1, secondItemPrice = -1;
    char clubCard;
    double taxRate = -1, taxes;
    double basePrice, bogoPrice, discountedPrice, totalPrice;

    /* Input */

    // Loops to make sure prices are positive integers
    while (firstItemPrice < 0) {
        cout << "Enter price of first item: ";
        cin >> firstItemPrice;
    }

    while (secondItemPrice < 0) {
        cout << "Enter price of second item: ";
        cin >> secondItemPrice;
    }

    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubCard;

    while (taxRate < 0) {
        cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
        cin >> taxRate;
    }

    /* Calculations */
    basePrice = firstItemPrice + secondItemPrice;
    // take 50% off the cheaper of the two items
    bogoPrice = (min(firstItemPrice, secondItemPrice) * HALF_OFF_DISCOUNT) + max(firstItemPrice, secondItemPrice);

    // set bogoPrice as discountedPrice by default, if club card member, subtract discount from bogoPrice
    discountedPrice = bogoPrice;
    if (clubCard == 'y' || clubCard == 'Y') {
        discountedPrice = bogoPrice - (bogoPrice * CLUB_CARD_DISCOUNT);
    }

    taxes = discountedPrice * (taxRate / 100); // divide taxRate by 100 to convert percentage to decimal
    totalPrice = discountedPrice + taxes;

    /* Output */
    cout << "Base price: " << basePrice;
    cout << endl;
    cout << "Price after discounts: " << discountedPrice;
    cout << endl;
    cout << "Total price: " << totalPrice;

    return 0;
}
