#include "luhn.h"
using namespace std;

// Checks that the input is allowed before vaildating
bool isValidFormat(string number) {
    // the number has to be exactly 16 characters long
    if (number.length() != 16) {
        return false;
    }

    // go through every character and make sure it is a digit
    // (characters '0' through '9' are in order, so this range check works)
    for (int i = 0; i < 16; i++) {
        if (number[i] < '0' || number[i] > '9') {
            return false;   // found a letter, space, or symbol
        }
    }
    return true;
}


// Follows the Luhn steps:
//   1. Start at the rightmost digit and move left.
//   2. The rightmost digit stays the same. Every second digit after that
//      (2nd, 4th, 6th ... from the right) is doubled.
//   3. If doubling gives a two-digit number (10 to 18), add its two digits
//      together. This is the same as subtracting 9 (ex: 16 -> 1+6 = 7 = 16-9).
//   4. Add up all of the digits, both the doubled and the unchanged ones.
// The number is passed in by value (a copy), so the original is not changed.
int luhnSum(string number) {
    int sum = 0;        // running total of the transformed digits
    int position = 1;   // counts digits from the right. 1 = rightmost digit

    // i starts at the last character (rightmost digit) and counts down to 0
    for (int i = number.length() - 1; i >= 0; i--) {
        // turn the character into its number value ('7' - '0' = 7)
        int digit = number[i] - '0';

        // even positions (2nd, 4th, 6th ... from the right) get doubled
        if (position % 2 == 0) {
            digit = digit * 2;

            // two-digit result: add the digits together (same as minus 9)
            if (digit > 9) {
                digit = digit - 9;
            }
        }

        // add this digit (doubled or not) to the running total
        sum = sum + digit;

        // move on to the next position to the left
        position++;
    }

    return sum;
}
// Checks if the Luhnsum is divisable by 10 with no remainder
bool checkLuhn(string number) {
    int sum = luhnSum(number);
    return (sum % 10 == 0);
}
