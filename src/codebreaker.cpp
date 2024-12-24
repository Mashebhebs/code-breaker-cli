#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

void runGame() {
    string secretNumber = "";
    bool flag = true;

    srand(time(0)); // Seed for random number generation

    // Generate a random 4-digit secret code with unique digits
    while (secretNumber.length() < 4) {
        char randomDigit = '1' + rand() % 8; // Digits in range 1 to 8
        if (secretNumber.find(randomDigit) == string::npos) {
            secretNumber += randomDigit;
        }
    }

    cout << "4-digit Code has been set. Digits in range 1 to 8. You have 12 turns to break it." << endl;
    int numberGuessesMade = 12;
    string guess;

    while (flag) {
        int countCorrectPos = 0;
        int countWrongPos = 0;

        cout << "Input 4-digit code: ";
        cin >> guess;

        // Validate user input
        while (guess.length() != 4 || !all_of(guess.begin(), guess.end(), ::isdigit)) {
            cout << "Please enter exactly 4 digits." << endl;
            cout << "Input 4-digit code: ";
            cin >> guess;
        }

        if (guess == secretNumber) {
            cout << "Number of correct digits in correct place:     4" << endl;
            cout << "Number of correct digits not in correct place: 0" << endl;
            cout << "Congratulations! You are a codebreaker!" << endl;
            cout << "The code was: " << secretNumber << endl;
            flag = false;
        } else {
            numberGuessesMade--;
            if (numberGuessesMade <= 0) {
                cout << "You've run out of turns. Game over!" << endl;
                cout << "The code was: " << secretNumber << endl;
                flag = false;
            } else {
                // Count correct and misplaced digits
                for (size_t i = 0; i < guess.length(); i++) {
                    if (secretNumber[i] == guess[i]) {
                        countCorrectPos++;
                    } else if (secretNumber.find(guess[i]) != string::npos) {
                        countWrongPos++;
                    }
                }

                cout << "Number of correct digits in correct place:     " << countCorrectPos << endl;
                cout << "Number of correct digits not in correct place: " << countWrongPos << endl;
                cout << "Turns left: " << numberGuessesMade << endl;
            }
        }
    }
}

int main() {
    runGame();
    return 0;
}

