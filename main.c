#include <stdio.h>

unsigned char add_bytes(unsigned char a, unsigned char b);
void add_bytes_overflow(char a, char b);
unsigned int arbitrary_byte_add (unsigned char *result, unsigned char *a1,
                                 unsigned char *a2, int size,
                                 unsigned int carry_in);
void print_array(unsigned char *a, int size);

int main() {
    unsigned char a1[] = {0x44, 0x00, 0x00, 0x00, 0x01};
    unsigned char a2[] = {0x30, 0xFF, 0xFF, 0x00, 0x00};
    unsigned char a[5];

    unsigned char b1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    unsigned char b2[] = {0x00, 0x00, 0x00, 0x00, 0x01};
    unsigned char b[5];

    /* part 1 */
    printf("The size of a byte is: %d\n", sizeof(unsigned char));
    printf("The size of a short int is: %d\n", sizeof(short int));
    printf("The size of an int is: %d\n", sizeof(int));
    printf("The size of a long int is: %d\n", sizeof(long int));

    /* part 3 */
    add_bytes(0x20, 0x35);
    add_bytes(0x80, 0x7F);
    add_bytes(0x80, 0xFF);
    add_bytes(0xFF, 0x01);

    /* part 4 */
    add_bytes_overflow(0x20, 0x35);
    add_bytes_overflow(0x80, 0x7F);
    add_bytes_overflow(0x80, 0xFF);
    add_bytes_overflow(0xFF, 0x01);

    /* part 6 */
    printf("carry = %d\n", arbitrary_byte_add(a, a1, a2, 5, 0));
    printf("carry = %d\n", arbitrary_byte_add(b, b1, b2, 5, 0));

    return 0;
}

unsigned char add_bytes(unsigned char a, unsigned char b) {
    int sum;
    sum = a + b;
    printf("0x%02x", (unsigned char)sum);
    if (sum > 255) {
        printf(" (carry occured)");
    }
    printf("\n");
}

void add_bytes_overflow(char a, char b) {
    char sum;
    sum = a + b;

    printf("a = %d, b = %d, sum = %d\n", a, b, sum);
    printf("0x%02x", sum);
    if ((a < 0 && b < 0 && sum > 0) || (a > 0 && b > 0 && sum < 0)) {
        printf(" (overflow occured)");
    }
    printf("\n");
}

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
    print_array(result, size);
    return (unsigned int)carry;
}

void print_array(unsigned char *a, int size) {
    while (--size >= 0) {
        printf("0x%02x ", a[size]);
    }
    printf("\n");
}