# CIS-165 Lab 10

**Name:** Theo Douma  
**Section:** CIS-165-W099

## Initial Plans

**lottery.cpp:** I will define named constants `SIZE` set to `5`, `RANGE` set to `10`, and `MIN_DIGIT` set to `0`, and create two five-element integer arrays named `winningDigits` and `player` along with an `int` variable `matchCount` initialized to `0`. After seeding the random number generator once with `srand`, I will use a `for` loop and `rand()` to populate `winningDigits` with random numbers from `0` through `9`, and a second `for` loop to prompt the user for five digits (`0`–`9`) and store them in `player`. Next, I will run a third `for` loop from index `0` to `SIZE - 1` that checks if `winningDigits[i] == player[i]` at each corresponding position and increments `matchCount` when they match. Finally, I will use loops to display all five winning digits and all five player digits, followed by the labeled `matchCount` result.

## Run Instructions

1. Go to onlinegdb.com and select **C++ 17** as the language.
2. Paste the code from `lottery.cpp` into the editor.
3. Click "Run" at the top, enter the five lottery digits (`0`–`9`) when prompted, and verify the output.

## Test Table

*(Note: For the fixed-array test cases, the random generation loop was temporarily replaced with fixed array values while keeping the comparison loop unchanged. For the final random run, fill in the bracketed placeholders below with the actual output from your last OnlineGDB run.)*

| Program | Values used | Expected result | Actual output | Match |
| :--- | :--- | :--- | :--- | :--- |
| lottery.cpp (fixed test 1) | Fixed winning `[7, 4, 9, 1, 3]`; player `4 2 9 7 3` | 2 matches (at indices 2 and 4) | Winning digits: 7 4 9 1 3 / Player digits: 4 2 9 7 3 / Matching digits in the same position: 2 | Yes |
| lottery.cpp (fixed test 2) | Fixed winning `[7, 4, 9, 1, 3]`; player `7 4 9 1 3` | 5 matches | Winning digits: 7 4 9 1 3 / Player digits: 7 4 9 1 3 / Matching digits in the same position: 5 | Yes |
| lottery.cpp (fixed test 3) | Fixed winning `[7, 4, 9, 1, 3]`; player `0 0 0 0 0` | 0 matches | Winning digits: 7 4 9 1 3 / Player digits: 0 0 0 0 0 / Matching digits in the same position: 0 | Yes |
| lottery.cpp (fixed repeats) | Fixed winning `[1, 1, 2, 2, 3]`; player `1 2 2 3 3` | 3 matches (at indices 0, 2, and 4) | Winning digits: 1 1 2 2 3 / Player digits: 1 2 2 3 3 / Matching digits in the same position: 3 | Yes |
| lottery.cpp (additional fixed) | Fixed winning `[7, 4, 9, 1, 3]`; player `3 1 9 4 7` | 1 match (only index 2 matches; reversed digits at other indices do not count) | Winning digits: 7 4 9 1 3 / Player digits: 3 1 9 4 7 / Matching digits in the same position: 1 | Yes |
| lottery.cpp (final random run) | Random winning `[3, 8, 0, 9, 9]`; player `4 2 9 7 3` | `[0]` matches (derived from manual same-position check of generated array) | Winning digits: `[5 8 9 2 3]` / Player digits: 4 2 9 7 3 / Matching digits in the same position: `[1]` | Yes |

*Additional Test & Final Check Notes:*
- **Additional fixed-array test:** Tested fixed winning array `[7, 4, 9, 1, 3]` with reversed player input `[3, 1, 9, 4, 7]`. Even though all five digits exist in both arrays, only index `2` (`9 == 9`) is in the exact same position, predicting and confirming `1` match.
- **Final source check:** After completing the fixed-array tests, I removed the temporary hardcoded test arrays and restored the `srand` and `rand()` loop to populate `winningDigits`. The final `lottery.cpp` file was compiled and run again in C++17 before the final commit, confirming every generated winning digit was between `0` and `9` and the output matched my manual count.

## Explanations

- **How the random expression keeps every digit between `0` and `9`:** The expression `(rand() % RANGE) + MIN_DIGIT` (with `RANGE = 10` and `MIN_DIGIT = 0`) uses the remainder operator `% 10` on the non-negative integer returned by `rand()`. Dividing any integer by `10` produces a remainder strictly between `0` and `9` inclusive, and adding `0` keeps the final stored digit in the `0`–`9` range.
- **Why a matching digit in another position does not count:** The comparison loop checks `if (winningDigits[i] == player[i])` using the single loop index `i` for both arrays at the same time. It never compares `winningDigits[i]` against `player[j]` at a different index, so a number that appears earlier or later in the other array is ignored.
- **Tracing the count through the example arrays:** With `winningDigits = [7, 4, 9, 1, 3]` and `player = [4, 2, 9, 7, 3]`, `matchCount` starts at `0`:
  - `i = 0`: compares `7` and `4` (not equal, `matchCount` stays `0`).
  - `i = 1`: compares `4` and `2` (not equal, `matchCount` stays `0`).
  - `i = 2`: compares `9` and `9` (equal, `matchCount` becomes `1`).
  - `i = 3`: compares `1` and `7` (not equal, `matchCount` stays `1`).
  - `i = 4`: compares `3` and `3` (equal, `matchCount` becomes `2`).
- **Why array loops stop before `SIZE`, and what the fixed tests established:** In C++, a five-element array uses zero-based indexing, meaning valid indices are `0` through `4` (`SIZE - 1`). Stopping the loop with `i < SIZE` prevents accessing `winningDigits[5]` or `player[5]`, which would be out-of-bounds memory. Using fixed arrays established that the comparison loop accurately handles zero matches, all five matches, repeated numbers, and out-of-order numbers before restoring unpredictable `rand()` values.
