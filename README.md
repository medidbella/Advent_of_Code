# Advent of Code

Welcome to [Advent of Code](https://adventofcode.com/) Solutions Repository. This project serves as a central hub for sharing solutions, algorithms, and editorial explanations for the annual puzzles presented during the Advent of Code event.
I invite everyone to contribute their code so we can learn from different approaches and languages.
While the primary focus is the current year, solutions for previous years are also welcome. Feel free to explore and contribute to any year you like!

## Repository Structure

To maintain organization, please adhere strictly to the following directory structure.

**Format:**
`/{Year}/Day{XX}/{Language}/{puzzle_name}_P{x}.{extension}`

**Example:**
```text
2024/
├── Day01/
│   ├── Python/
│   │   ├── Historian_Hysteria_P1.py
│   │   ├── Historian_Hysteria_P2.py
│   │   └── README.md   <-- (Required: Your Editorial/Explanation)
│   └── C++/
│       ├── Historian_Hysteria_P1.cpp
│       ├── Historian_Hysteria_P2.cpp
│       └── README.md
└── Day02/
    └── ...
````

## How to Contribute

We follow a strict **Fork & Pull Request** workflow.

1.  **Fork** this repository to your own GitHub account.
2.  **Clone** your fork to your local machine.
3.  Create your solution following the structure above.
4.  **Push** your changes to your fork.
5.  Open a **Pull Request (PR)** to the `main` branch of this repository.

## Contribution Rules

### 1\. The "Quality over Quantity" Rule

If a solution **already exists** for a specific puzzle in your chosen language, you may still submit a Pull Request. However, for your PR to be accepted and merged, your solution must be **demonstrably better** than the existing one.

"Better" is defined as:

  * **More Optimized:** Lower time complexity (Big O) or lower memory usage.
  * **Cleaner Code:** Significantly more readable, better variable naming, or more idiomatic usage of the language.

### 2\. The Editorial Requirement

Code alone is not enough. Every submission **must** include a `README.md` file in the same folder as the solution. This file should contain an "Editorial" explaining your approach for both parts of the puzzle.

**Editorial Template:**
Please copy this into your `README.md`:

```markdown
# Solution Explanation

## Part 1

### Approach
Describe the algorithm or logic you used to solve Part 1. (e.g., "I used a hash map to track frequency...")

### Complexity
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)

## Part 2

### Approach
Describe how the requirements changed and how you adapted your algorithm.

### Complexity
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)
```

### 3\. Naming Conventions

  * **Day Folders:** Must use two digits (e.g., `Day01`, `Day05`, `Day12`).
  * **Files:** MUST use the name of the puzzle followed by the part number (e.g., `historian_hysteria_P1.py`, `red_nosed_reports_P2.cpp`). Generic names like `main.cpp` or `solver.py` are **not allowed**.

## Leaderboard

Don't forget to join our private leaderboard for this year to track our local progress\!
Code: `5188033-b5f04b6a`

Happy Coding\!
