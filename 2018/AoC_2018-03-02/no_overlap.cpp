/*
 * =====================================================================================
 *
 *       Filename:  overlap.cpp
 *
 *    Description:  Advent of Code 2018. Day three. Task two
 *
 *        Version:  1.0
 *        Created:  11/12/2018 21:58:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Matthews
 *	    Email:  jonathanpetermatthews@protonmail.com
 *
 * =====================================================================================
 */
#include <string>
#include <cstdlib>
#include <iostream>

bool sheet[1000][1000];

struct elf {
	size_t xstart;
	size_t ystart;
	size_t xlength;
	size_t ylenght;
	size_t number;
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main(int argc, char *argv[]) {
	if (argc == 1) {
		return 0;
	}
	std::string input(argv[1]);
	size_t pos = 0;
	size_t lines = 0;
	while (std::string::npos != (pos = input.find("\n", pos))) {
		pos++;
		lines++;
	}
	elf *elves = new elf[lines];
	size_t i = 1;
	size_t line = 0;
	while (i < input.length()) {
		char number[5];
		size_t pos = 0;
		while (input[i] != ' ') {
			number[pos] = input[i];
			i++;
			pos++;
		}
		number[pos] = '\0';
		elves[line].number = std::atoi(number);
		char xsc[5];
		char ysc[5];
		pos = 0;
		i = i + 3;
		while (input[i] != ',') {
			xsc[pos] = input[i];
			i++;
			pos++;
		}
		xsc[pos] = '\0';
		pos = 0;
		i++;
		while (input[i] != ':') {
			ysc[pos] = input[i];
			i++;
			pos++;
		}
		i = i + 2;
		ysc[pos] = '\0';
		elves[line].xstart = std::atoi(xsc);
		elves[line].ystart = std::atoi(ysc);
		char xlc[5];
		char ylc[5];
		pos = 0;
		while (input[i] != 'x') {
			xlc[pos] = input[i];
			i++;
			pos++;
		}
		xlc[pos] = '\0';	
		i++;
		pos = 0;
		while (input[i] != '\n') {
			ylc[pos] = input[i];
			i++;
			pos++;
		}
		ylc[pos] = '\0';
		elves[line].xlength = std::atoi(xlc);
		elves[line].ylenght = std::atoi(ylc);
		i = i + 2;
		line++;
	}
	i = 0;
	size_t not_overlapped = 1;
	while (i < lines && not_overlapped != 0) {
		size_t overlap = 0;
		size_t j = 0;
		size_t ixstart = elves[i].xstart;
		size_t ixend = elves[i].xstart + elves[i].xlength;
		size_t iystart = elves[i].ystart;
		size_t iyend = elves[i].ystart + elves[i].ylenght;
		while (j < lines) {
			size_t jxstart = elves[j].xstart;
			size_t jxend = elves[j].xstart + elves[j].xlength;
			size_t jystart = elves[j].ystart;
			size_t jyend = elves[j].ystart + elves[j].ylenght;
			if (j != i) {
				if (ixstart >= jxstart && ixstart <= jxend) {
					if (iystart >= jystart && iystart <= jyend) {
						overlap++;
					}
					if (iystart <= jystart && jystart <= iyend) {
						overlap++;
					}
				}
				if (ixstart <= jxstart && jxstart <= ixend) {
					if (iystart >= jystart && iystart <= jyend) {
						overlap++;
					}
					if (iystart <= jystart && jystart <= iyend) {
						overlap++;
					}

				}
			}
			j++;
		}
		if (overlap == 0) {
			not_overlapped = 0;
		}
		i++;
	}
	std::cout << i << std::endl;
	delete[]elves;
	return 0;
}
	/* ----------  end of function main  ---------- */
