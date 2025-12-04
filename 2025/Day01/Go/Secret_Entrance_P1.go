package main

import (
	"fmt"
	"os"
	"strings"
)

func extractRotation(dial string) int {
	direction := -1 // left -1, right 1
	rotation := 0
	if dial[0] == 'R' {
		direction = 1
	}
	for i := 1; i < len(dial); i++ {
		rotation *= 10
		rotation += int(dial[i] - '0')
	}

	rotation %= 100
	return direction * rotation
}

func main() {
	data, err := os.ReadFile("input.txt")
	if err != nil {
		panic("Error Can't read the file")
		return
	}

	password := 0
	current := 50
	document := string(data)
	dials := strings.Split(document, "\n")

	for _, dial := range dials {
		rot := extractRotation(dial)
		current += rot

		if current < 0 {
			current += 100
		} else if current > 99 {
			current -= 100
		}

		if current == 0 {
			password += 1
		}
	}
	fmt.Println(password)
}
