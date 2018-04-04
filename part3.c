#include <stdio.h>

unsigned char add_bytes(unsigned char a, unsigned char b) {
	int sum;
	sum = a + b;
	printf("0x%02x", (unsigned char)sum);
	if (sum > 255) {
		printf(" (carry occured)");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	add_bytes(0x20, 0x35);
	add_bytes(0x80, 0x7F);
	add_bytes(0x80, 0xFF);
	add_bytes(0xFF, 0x01);	

	return 0;
}
