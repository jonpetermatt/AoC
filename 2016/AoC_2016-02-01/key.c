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
	size_t * passcode = calloc(total_lines, sizeof(size_t));
	size_t pos = 5;
	for (size_t i = 0; i < total_lines; i++) {
		size_t command_length = strlen(*(lines + i));
		for (size_t j = 0; j < command_length; j++){
			if (*(*(lines + i) + j) == 'L') {
				switch(pos) {
					case 1:
						break;
					case 4:
						break;
					case 7:
						break;
					default:
						pos--;
				}
			}
			else if (*(*(lines + i) + j) == 'U') {
				if (pos > 3) {
					pos = pos - 3;
				}
			}
			else if (*(*(lines + i) + j) == 'R') {
				switch(pos) {
					case 3:
						break;
					case 6:
						break;
					case 9:
						break;
					default:
						pos++;
				}
			}
			else {
				if (pos < 7) {
					pos = pos + 3;
				}
			}
		}
		*(passcode + i) = pos;
	}
	for (size_t i = 0; i < total_lines; i++) {
		printf("%zu", *(passcode + i));
	}
	printf("\n");
	free(passcode);
	free(lines);
}				/* ----------  end of function main  ---------- */
