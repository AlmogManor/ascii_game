#include <stdio.h>

#include "colors.h"
#include "assets.h"

void print_key(const char* key[], const char* color) {
	printf(CLEAR_SCREEN);
	printf(color);
	while (*key != 0) {
		printf("%s\n", *key);
		key++;
	}
	printf(RESET_COLOR);
}


int main(int argc, char** argv) {
	print_key(KEY_UP, GREEN);
	return 0;
}
