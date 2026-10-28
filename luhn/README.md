Luhn Validation — Project Plan

Goal

Make a separate C++ program that takes a 16-digit number and checks if it's valid using the Luhn algorithm.

What the Program Needs to Do

- Take the user's input as a string so we don't lose any zeros at the beginning.
- Make sure the input is exactly 16 digits long.
- Reject anything with letters, symbols, or the wrong number of digits.
- Make a function called `checkLuhn` to handle the actual math.
- Starting from the second-to-last digit, double every other digit.
- If doubling a digit gives us a number over 9, subtract 9 from it.
- Add all the digits together after doing the math.
- If the total divides evenly by 10, the number passes.
- Give the user the option to check another number or quit.

Who's Doing What

Member B is taking the lead on this part during Checkpoint 5. We'll all need to test it, look over the code, and understand how it works.

Testing

We'll need to try numbers that pass and fail, along with inputs that are too short, too long, or contain letters and symbols. We should also check numbers starting with zero and make sure the program can run multiple checks without restarting.

## Status

Just setting up the plan for now. No code written yet.
