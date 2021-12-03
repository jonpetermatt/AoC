/*
 * =====================================================================================
 *
 *       Filename:  gates.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/03/2019 16:37:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Matthews
 *	    Email:  jonathanpetermatthews@protonmail.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct gate {
	size_t value;
	char name[256];
	size_t gates_connected_forward;
	size_t gates_connected_backward;
	size_t bitwise_op; //0 = NOTHING 1 = NOT; 2 = AND; 3 = OR; 4 = LSHIFT; 5 = RSHIFT
	size_t shift_value;
	size_t * forward_connection;
	size_t * backward_connection;
} gate;

struct gate * gates = NULL;
size_t current_gates = 0;
size_t total_ave_gates = 0;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  three_inputs
 *  Description:  
 * =====================================================================================
 */
void three_inputs (char * one, char * three)
{
	bool found = false;
	size_t value;
	sscanf(one, "%zu", &value);
	if (current_gates == 0) {
		gates = calloc(sizeof(gate), 1);
		total_ave_gates++;
	}
	for (size_t i = 0; i < current_gates; i++) {
		size_t changing_gate_length = strlen(three);
		size_t watched_gate_length = strlen((gates + i)->name);
		if (changing_gate_length != watched_gate_length) {
			continue;
		}
		if (strcmp(three, (gates + i)->name) == 0) {
			(gates + i)->value = value;
			i = current_gates;
			found = true;
		}
	}
	if (!found) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		(gates + current_gates)->value = value;
		strcpy((gates + current_gates)->name, three);
		(gates + current_gates)->bitwise_op = 0;
		(gates + current_gates)->shift_value = 0;
		(gates + current_gates)->backward_connection = NULL;
		(gates + current_gates)->forward_connection = NULL;
		(gates + current_gates)->gates_connected_forward = 0;
		(gates + current_gates)->gates_connected_backward = 0;
		current_gates++;
	}
}		/* -----  end of function three_inputs  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  four_inputs
 *  Description:  
 * =====================================================================================
 */
void four_inputs (char * two, char * four)
{
	bool found_two = false;
	bool found_four = false;
	if (current_gates == 0) {
		gates = calloc(sizeof(gate), 2);
		total_ave_gates = 2;
	}
	size_t two_length = strlen(two);
	size_t four_length = strlen(four);
	size_t two_gate;
	size_t four_gate;
	for (size_t i = 0; i < current_gates; i++) {
		size_t watched_gate_length = strlen((gates + i)->name);
		if (watched_gate_length == two_length) {
			if (strncmp((gates + i)->name, two, two_length) == 0) {
				two_gate = i;
				found_two = true;
			}
		}
		if (watched_gate_length == four_length) {
			if (strncmp((gates + i)->name, four, four_length) == 0) {
				four_gate = i;
				found_four = true;
			}
		}
	}
	if (!found_two) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		strcpy((gates + current_gates)->name, two);
		(gates + current_gates)->value = 0;
		(gates + current_gates)->forward_connection = NULL;
		(gates + current_gates)->gates_connected_forward = 1;
		(gates + current_gates)->backward_connection = NULL;
		(gates + current_gates)->gates_connected_backward = 0;
		(gates + current_gates)->bitwise_op = 0;
		two_gate = current_gates;
		(gates + current_gates)->forward_connection = malloc(sizeof(size_t));
		found_two = true;
		two_gate = current_gates;
		current_gates++;
	}
	if (!found_four) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		strcpy((gates + current_gates)->name, four);
		(gates + current_gates)->forward_connection = NULL;
		(gates + current_gates)->gates_connected_forward = 0;
		(gates + current_gates)->backward_connection = malloc(sizeof(size_t));
		(gates + current_gates)->gates_connected_backward = 1;
		(gates + current_gates)->bitwise_op = 1;
		*(gates + current_gates)->backward_connection = two_gate;
		current_gates++;
	}
	*(gates + two_gate)->forward_connection = four_gate;
}		/* -----  end of function four_inputs  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bitwise_input
 *  Description:  
 * =====================================================================================
 */
void bitwise_input (char * one, size_t op, char * three, char * five)
{
	if (current_gates == 0) {
		gates = calloc(sizeof(gate), 1);
		total_ave_gates++;
	}
	size_t one_length = strlen(one);
	size_t three_length = strlen(three);
	size_t five_length = strlen(five);
	size_t one_gate = 0;
	size_t three_gate = 0;
	if (op > 3) {
		three_gate = atoll(three);
	}
	size_t five_gate = 0;
	bool found_one = false;
	bool found_three = false;
	bool found_five = false;
	for (size_t i = 0; i < current_gates; i++) {
		size_t watched_gate_length = strlen((gates + i)->name);
		if (watched_gate_length == one_length) {
			if (strncmp((gates + i)->name, one, one_length) == 0) {
				one_gate = i;
				found_one = true;
			}
		}
		if (op < 4) {
			if (watched_gate_length == three_length) {
				if (strncmp((gates + i)->name, three, three_length) == 0) {
					three_gate = i;
					found_three = true;
				}
			}
		}
		if (watched_gate_length == five_length) {
			if (strncmp((gates + i)->name, five, five_length) == 0) {
				five_gate = i;
				found_five = true;
			}	
		}
	}
	if (!found_one) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		strcpy((gates + current_gates)->name, one);
		(gates + current_gates)->forward_connection = (size_t *) malloc(sizeof(size_t));
		(gates + current_gates)->gates_connected_forward = 1;
		(gates + current_gates)->backward_connection = NULL;
		(gates + current_gates)->gates_connected_backward = 0;
		(gates + current_gates)->bitwise_op = 0;
		one_gate = current_gates;
		current_gates++;
	}
	if (!found_three) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		strcpy((gates + current_gates)->name, three);
		(gates + current_gates)->forward_connection = (size_t *) malloc(sizeof(size_t));
		(gates + current_gates)->gates_connected_forward = 1;
		(gates + current_gates)->backward_connection = NULL;
		(gates + current_gates)->gates_connected_backward = 0;
		(gates + current_gates)->bitwise_op = 0;
		three_gate = current_gates;
		current_gates++;
	}
	if (!found_five) {
		if ((current_gates + 1) >= total_ave_gates) {
			total_ave_gates = total_ave_gates * 2;
			gate * new_gates = (gate *) calloc(sizeof(gate), total_ave_gates);
			memcpy(new_gates, gates, sizeof(gate) * current_gates);
			free(gates);
			gates = new_gates;
		}
		strcpy((gates + current_gates)->name, three);
		(gates + current_gates)->forward_connection = NULL;
		(gates + current_gates)->gates_connected_forward = 0;
		(gates + current_gates)->backward_connection = (size_t *) malloc(sizeof(size_t) * 2);
		*((gates + current_gates)->backward_connection) = one_gate;
		*((gates + current_gates)->backward_connection + 1) = three_gate;
		(gates + current_gates)->gates_connected_backward = 2;
		(gates + current_gates)->bitwise_op = op;
		current_gates++;
	}

	(gates + one_gate)->gates_connected_forward++;
	size_t * forward_gates = malloc((sizeof(size_t)) * ((gates + one_gate)->gates_connected_forward));
	memcpy(forward_gates, (gates + one_gate)->forward_connection, sizeof(size_t) * ((gates + one_gate)->gates_connected_forward - 1));
	free((gates + one_gate)->forward_connection);
	(gates + one_gate)->forward_connection = forward_gates;
	forward_gates = NULL;
	*((gates + one_gate)->forward_connection + ((gates + one_gate)->gates_connected_forward - 1)) = five_gate;

	(gates + three_gate)->gates_connected_forward++;
	forward_gates = (size_t *) malloc(sizeof(size_t) * (gates + three_gate)->gates_connected_forward);
	memcpy(forward_gates, (gates + three_gate)->forward_connection, sizeof(size_t) * ((gates + three_gate)->gates_connected_forward - 1));
	free((gates + three_gate)->forward_connection);
	(gates + three_gate)->forward_connection = forward_gates;
	forward_gates = NULL;
	*((gates + three_gate)->forward_connection + ((gates + three_gate)->gates_connected_forward - 1)) = five_gate;


}		/* -----  end of function bitwise_input  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  five_inputs
 *  Description:  
 * =====================================================================================
 */
void five_inputs (char * one, char * two, char * three, char * five)
{
	if (strlen(two) == 2) {
		bitwise_input(one, 0, three, five);
	}
	else if (strlen(two) == 3) {
		bitwise_input(one, 2, three, five);
	}
	else {
		if (two[0] == 'L') {
			bitwise_input(one, 4, three, five);
		}
		else {
			bitwise_input(one, 5, three, five);
		}
	}
}		/* -----  end of function five_inputs  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  print_data
 *  Description:  
 * =====================================================================================
 */
void print_data ()
{
	char name[256];
	size_t value;
	size_t * backward_connection = NULL;
	size_t * forward_connection = NULL;
	size_t op;
	size_t gates_connected_forward;
	size_t gates_connected_backward;
	for (size_t i = 0; i < current_gates; i++) {
		gate * watched_gate = (gates + i);
		strcpy(name, watched_gate->name);
		value = watched_gate->value;
		backward_connection = watched_gate->backward_connection;
		forward_connection = watched_gate->forward_connection;
		op = watched_gate->bitwise_op;
		gates_connected_forward = watched_gate->gates_connected_forward;
		gates_connected_backward = watched_gate->gates_connected_backward;
		if (backward_connection == NULL && forward_connection == NULL) {
			printf("name: %s\nvalue: %zu\nforward_connection: NULL\nbackward_connection: NULL\nop: %zu\ngates_connected_forward: %zu\ngates_connected_backward: %zu\n", name, value, op, gates_connected_forward, gates_connected_backward);
		}
		else if (backward_connection == NULL && forward_connection != NULL) {
			printf("name: %s\nvalue: %zu\n forward_connections: ", name, value);
			for (size_t j = 0; j < gates_connected_forward; j++) {
				printf("%s\n", (gates + *(forward_connection + j))->name);
			}
		}
		else if (backward_connection != NULL && forward_connection == NULL) {
			printf("name: %s\nvalue: %zu\n forward_connections: ", name, value);
			for (size_t j = 0; j < gates_connected_backward; j++) {
				printf("%s\n", (gates + *(backward_connection + j))->name);
			}
		}
		else {

		}
	}
}		/* -----  end of function print_data  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
	if (argc < 2) {
		return 1;
	}
	char * first;
	char * second;
	char * third;
	char * fourth;
	char * fifth;
	size_t length = strlen(argv[1]) + 1;
	char input[length];
	strncpy(input, argv[1], length);
	size_t i = 0;
	size_t j = 0;
	char line[256];
	while (i + 1 < length) {
		while (input[j] != '\n') {
			j++;
		}
		strncpy(line, (input + i), j - i);
		j++;
		line[j] = '\0';
		first = strtok(line, " ");
		printf("first: %s\n", first);
		second = strtok(NULL, " ");
		printf("second: %s\n", second);
		third = strtok(NULL, " ");
		printf("third: %s\n", third);
		fourth = strtok(NULL, " ");
		if (fourth != NULL) {
			printf("fourth: %s\n", fourth);
			fifth = strtok(NULL, " ");
		}
		else {
			three_inputs(first, third);
			first = NULL;
			second = NULL;
			third = NULL;
			i = j;
			printf("i: %zu\n", i);
			continue;
		}
		if (fifth == NULL) {
			four_inputs(second, fourth);
			third = NULL;
		}
		else {
			five_inputs(first, second, third, fifth);
			fourth = NULL;
		}
		first = NULL;
		second = NULL;
		third = NULL;
		fourth = NULL;
		fifth = NULL;
		i = j;
		printf("i: %zu\n", i);
	}
	print_data();
	free(gates);
}				/* ----------  end of function main  ---------- */
