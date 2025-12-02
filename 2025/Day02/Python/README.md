# Solution Explanation

## Part 1

### Approach
This solution checks if a number is composed of two identical halves.  
- The function `twice(s)` extracts the first half of the string and duplicates it to reconstruct the full number.
- For each number in the input ranges, it checks if the length of the number's string is even and if the number equals the duplicated halves.
- The sum of all such numbers is calculated and printed.

### Complexity
- **Time Complexity:** O(N * M) — where N is the number of ranges and M is the size of each range. Each number in every range is checked.
- **Space Complexity:** O(1) — Uses a few variables and string conversions.

---

## Part 2

### Approach
This solution detects if a number string is made up by repeating a smaller substring multiple times.  
- The function `repeated(s)` uses a neat trick: if `s` is found in `(s + s)[1:-1]`, it means `s` is a repetition of a smaller pattern.
- Each number in the input ranges is converted to string and tested using this function.
- The sum of all repeated numbers is computed and printed.

### Complexity
- **Time Complexity:** O(N * M * L) — where N is number of ranges, M is size of each range, and L is average length of number strings (due to string slicing and searching).
- **Space Complexity:** O(L) — due to temporary string allocations.

