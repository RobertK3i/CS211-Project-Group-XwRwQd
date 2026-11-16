#include <iostream>
#include <string>
#include "luhn.h"   
using namespace std;

int main() {
    string number;   

    cout << "Luhn Checksum Checker" << endl;
    cout << "(this only checks the checksum, it does not prove a card is real)" << endl;

    // keep looping so the user can check as many numbers as they want
    while (true) {
        cout << endl;
        cout << "Enter a 16-digit number (or q to quit): ";

        // getline reads the whole line, including spaces, so we can detect
        // bad input like "4532 0151 1283 0366".
        // It returns false when there is no more input (like Ctrl+D / Ctrl+Z),
        // so we exit cleanly instead of looping forever.
        if (!getline(cin, number)) {
            cout << endl << "No more input. Exiting." << endl;
            break;
        }

        // the exit choice
        if (number == "q" || number == "Q") {
            cout << "Goodbye." << endl;
            break;
        }

        // STEP 1: check the format first.
        // If it is wrong, say so and go back to ask again (continue skips
        // the rest of the loop). This is different from a failed checksum.
        if (!isValidFormat(number)) {
            cout << "Invalid format: enter exactly 16 digits (0-9) with no spaces, "
                 << "letters, or punctuation." << endl;
            continue;
        }

        // STEP 2: the format is good, so now check the checksum.
        // We print the sum too so the result can be checked by hand.
        if (checkLuhn(number)) {
            cout << "Format OK. Checksum PASSES (sum = " << luhnSum(number) << ")." << endl;
        } else {
            cout << "Format OK. Checksum FAILS (sum = " << luhnSum(number) << ")." << endl;
        }
    }

    return 0;   
}
