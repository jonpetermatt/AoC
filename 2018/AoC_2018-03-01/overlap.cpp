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
	while (i < lines) {
		size_t j = i + 1;
		size_t ixstart = elves[i].xstart;
		size_t ixend = elves[i].xstart + elves[i].xlength;
		size_t iystart = elves[i].ystart;
		size_t iyend = elves[i].ystart + elves[i].ylenght;
		while (j < lines) {
			size_t jxstart = elves[j].xstart;
			size_t jxend = elves[j].xstart + elves[j].xlength;
			size_t jystart = elves[j].ystart;
			size_t jyend = elves[j].ystart + elves[j].ylenght;
			if (ixstart >= jxstart && ixstart <= jxend) {
				if (iystart >= jystart && iystart <= jyend) {
					if (ixend <= jxend) {
						if (iyend <= jyend) {
							for (size_t k = iystart; k < iyend; k++) {
								for (size_t l = ixstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = iystart; k < jyend; k++) {
								for (size_t l = ixstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
					else {
						if (iyend <= jyend) {
							for (size_t k = iystart; k < iyend; k++) {
								for (size_t l = ixstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = iystart; k < jyend; k++) {
								for (size_t l = ixstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
				}
				if (iystart <= jystart && jystart <= iyend) {
					if (ixend <= jxend) {
						if (iyend <= jyend) {
							for (size_t k = jystart; k < iyend; k++) {
								for (size_t l = ixstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = jystart; k < jyend; k++) {
								for (size_t l = ixstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
					else {
						if (iyend <= jyend) {
							for (size_t k = jystart; k < iyend; k++) {
								for (size_t l = ixstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = jystart; k < jyend; k++) {
								for (size_t l = ixstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
				}

			}
			if (ixstart <= jxstart && jxstart <= ixend) {
				if (iystart >= jystart && iystart <= jyend) {
					if (ixend <= jxend) {
						if (iyend <= jyend) {
							for (size_t k = iystart; k < iyend; k++) {
								for (size_t l = jxstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = iystart; k < jyend; k++) {
								for (size_t l = jxstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
					else {
						if (iyend <= jyend) {
							for (size_t k = iystart; k < iyend; k++) {
								for (size_t l = jxstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = iystart; k < jyend; k++) {
								for (size_t l = jxstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
				}
				if (iystart <= jystart && jystart <= iyend) {
					if (ixend <= jxend) {
						if (iyend <= jyend) {
							for (size_t k = jystart; k < iyend; k++) {
								for (size_t l = jxstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = jystart; k < jyend; k++) {
								for (size_t l = jxstart; l < ixend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
					else {
						if (iyend <= jyend) {
							for (size_t k = jystart; k < iyend; k++) {
								for (size_t l = jxstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
						else {
							for (size_t k = jystart; k < jyend; k++) {
								for (size_t l = jxstart; l < jxend; l++) {
									sheet[k][l] = true;
								}
							}
						}
					}
				}

			}
			j++;
		}
		i++;
	}
	size_t inches = 0;
	for (size_t k= 0; k < 1000; k++) {
		for (size_t l = 0; l < 1000; l++) {
			if (sheet[k][l] == true) {
				inches++;
			}
		}
	}
	delete[]elves;
	std::cout << inches << std::endl;
	return 0;
}				/* ----------  end of function main  ---------- */
