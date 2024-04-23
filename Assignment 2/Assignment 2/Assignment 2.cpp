#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr)); // Seed the random number generator
    int secretNumber = rand() % 1000 + 1; // Generate a random number between 1 and 1000
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;

    cout << "Guess a number between 1 and 1000." << endl;

    // Loop until the user guesses the number or reaches the maximum number of attempts
    while (attempts < maxAttempts) {
        cout << "Attempt " << attempts + 1 << ": ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << attempts + 1 << " attempts!" << endl;
            if (attempts < maxAttempts - 1) {
                cout << "Either you know the secret or you got lucky!" << endl;
            }
            else {
                cout << "You know the secret!" << endl;
            }
            return 0; // Exit the program
        }
        else if (guess < secretNumber) {
            cout << "Too low. Try again." << endl;
        }
        else {
            cout << "Too high. Try again." << endl;
        }

        attempts++;
    }

    // If the loop completes without the correct guess
    cout << "Sorry, you didn't guess the number. The correct number was " << secretNumber << "." << endl;
    cout << "You should be able to do better!" << endl;

    return 0;
}