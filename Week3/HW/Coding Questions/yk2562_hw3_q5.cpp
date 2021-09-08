#include <iostream>
#include <string>
using namespace std;

const double ONE_POUND_IN_KILOGRAMS = 0.453592;
const double ONE_INCH_IN_METERS = 0.0254;

int main() {
    double weightInPounds, heightInInches;
    double weightInKilograms, heightInMeters;
    double bodyMassIndex;
    string weightStatus;

    /* Input */
    cout << "Please enter weight (in pounds): ";
    cin >> weightInPounds;
    cout << "Please enter height (in inches): ";
    cin >> heightInInches;

    /* Calculations */

    // 1. First convert weight & height from imperial units (pounds, inches) into metric units (kilograms, meters)
    weightInKilograms = weightInPounds * ONE_POUND_IN_KILOGRAMS;
    heightInMeters = heightInInches * ONE_INCH_IN_METERS;

    // 2. Then calculate bmi
    bodyMassIndex = weightInKilograms / (heightInMeters * heightInMeters);

    if (bodyMassIndex < 18.5) {
        weightStatus = "Underweight";
    }else if (bodyMassIndex >= 18.5 && bodyMassIndex < 25) {
        weightStatus = "Normal";
    }else if (bodyMassIndex >= 25 && bodyMassIndex < 30) {
        weightStatus = "Overweight";
    }else if (bodyMassIndex > 30) {
        weightStatus = "Obese";
    }

    /* Output */
    cout << "The weight status is: " << weightStatus;

    return 0;
}
