// luhn.h
// Header file for the Luhn checksum program.
// A header file only lists the functions (their names and what they take in
// and give back). The actual code for them is in luhn.cpp.

// These two lines and the #endif at the bottom are the "include guard".
// They stop this file from being included twice, which would cause errors.
#ifndef LUHN_H
#define LUHN_H

#include <string>

// Checks the FORMAT of the input only (not the checksum).
// Returns true if the input is exactly 16 characters and every character is
// a digit from 0 to 9. Returns false for anything else (wrong length, letters,
// spaces, punctuation).
bool isValidFormat(std::string number);

// Does the math part of the Luhn algorithm.
// Going from right to left, the rightmost digit stays the same, every second
// digit is doubled, and then everything is added up.
// Returns that total (the "Luhn sum").
int luhnSum(std::string number);

// Returns true if the number passes the Luhn checksum, meaning the Luhn sum
// is divisible by 10. Returns false if it does not.
bool checkLuhn(std::string number);

#endif
