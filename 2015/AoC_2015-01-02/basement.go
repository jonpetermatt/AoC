package main

import "fmt"
import "os"

func main() {
	var i = 0
	var floor = 0
	var input = os.Args[1]
	for i < len(input) {
		if string(input[i]) == "(" {
			floor++
		} else {
			floor--
		}
		i++
		if floor == -1 {
			fmt.Println(i)
			return
		}
	}
}
