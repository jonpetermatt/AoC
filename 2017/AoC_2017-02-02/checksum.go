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
		high := 0
		low := 0
		for j := 0; j < len(line); j++ {
			divider, err := strconv.Atoi(line[j])
			if err != nil {
				fmt.Println(err)
			}
			for k := 0; k < len(line); k++ {
				if k == j {
					continue
				}
				watched, err := strconv.Atoi(line[k])
				if err != nil {
					fmt.Println(err)
				}
				if watched%divider == 0 {
					high = watched
					low = divider
					j = len(line)
					break
				}
			}
		}
		diffs[i] = high / low
	}
	total := 0
	for i := 0; i < len(diffs); i++ {
		total += diffs[i]
	}
	fmt.Println(total)
}
