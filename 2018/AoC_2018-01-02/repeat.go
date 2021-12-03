package main

import "fmt"
import "os"
import "strings"
import "strconv"

func check(list []int, total int, start int, end int) {

}

func main() {
	var repeated = 0
	var input = os.Args[1]
	var j = 4
	var check = 0
	var total = 0
	list := make([]bool, 4)
	for check == 0 {
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
			for true {
				if total > j/2 {
					j = j * 2
					newlist := make([]bool, j)
					var counter = 0
					for counter < j/2 {
						newlist[(j/4)+counter] = list[counter]
						counter++
					}
					list = newlist
				} else if total < (-j/2)+1 {
					j = j * 2
					newlist := make([]bool, j)
					var counter = 0
					for counter < j/2 {
						newlist[(j/4)+counter] = list[counter]
						counter++
					}
					list = newlist
				} else {
					break
				}
			}
			if list[(j/2)-1+total] == true {
				i = len(input)
				check = 1
				repeated = total
			} else {
				list[(j/2)-1+total] = true
			}
			i++
		}

	}
	fmt.Println(repeated)
}
