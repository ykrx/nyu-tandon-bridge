#include <iostream>
using namespace std;

int main() {
    int num1 = -1, num2 = -1; // Initialized to -1 to trigger positive-integer check loop
    int addition, subtraction, multiplication, div, mod;
    double division;

    while (num1 <= 0 || num2 <= 0) {
        cout<<"Please enter two positive integers, separated by a space: "<<endl;
        cin>>num1>>num2;
    }

    /* Calculations */
    addition = num1 + num2;
    subtraction = num1 - num2;
    multiplication = num1 * num2;
    division = (double)num1 / (double)num2; // Cast integers to doubles to perform real division
    div = num1 / num2;
    mod = num1 % num2;

    /* Output */
    cout<<num1<<" + "<<num2<<+" = "<<addition<<endl;
    cout<<num1<<" - "<<num2<<+" = "<<subtraction<<endl;
    cout<<num1<<" * "<<num2<<+" = "<<multiplication<<endl;
    cout<<num1<<" / "<<num2<<+" = "<<division<<endl;
    cout<<num1<<" div "<<num2<<+" = "<<div<<endl;
    cout<<num1<<" mod "<<num2<<+" = "<<mod<<endl;

    return 0;
}
