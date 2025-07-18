package main


import (
	"fmt"
	"strings"
	"os"
	"bufio"
	"strconv"

)


func main() {
	file, err := os.Open("input")
	if err != nil {
		fmt.Println(err)
		return
	}
	scanner := bufio.NewScanner(file)
	
	right := make(map[int]int)
  left := make(map[int]int)

	for scanner.Scan() {
		line := strings.Split(scanner.Text(), "   ");
		number, _ := strconv.Atoi(line[0])
		left[number]++ 
		number, _ = strconv.Atoi(line[1])
		right[number]++

	}

	var result int;
	for key, value := range left  {
		_, exist := right[key]
		if (!exist) {
			continue
		}
		result += (key * value * right[key])
	}
	fmt.Println(result)
}
