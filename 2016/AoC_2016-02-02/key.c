#include 	<string.h>
#include 	<stdio.h>
#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  First get the number of lines. Split lines from argv[1]. Go through
 *  		  the lines, one character at a time. 
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
	if (argc != 2) {
		return 0;
	}
	size_t counter = 0;
	size_t total_lines  = 0;
	char * input = argv[1];
	while (*(input + counter) != '\0') {
		if (*(input + counter) == '\n') {
			total_lines++;
		}
		counter++;
	}
	char ** lines = calloc(total_lines, sizeof(char*));
	*(lines) = strtok(input, "\n");
	for (size_t i = 1; i < total_lines; i++) {
		*(lines + i) = strtok(NULL, "\n");
	}
	char * passcode = calloc(total_lines, sizeof(char));
	size_t pos = 5;
	for (size_t i = 0; i < total_lines; i++) {
		size_t command_length = strlen(*(lines + i));
		for (size_t j = 0; j < command_length; j++) {
			switch(pos) {
				case 1:
					if (*(*(lines + i) + j) == 'D') {
						pos = 3;
					}
					break;
				case 2:
					if (*(*(lines + i) + j) == 'R') {
						pos = 3;
						break;
					}
					if (*(*(lines + i) + j) == 'D') {
						pos = 6;
						break;
					}
					break;
				case 3:
					if (*(*(lines + i) + j) == 'U') {
						pos = 1;
					}
					else if (*(*(lines + i) + j) == 'R') {
						pos = 4;
					}
					else if (*(*(lines + i) + j) == 'D') {
						pos = 7;
					}
					else {
						pos = 2;
					}
					break;
				case 4:
					if (*(*(lines + i) + j) == 'L') {
						pos = 3;
						break;
					}
					if (*(*(lines + i) + j) == 'D') {
						pos = 8;
						break;
					}
					break;
				case 5:
					if (*(*(lines + i) + j) == 'R') {
						pos = 6;
						break;
					}
					break;
				case 6:
					if (*(*(lines + i) + j) == 'U') {
						pos = 2;
					}
					else if (*(*(lines + i) + j) == 'R') {
						pos = 7;
					}
					else if (*(*(lines + i) + j) == 'D') {
						pos = 10;
					}
					else {
						pos = 5;
					}
					break;
				case 7:
					if (*(*(lines + i) + j) == 'U') {
						pos = 3;
					}
					else if (*(*(lines + i) + j) == 'R') {
						pos = 8;
					}
					else if (*(*(lines + i) + j) == 'D') {
						pos = 11;
					}
					else {
						pos = 6;
					}
					break;
				case 8:
					if (*(*(lines + i) + j) == 'U') {
						pos = 4;
					}
					else if (*(*(lines + i) + j) == 'R') {
						pos = 9;
					}
					else if (*(*(lines + i) + j) == 'D') {
						pos = 12;
					}
					else {
						pos = 7;
					}
					break;
				case 9:
					if (*(*(lines + i) + j) == 'L') {
						pos = 8;
						break;
					}
					break;
				case 10:
					if (*(*(lines + i) + j) == 'U') {
						pos = 6;
						break;
					}
					if (*(*(lines + i) + j) == 'R') {
						pos = 11;
						break;
					}
					break;
				case 11:
					if (*(*(lines + i) + j) == 'U') {
						pos = 7;
					}
					else if (*(*(lines + i) + j) == 'R') {
						pos = 12;
					}
					else if (*(*(lines + i) + j) == 'D') {
						pos = 13;
					}
					else {
						pos = 10;
					}
					break;
				case 12:
					if (*(*(lines + i) + j) == 'U') {
						pos = 8;
						break;
					}
					if (*(*(lines + i) + j) == 'L') {
						pos = 11;
						break;
					}
					break;
				default:
					if (*(*(lines + i) + j) == 'U') {
						pos = 11;
					}
					break;
			}
		}
		switch(pos) {
			case 1:
				*(passcode + i) = '1';
				break;
			case 2:
				*(passcode + i) = '2';
				break;
			case 3:
				*(passcode + i) = '3';
				break;
			case 4:
				*(passcode + i) = '4';
				break;
			case 5:
				*(passcode + i) = '5';
				break;
			case 6:
				*(passcode + i) = '6';
				break;
			case 7:
				*(passcode + i) = '7';
				break;
			case 8:
				*(passcode + i) = '8';
				break;
			case 9:
				*(passcode + i) = '9';
				break;
			case 10:
				*(passcode + i) = 'A';
				break;
			case 11:
				*(passcode + i) = 'B';
				break;
			case 12:
				*(passcode + i) = 'C';
				break;
			default:
				*(passcode + i) = 'D';
				break;
		}
	}
	for (size_t i = 0; i < total_lines; i++) {
		printf("%c", *(passcode + i));
	}
	printf("\n");
	free(passcode);
	free(lines);
}				/* ----------  end of function main  ---------- */
