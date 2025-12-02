# Solution Explanation

## Part 1

### Approach
I used a direct mathematical approach to solve the problem. Instead of simulating the movement, I calculated the final position for each instruction instantly using the modulo operator.
- If the direction is 'L', I subtract the value and add 100 before applying modulo (to handle negative numbers).
- If the direction is 'R', I add the value.
- After updating the position, I check if it equals 0.

### Complexity
- **Time Complexity:** O(N) — where N is the number of lines in the input. The calculation for each line is constant time.
- **Space Complexity:** O(1) — Only a few integer variables are used.

## Part 2

### Approach
Since we need to count *every* time the dial touches 0 (not just the final position), I switched to a simulation approach.
- For every instruction, I run a loop `n` times (where `n` is the rotation distance).
- Inside the loop, I increment or decrement the position by 1.
- In every single step of the loop, I check if the position is 0 and increment the counter.

### Complexity
- **Time Complexity:** O(S) — where S is the sum of all rotation amounts (total steps). Since we iterate step-by-step, the runtime depends on the total distance rotated, not just the number of lines.
- **Space Complexity:** O(1)
