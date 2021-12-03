package main

import "fmt"
import "os"
import "strings"
import "strconv"

func main() {
	var total = 0
	var i = 0
	var l strings.Builder
	var w strings.Builder
	var h strings.Builder
	var input = os.Args[1]
	for i < len(os.Args[1]) {
		for string(input[i]) != "x" {
			fmt.Fprintf(&l, string(input[i]))
			i++
		}
		i++
		for string(input[i]) != "x" {
			fmt.Fprintf(&w, string(input[i]))
			i++
		}
		i++
		for string(input[i]) != "\n" {
			fmt.Fprintf(&h, string(input[i]))
			i++
		}
		var lvalue = 0
		var wvalue = 0
		var hvalue = 0
		if value, err := strconv.Atoi(l.String()); err == nil {
			lvalue = value
		}
		if value, err := strconv.Atoi(w.String()); err == nil {
			wvalue = value
		}
		if value, err := strconv.Atoi(h.String()); err == nil {
			hvalue = value
		}
		var extra = lvalue * wvalue * hvalue
		var short = lvalue
		var medium = wvalue
		var long = hvalue
		if long < medium {
			medium = hvalue
			long = wvalue
		}
		if medium < short {
			short = medium
			medium = lvalue
		}
		if long < medium {
			medium = long
		}
		total = total + (2 * short) + (2 * medium) + extra
		i++
		l.Reset()
		w.Reset()
		h.Reset()
	}
	fmt.Println(total)
}
