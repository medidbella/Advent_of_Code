/*
--- Day 5: Print Queue ---
--- Part Two ---

While the Elves get to work printing the correctly-ordered updates, you have a little time to fix the rest of them.

For each of the incorrectly-ordered updates, use the page ordering rules to put the page numbers in the right order. For the above example, here are the three incorrectly-ordered updates and their correct orderings:

    75,97,47,61,53 becomes 97,75,47,61,53.
    61,13,29 becomes 61,29,13.
    97,13,75,29,47 becomes 97,75,47,29,13.

After taking only the incorrectly-ordered updates and ordering them correctly, their middle page numbers are 47, 29, and 47. Adding these together produces 123.

Find the updates which are not in the correct order. What do you get if you add up the middle page numbers after correctly ordering just those updates?

*/

package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"slices"
	"strconv"
)

func fix_invalid_updates(numbers []string, store map[string][]string ) int {

	size := len(numbers)
	for i := 0; i < len(numbers); i++ {
		for j := (size - 1); j > 0; j-- {
			if (slices.Contains(store[numbers[j]], numbers[j - 1])) {
				numbers[j - 1], numbers[j] = numbers[j], numbers[j - 1]
			}
		}
	}
	number, _ := strconv.Atoi(numbers[len(numbers) / 2]) 
	return number 
}


func get_valid_updates(line string, store map[string][]string) bool {
	var list []string
	numbers := strings.Split(line,",")
	for i := 0; i < len(numbers); i++ {
		key := numbers[i]
		for j := 0; j < len(store[key]); j++ {
			if slices.Contains(list, store[key][j]) {
				return false
			}
		}
		list = append(list, numbers[i])
	}
	return true
}

func main() {
	file, err := os.Open("input")
	if err != nil {
		fmt.Println(err)
	}

	scanner := bufio.NewScanner(file)
	store := make(map[string][]string) 
	var result int

	for scanner.Scan() {
		line := scanner.Text()
		if strings.Contains(line, "|") {
			numbers := strings.Split(line, "|")
			store[numbers[0]] = append(store[numbers[0]], numbers[1])
		} else if strings.Contains(line, ",") {
			numbers := strings.Split(line, ",")
			if !get_valid_updates(line,store) {
				result += fix_invalid_updates(numbers ,store)
			}
		}
	}
	fmt.Println(result)
}
