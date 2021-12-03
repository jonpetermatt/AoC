package main

import "fmt"
import "os"
import "strings"
import "strconv"

func main() {
	var total = 0
	var input = os.Args[1]
	var i = 0
	for i < len(input) {
		var sign = string(input[i])
		i++
		var number strings.Builder
		for string(input[i]) != "\n" {
			fmt.Fprintf(&number, string(input[i]))
			i++
		}
		if value, err := strconv.Atoi(number.String()); err == nil {
			if sign == "+" {
				total = total + value
			} else {
				total = total - value
			}
		}
		i++
	}
	fmt.Println(total)
}
