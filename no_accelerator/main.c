#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "md5.h"
#define TRUE 1
#define FALSE 0
#define UINT8_ARRAY_SIZE 64
#define HASH_SIZE_8 16
/*
hypothetical blockchain algorithm structure
Total block input needs to be 512 bits
128 bits of previous hash
320 bits of data
64 bits of nonce
this means that the nonce consists of 8 bytes -> which means the last 8 array elements of the input array can be modified
*/

void print_bytes(void *p, size_t length){
	uint8_t *pp = (uint8_t *)p;
	for(unsigned int i = 0; i < length; ++i){
		if(i && !(i % 16)){
			printf("\n");
		}
		printf("%02X ", pp[i]);
	}
	printf("\n");
}

void print_hash(uint8_t *p){
	printf("Hash:\t");
	for(unsigned int i = 0; i < 16; ++i){
		printf("%02x", p[i]);
	}
	printf("\n");
}


int check_hash(uint8_t *max_value, char *hash){
	for(unsigned int i = 0; i < 16; ++i){
		if(max_value[i] > hash[i]){
			return FALSE;
		}
	}
	return TRUE;
}
void incremeant_nonce(uint8_t *input){
	int current_location = 63;
	if (input[current_location] == 0xFF){
		while(input[current_location] == 0xFF){
			input[current_location] = 0x00;
			current_location--;
		}
		input[current_location]++;
	}
	else{
		input[current_location]++;
	}
}



int main(void){
	// declairing variables
	//uint8_t* max_value = malloc(sizeof(uint8_t) * HASH_SIZE_8);
	uint8_t max_value_increment = 0x00;\
	/*
	uint8_t previous_hash[HASH_SIZE_8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	uint8_t data[40] = {0x00}; 
	uint8_t nonce[8] = {0x00};
	*/

	uint8_t *previous_hash, *data, *nonce;

	//instantiate 
	uint8_t max_value[HASH_SIZE_8] = {0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	
	uint8_t* input_array = malloc(sizeof(uint8_t) * UINT8_ARRAY_SIZE);

	for (int i = 0; i < UINT8_ARRAY_SIZE; i++){
		input_array[i] = 0x00;
	}


	uint8_t *result = md5_exact_length_int(input_array);
	while(check_hash(max_value,result) == FALSE){ //should be while
		incremeant_nonce(input_array);
		result = md5_exact_length_int(input_array);
	}
	print_hash(result);
	printf("Nonce:\t");
	for (int i = 0; i < 8; i++){
		printf("%02x", input_array[i+56]);
	}
	printf("\n");
	free(result);
}

