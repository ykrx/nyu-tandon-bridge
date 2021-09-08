#include <iostream>
#include <ctime>

const int DEFAULT_MINIMUM = 1;
const int DEFAULT_MAXIMUM = 100;
const int MAXIMUM_NUMBER_OF_GUESSES = 5;

int main() {
    int correctNumber;
    int minimum = DEFAULT_MINIMUM;
    int maximum = DEFAULT_MAXIMUM;
    int numberOfGuesses = 0;
    int numberOfGuessesLeft = MAXIMUM_NUMBER_OF_GUESSES;
    int guess = 0; // initialized to 0 to trigger game start

    srand(time(0)); // NOLINT
    correctNumber = (rand() % DEFAULT_MAXIMUM) + 1; // NOLINT

    /* GAME START */
    std::cout << "I thought of a number between " << minimum << " and " << maximum << "! Try to guess it.";
    std::cout << "\n";

    do {
        std::cout << "Range: [" << minimum << ", " << maximum << "], Number of guesses left: " << numberOfGuessesLeft;
        std::cout << "\n";
        std::cout << "Your guess: ";
        std::cin >> guess;

        numberOfGuesses++;
        numberOfGuessesLeft--;

        if (guess < correctNumber) {
            /*
             * Update minimum only if:
             * 1. Guess is greater than current minimum
             * AND
             * 2. Guess is less than the DEFAULT_MINIMUM
             *
             * Otherwise, keep current minimum
            */
            minimum = guess < minimum ? minimum : guess < DEFAULT_MINIMUM ? DEFAULT_MINIMUM : guess + 1;
            std::cout << "Wrong! My number is bigger." << "\n\n";
        }else if (guess > correctNumber) {
            /*
             * Update maximum only if:
             * 1. Guess is less than current maximum
             * AND
             * 2. Guess is greater than the DEFAULT_MAXIMUM
             *
             * Otherwise, keep current minimum
            */
            maximum = guess > maximum ? maximum : guess > DEFAULT_MAXIMUM ? DEFAULT_MAXIMUM : guess - 1;
            std::cout << "Wrong! My number is smaller." << "\n\n";
        }
    } while (guess != correctNumber && numberOfGuessesLeft != 0);

    if (numberOfGuessesLeft == 0) {
        /* GAME OVER: LOST */
        std::cout << "Out of guesses! My number is " << correctNumber;
    }

    if (guess == correctNumber) {
        /* GAME OVER: WON */
        std::cout << "Congrats! You guessed my number in " << numberOfGuesses << " guesses.";
    }

    return 0;
}
