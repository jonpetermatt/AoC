package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	lines := strings.Split(os.Args[1], "\n")
	n_lines := len(lines)
	var diffs = make([]int, n_lines)
	for i := 0; i < n_lines; i++ {
		line := strings.Fields(lines[i])
		max, err := strconv.Atoi(line[0])
		if err != nil {
			fmt.Println(err)
		}
		min, err := strconv.Atoi(line[0])
		if err != nil {
			fmt.Println(err)
		}
		for j := 1; j < len(line); j++ {
			value, err := strconv.Atoi(line[j])
			if err != nil {
				fmt.Println(err)
			}
			if min > value {
				min = value
			}
			if max < value {
				max = value
			}
		}
		diffs[i] = max - min
	}
	total := 0
	for i := 0; i < len(diffs); i++ {
		total += diffs[i]
	}
	fmt.Println(total)
}
