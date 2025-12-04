# Solution Explanation

## Part 1

### Approach
	we parse the input as a grid of characters and iterate over every position (y, x).
		for each '@' character we collect its 8 neighboring chars and count how many
		of them are also '@', if that count is less than 4 we increment the result

### Complexity:**
- **Time Complexity:** O(N * K)
	N : number of input lines (rows)
- **Space Complexity:** O(1)

## Part 2

### Approach

	in part two we repeatedly scan the grid for any '@'and replace ot replace with '.'
	if it meets the same previous rule (fewer than 4 neighboring `@`). we loop over
	the whole grid in rounds, marking and removing qualified cells until no more
	removals are possible, while incrementing the counter for each removal

### Complexity:**
- **Time Complexity:** O(N * K)

	N : number of input lines (rows)
	K : number of removal rounds
