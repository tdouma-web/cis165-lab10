#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Named constants for array size and digit bounds
    const int SIZE = 5;
    const int MIN_DIGIT = 0;
    const int MAX_DIGIT = 9;
    const int RANGE = MAX_DIGIT - MIN_DIGIT + 1;

    // Required five-element arrays
    int winningDigits[SIZE];
    int player[SIZE];
    int matchCount = 0;

    // Seed the random number generator once before generating digits
    srand(static_cast<unsigned int>(time(nullptr)));

    // 1. Populate winningDigits with random numbers from 0 through 9
    for (int i = 0; i < SIZE; i++) {
        int randomDigit = (rand() % RANGE) + MIN_DIGIT;
        winningDigits[i] = randomDigit;
    }

    // 2. Ask the user for five digits and store them in player
    cout << "Enter " << SIZE << " lottery digits (each from 0 through 9):" << endl;
    for (int i = 0; i < SIZE; i++) {
        int digitNumber = i + 1;
        cout << "Digit " << digitNumber << ": ";
        cin >> player[i];
    }

    // 3. Compare corresponding positions only and count matches
    for (int i = 0; i < SIZE; i++) {
        if (winningDigits[i] == player[i]) {
            matchCount = matchCount + 1;
        }
    }

    // 4. Display winning digits, player digits, and the match count
    cout << "\n--- Lottery Results ---" << endl;

    cout << "Winning digits: ";
    for (int i = 0; i < SIZE; i++) {
        cout << winningDigits[i] << " ";
    }
    cout << endl;

    cout << "Player digits:  ";
    for (int i = 0; i < SIZE; i++) {
        cout << player[i] << " ";
    }
    cout << endl;

    cout << "Matching digits in the same position: " << matchCount << endl;

    return 0;
}