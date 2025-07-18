package main

import (
	"fmt"
	"strings"
	"os"
	"bufio"
	"strconv"
	"slices"
	"math"
)


func main() {
	file, err := os.Open("input")
	if err != nil {
		fmt.Println(err)
		return
	}
	scanner := bufio.NewScanner(file)
	
	right := []int{}
  left := []int{}

	for scanner.Scan() {
		line := strings.Split(scanner.Text(), "   ");
		number, _ := strconv.Atoi(line[0])
		left = append(left, number)
		number, _ = strconv.Atoi(line[1])
		right = append(right, number) 
	}

	slices.Sort(left)
	slices.Sort(right)

	distances := make(map[int]int)

	for index, _ := range left {
		distance := int(math.Abs(float64(left[index] - right[index])))
		distances[distance]++;
	}

	var result int

	for key, value := range distances {
		result += (key * value)
	}

	fmt.Println(result)
}
