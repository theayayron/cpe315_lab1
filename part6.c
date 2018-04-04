#include <stdio.h>

unsigned int arbitrary_byte_add (unsigned char *result, unsigned char *a1, 
			      unsigned char *a2, int size,
			      unsigned int carry_in) {
	int i, sum, carry;

	carry = carry_in;

	for (i = 0; i < size; i++) {
		sum = a1[i] + a2[i] + carry;
		result[i] = (unsigned char) sum;
		
		carry = sum >> 8;
	}
}
 

int main(int argc, char *argv[]) {
	unsigned char a1[] = {0x44, 0x00, 0x00, 0x00, 0x01};
	unsigned char a2[] = {0x30, 0xFF, 0xFF, 0x00, 0x00};
	unsigned char a[5];

	unsigned char b1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	unsigned char b2[] = {0x00, 0x00, 0x00, 0x00, 0x01};
	unsigned char b[5];

	arbitrary_byte_add(a, a1, a2, 5, 0);
	arbitrary_byte_add(b, b1, b2, 5, 0);

	return 0;
}

void print_array(unsigned char *a, int size) {
	while (--size >= 0) {
		printf("0x%02x ", a[size]);
	}
}
