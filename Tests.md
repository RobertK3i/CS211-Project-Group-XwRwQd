# CS 211 Group Project - Testing

We tested both programs using OnlineGDB with C++17. We wanted to make sure the programs handled normal inputs correctly, gave the right results, and didn't have problems with basic commands.

## Part A - 2048 Game

We ran the 2048 game and tested the movement commands, merging, scoring, saving/loading, help menu, and exiting.

### 2048 Test Results

| # | Input / Test | Expected Result | Actual Result | Pass/Fail |
|---|---|---|---|---|
| 1 | Start game, choose `n` when asked to load a save | Start a 5x5 board with two tiles, score 0, and moves 0 | Started with two 2 tiles, score 0, and moves 0 | Pass |
| 2 | Enter `l` | Move tiles left and combine matching tiles | Tiles moved left correctly | Pass |
| 3 | Enter `u` | Move tiles up and merge matching tiles | Tiles moved up, score increased to 4, moves increased to 2 | Pass |
| 4 | Enter `d` | Move tiles down and combine matching tiles | Down movement worked and score increased to 8 | Pass |
| 5 | Enter `r` | Move tiles right and combine matching tiles | Right movement worked and score increased to 20 | Pass |
| 6 | Continue playing and merging tiles | Update the board, score, and successful move count | Score reached 120 after 23 successful moves, with a highest tile of 16 | Pass |
| 7 | Enter an invalid command | Display an error and continue the game | Displayed "Invalid command. Press h for help." | Pass |
| 8 | Enter `h` | Display the controls and instructions | Help menu displayed all movement and game commands | Pass |
| 9 | Enter `s` and then `o` | Save the current game and load the saved data | Save succeeded and loading displayed score 120, moves 23, and the same board | Pass |
| 10 | Enter `e` | Exit the game normally | Displayed "Goodbye!" and exited | Pass |

### Some Actual 2048 Output

**Starting the game**

```text
2048 - 5x5
Load saved game? (y/n): n

Score: 0
Successful moves: 0
Highest tile: 2
```

**Movement and merging**

After the first left movement:

```text
Score: 0
Successful moves: 1
Highest tile: 2
```

After moving up and merging two tiles:

```text
Score: 4
Successful moves: 2
Highest tile: 4
```

We kept playing and the score continued increasing as tiles were combined.

**Saving and loading**

```text
Enter command (u,d,l,r,s,o,n,h,e): s
Saved to savegame.txt.

Enter command (u,d,l,r,s,o,n,h,e): o
Game loaded successfully!

Score: 120
Successful moves: 23
Highest tile: 16
```

The board also displayed the same tile values after loading. This confirmed the saved data could be read back, although this recording did not include changing the board between saving and loading.

**Exiting**

```text
Enter command (u,d,l,r,s,o,n,h,e): e
Goodbye!
```

### 2048 Results

All 10 basic checks listed above passed.

We were able to play the game, move and merge tiles in every direction, increase the score, and save/load game data. The program also handled invalid commands and displayed the help menu correctly.

These results came from an actual gameplay session that reached 23 successful moves and a score of 120.

### 2048 Tests Still to Verify

The following cases were not demonstrated in the recorded gameplay output:

- Multiple merges in one row, such as `2 2 2 2 2` becoming `4 4 2 0 0`
- Reaching 2048 and displaying the win message
- Filling the board with no possible moves to trigger game over
- Loading a missing or damaged save file
- Using `n` during gameplay to confirm or cancel a new game
- Making a move that changes nothing and checking that the move count stays the same
- Changing the game after saving and confirming that loading restores the earlier state

These are not included in the passed test count.

---

## Part B - Luhn Validation

We tested the Luhn program with valid and invalid 16-digit numbers, incorrect input lengths, letters, spaces, and multiple entries.

### Luhn Test Results

| # | Input | Expected Result | Actual Result | Pass/Fail |
|---|---|---|---|---|
| 1 | `4532015112830366` | Passes checksum | PASSES, sum = 50 | Pass |
| 2 | `4532015112830367` | Fails checksum | FAILS, sum = 51 | Pass |
| 3 | `0000000000000018` | Passes, leading zeros kept | PASSES, sum = 10 | Pass |
| 4 | `453201511283036` | Reject, 15 digits | Invalid format | Pass |
| 5 | `45320151128303666` | Reject, 17 digits | Invalid format | Pass |
| 6 | `453201511283036X` | Reject, non-digit | Invalid format | Pass |
| 7 | `4532 0151 1283 0366` | Reject, internal spaces | Invalid format | Pass |
| 8 | Several checks, then `q` | Correct results and clean exit | Handled multiple inputs and displayed "Goodbye." | Pass |

### Some Actual Luhn Output

**Test 1 - Valid checksum**

```text
Enter a 16-digit number (or q to quit): 4532015112830366
Format OK. Checksum PASSES (sum = 50).
```

**Test 2 - Invalid checksum**

```text
Enter a 16-digit number (or q to quit): 4532015112830367
Format OK. Checksum FAILS (sum = 51).
```

**Test 3 - Leading zeros**

```text
Enter a 16-digit number (or q to quit): 0000000000000018
Format OK. Checksum PASSES (sum = 10).
```

**Tests 4-7 - Invalid inputs**

The program rejected inputs that were too short, too long, or contained letters or spaces.

```text
Invalid format: enter exactly 16 digits (0-9) with no spaces, letters, or punctuation.
```

**Test 8 - Multiple inputs**

We entered these without restarting:

```text
Enter a 16-digit number (or q to quit): 4111111111111111
Format OK. Checksum PASSES (sum = 30).

Enter a 16-digit number (or q to quit): 12345
Invalid format: enter exactly 16 digits (0-9) with no spaces, letters, or punctuation.

Enter a 16-digit number (or q to quit): q
Goodbye.
```

### Luhn Results

All 8 required tests passed.

The program correctly identified numbers that passed or failed the checksum. It also rejected incorrect formats, kept leading zeros, and allowed us to enter multiple numbers without restarting.

We didn't find any problems during these tests.

---

## Final Testing Summary

| Program | Checks Recorded | Passed | Failed |
|---|---|---|---|
| 2048 Game | 10 | 10 | 0 |
| Luhn Validation | 8 | 8 | 0 |
| **Total** | **18** | **18** | **0** |

Both programs passed the checks documented here.

The 2048 game worked during normal gameplay, including movement, scoring, merging, and reading/writing a save file. The Luhn program correctly handled the required checksum and input-format tests.

Testing was done using single-file versions of the programs in OnlineGDB. We still need to verify the original separate-file builds and finish the additional 2048 tests listed above before calling the entire project fully tested.
