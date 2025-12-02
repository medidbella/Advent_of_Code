# Solution Explanation

## Part 1

### Approach
	looped through the values in each id range while dividing
		the numbers (as a string) to two parts if they are identical
		then the current ID is invalid and will be added to our counter
		+ in case an ID has an odd number of digits it is skipped so 
		no unnecessary checking will happen

### Complexity
- **Time Complexity:** O(N * k) 
		N : number of ranges
		k : average of numbers between all ID ranges
- **Space Complexity:** O(1)

## Part 2

### Approach
	the idea here is to figure out the size of each parallel chunk i can 
		make out of each number, example:
		num = "1234"=> (1, 2) meaning i can split it where each substring
		can have a size of 1 or 2 without having any left chars
		to have the numbers you just need all the divisors of the digit
		number, our example has 4 digits and 4 is divisible by 1 and 2
		after getting the divisors just use each one as the size of 
		the substrings and compare them with each other
		this time odd numbers ARE checked too 
### Complexity
- **Time Complexity:** O(N * k * l)
	N : number of ranges
	k : average of numbers between all ID ranges
	l : average number of all divisors

- **Space Complexity:** O(l)