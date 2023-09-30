#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    while (true) {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "Please enter a valid guess between 1 and 100." << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
