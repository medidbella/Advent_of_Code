# Solution Explanation 🧭

## Part 1

### Approach
The algorithm processes each movement instruction as a **single, instantaneous jump** on the circular track of 100 positions (0-99). The current position, $pos$, is updated directly using **modular arithmetic** based on the direction ($L$ for Left/Decrease, $R$ for Right/Increase) and the number of steps, $n$.

* **Right (R) movement:** The new position is calculated as $(pos + n) \pmod{100}$.
* **Left (L) movement:** The new position is calculated as $(pos - n + 100) \pmod{100}$. Adding $100$ before the modulo operation ensures the result is non-negative, even if $pos - n$ is negative.

After each update, the algorithm checks if the new position is **0** and increments a counter if it is.



---

### Complexity
- **Time Complexity:** $O(M)$, where $M$ is the **total number of movement instructions**. Each instruction is parsed and processed in $O(1)$ time.
- **Space Complexity:** $O(1)$, as the algorithm only uses a few constant-space variables (like $pos$, $count$, and the instruction string $s$).

---

## Part 2

### Approach
The requirement changed from treating movement as a single jump to **simulating the movement step-by-step**, counting every time position **0** is visited.

To adapt, the instantaneous jump calculation was replaced with an **inner loop**. For each instruction (e.g., L10), an inner loop runs $n$ times (e.g., 10 times). Inside this loop, the position is updated by exactly **+1** (for $R$) or **-1** (for $L$) in each iteration using basic modular arithmetic for a single step:

* **Right (+1) step:** $pos \leftarrow (pos + 1) \pmod{100}$.
* **Left (-1) step:** $pos \leftarrow (pos - 1 + 100) \pmod{100}$.

The check for $pos == 0$ and the counter increment now occur **after every single step** inside the inner loop. The complexity is thus dominated by the total number of steps simulated.

---

### Complexity
- **Time Complexity:** $O(N)$, where $N$ is the **total number of individual steps** across all instructions (i.e., the sum of all $n$ values). The simulation scales with the total distance traveled.
- **Space Complexity:** $O(1)$, same as Part 1, as only constant-space variables are used.

Would you like to explore how the complexity of a similar problem might change if the track size were variable?
