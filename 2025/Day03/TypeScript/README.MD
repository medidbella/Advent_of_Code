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

## Part 2

### Approach
	the end goal is to get the largest 12 digit long number from each line of the input
		to get the correct result i iterate over the string 12 times to get largest digit
		while leaving room (in input) for incoming iterations, each iteration will start from
		the index of digit chosen in the previous one also the number and also the room left 
		is decremented in each iteration heres is an example:
		input = 111211193456788, in the first iteration the digit 2 will be used first 
		since its the biggest digit that will leave at least 11 digits left 
		in the second iteration we will also look for the largest digit but this time 
		the condition is to leave 10 digits since we already have chosen one digit out of 12.  

### Complexity
- **Time Complexity:** O(N)
	even though there's a loop inside a loop,
	the number of outer iterations is a fixed (12),
	so it does not make it O(n²).

- **Space Complexity:** O(1)