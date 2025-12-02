# Solution Explanation

## Part 1

### Approach
I used a direct mathematical approach to solve the problem. Instead of simulating the movement, I calculated the final position for each instruction instantly using the modulo operator.
- If the direction is 'L', I subtract the value and add 100 before applying modulo (to handle negative numbers).
- If the direction is 'R', I add the value.
- After updating the position, I check if it equals 0 to increment the result.

### Complexity
- **Time Complexity:** O(N) — where N is the number of lines in the input. The calculation for each line is constant time.
- **Space Complexity:** O(1) — Only a few integer variables are used.

---

## Part 2

### Approach
Since we need to count *every* time the dial crosses or touches 0 (not just the final position), I switched to a simulation approach that tracks the dial's position carefully.
- For each instruction, I update the position by adding or subtracting the steps.
- I calculate how many times the position crossed multiples of 100 by using `ceil` and `floor` functions.
- I increment the result accordingly based on how many full "rotations" or thresholds of 100 the dial passed through.
- I adjust the position to always remain within 0 to 99 using modulo operations.

### Complexity
- **Time Complexity:** O(N) — where N is the number of instructions. Each instruction is processed in constant time.
- **Space Complexity:** O(1) — Only a fixed number of variables are used for tracking the position and result.

---
