package main

import "fmt"
import "os"

func main() {
	var input = os.Args[1]
	var i = 0
	var counter = 0
	for string(input[counter]) != "\n" {
		counter++
	}
	string_a := make([]string, counter)
	string_b := make([]string, counter)
	compared := make([]string, counter)
	var postition = 0
	var lines = 0
	for i < len(input) {
		if string(input[i]) == "\n" {
			lines++
		}
		i++
	}
	var diff = counter
	for postition < lines {
		var j = 0
		var k = 0
		for string(input[postition*(counter+1)+j]) != "\n" {
			compared[k] = string(input[postition*(counter+1)+j])
			j++
			k++
		}
		i = postition*(counter+1) + counter + 1
		for i < len(input) {
			var k = 0
			var letter_diff = 0
			for string(input[i]) != "\n" {
				if string(input[i]) != string(compared[k]) {
					letter_diff++
				}
				i++
				k++
			}
			if letter_diff < diff {
				diff = letter_diff
				copy(string_a, compared)
				i = i - counter
				var l = 0
				for string(input[i]) != "\n" {
					string_b[l] = string(input[i])
					i++
					l++
				}
			}
			i++
		}
		postition++
	}
	string_final := make([]string, counter-diff)
	var j = 0
	var k = 0
	for j < counter {
		if string_a[j] == string_b[j] {
			string_final[k] = string_a[j]
			k++
		}
		j++
	}
	fmt.Println(string_final)
}
