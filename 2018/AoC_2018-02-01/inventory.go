package main

import "fmt"
import "os"

func main() {
	var two = 0
	var three = 0
	var input = os.Args[1]
	var i = 0
	for i < len(input) {
		var counter = 0
		for string(input[i]) != "\n" {
			counter++
			i++
		}
		i = i - counter
		list := make([]string, counter)
		var letter = 0
		for letter < counter {
			list[letter] = string(input[i])
			letter++
			i++
		}
		var j = 0
		skip := make([]int, counter)
		var two_count = 0
		var three_count = 0
		for j < counter-1 {
			for skip[j] == 1 && j < counter-1 {
				j++
			}
			var counted = 0
			var k = j + 1
			for k < counter {
				if string(list[j]) == string(list[k]) {
					counted++
					skip[k] = 1
				}
				k++
			}
			if counted == 2 && three_count == 0 {
				three++
				three_count++
			}
			if counted == 1 && two_count == 0 {
				two++
				two_count++
			}
			if two_count == 1 && three_count == 1 {
				j = counter
			}
			j++
		}
		i++
	}
	fmt.Println(two * three)
}
