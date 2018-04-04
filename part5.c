#include <stdio.h>

void add_bytes(char a, char b) {
	char sum;
	sum = a + b;
	
	printf("a = %d, b = %d, sum = %d\n", a, b, sum);
	printf("0x%02x", sum);
	if ((a < 0 && b < 0 && sum > 0) || (a > 0 && b > 0 && sum < 0)) {
		printf(" (overflow occured)");
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
