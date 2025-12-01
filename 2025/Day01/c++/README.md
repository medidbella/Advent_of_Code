Solution Explanation

The problem involves tracking a position on a circular track of 100 positions (0-99), starting at position 50, and counting the number of times the position 0 is visited based on movement instructions (e.g., L10, R5).

Part 1

Approach

In Part 1, the movement instruction is treated as a single, instantaneous jump. We read the input instruction (L or R followed by $n$ steps) and update the position directly using modular arithmetic.

The key calculation for circular movement on a 100-unit track is:

Right/Increase (R): (pos + n) % 100

Left/Decrease (L): (pos - n + 100) % 100 (Adding 100 ensures the result of the modulo operation is positive, even if pos - n is negative).

We check if the new calculated position is 0 and increment the counter if it is.

Complexity

Time Complexity: $O(M)$, where $M$ is the total number of movement instructions. Each instruction is processed in $O(1)$ time.

Space Complexity: $O(1)$, as only a few constant-space variables (pos, count, s) are used regardless of the input size.

Part 2

Approach

The requirements for Part 2 changed: instead of treating the movement as a single jump, we must now simulate the movement step-by-step and count every time position 0 is crossed.

To adapt, the instantaneous jump calculation was replaced with an inner loop. For each instruction, we iterate $n$ times (where $n$ is the number of steps), moving the position by $+1$ or $-1$ in each iteration.

Inside the inner loop, the position is updated using the basic modular arithmetic for a single step:

Right/Increase: (pos + 1) % 100

Left/Decrease: (pos - 1 + 100) % 100

We check for pos == 0 and increment the counter after every single step.

Complexity

Time Complexity: $O(N)$, where $N$ is the total number of individual steps across all instructions. Since the inner loop dominates the computation, the complexity scales with the total distance traveled, not just the number of instructions.

Space Complexity: $O(1)$, same as Part 1.
