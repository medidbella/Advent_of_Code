# Solution Explanation

## Part 1

### Approach
I have used a simple class to implement a circular buffer that represents the dial
	and added two methods the increase/decrease the value of the dial
	then looped over the input and called the appropriate method depending
	on the first char of each line (L->left, R->right) 

### Complexity
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

## Part 2

### Approach
made some simple modifications to same class from part one so it will keep count of 
	the number of times a rotation has passed by 0 

### Complexity
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)