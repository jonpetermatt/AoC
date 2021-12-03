package main

import "fmt"
import "os"
import "strings"
import "strconv"

func lw(l int, w int) int {
	return (2 * l * w)
}

func wh(w int, h int) int {
	return (2 * w * h)
}

func hl(h int, l int) int {
	return (2 * h * l)
}

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
		var extra = lvalue * wvalue
		if extra > wvalue*hvalue {
			extra = wvalue * hvalue
		}
		if extra > hvalue*lvalue {
			extra = hvalue * lvalue
		}
		fmt.Println(lvalue)
		fmt.Println(wvalue)
		fmt.Println(hvalue)
		fmt.Println(lw(lvalue, wvalue), " ", wh(wvalue, hvalue), " ", hl(hvalue, lvalue), " ", extra)
		total = total + lw(lvalue, wvalue) + wh(wvalue, hvalue) + hl(hvalue, lvalue) + extra
		i++
		l.Reset()
		w.Reset()
		h.Reset()
	}
	fmt.Println(total)
}
