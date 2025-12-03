# Solution Explanation

## Part 1

### Approach
	the first step is to get the largest digit and second largest digits from
		each line and their indexes, after that we have three cases
		case 1: the index of the largest number is smaller than the second largest
		  and thats straightforward means that the largest possible joltage for that 
		  line is: the largest digit + second largest (as string so 1 + 1 = 11)
		case 2: the largest digit is the last one, in that case its also straightforward
		  because the largest possible joltage is just the reverse meaning:
		  second largest digit + the largest one (as a string too)
		case 3: if non of the above cases is faced that means largest digit comes after
		  the second larges one, well in that case we have to determine the largest 
		  digit right of our largest (comes after it) so the largest possible joltage is :
		  largest digit + largest digit after it

### Complexity
- **Time Complexity:** O(N * K)
		N : number of input lines
		K : average amount of run into the third case 
- **Space Complexity:** O(1)

<!-- ## Part 2

### Approach


### Complexity
- **Time Complexity:** O(X)
- **Space Complexity:** O(X) -->