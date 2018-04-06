#include <stdio.h>

void add_bytes(unsigned char a, unsigned char b);
void add_bytes_carry(unsigned char a, unsigned char b);
void add_bytes_overflow(char a, char b);
unsigned int arbitrary_byte_add(unsigned char *result, unsigned char *a1,
                                unsigned char *a2, int size,
                                unsigned int carry_in);
void print_array(unsigned char *a, int size);
void byteOrdering(void);

int main(int argc, char *argv[]) {
    unsigned char a1[] = {0x44, 0x00, 0x00, 0x00, 0x01};
    unsigned char a2[] = {0x30, 0xFF, 0xFF, 0x00, 0x00};
    unsigned char a[5];

    unsigned char b1[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    unsigned char b2[] = {0x00, 0x00, 0x00, 0x00, 0x01};
    unsigned char b[5];

    /* part 1 */
    printf("Part 1: Data Types and their Sizes\n");
    printf("========================\n");
    printf("Byte Size: %lu\n", sizeof(unsigned char));
    printf("Short Int Size: %lu\n", sizeof(short int));
    printf("Int Size: %lu\n", sizeof(int));
    printf("Long Int Size: %lu\n", sizeof(long int));
    printf("========================\n\n");

    /* part 2 */
    byteOrdering();

    /* part 3 */
    printf("Part 3: Unsigned Addition of Small Fields\n");
    printf("========================\n");
    add_bytes(0x20, 0x35);
    add_bytes(0x80, 0x7F);
    add_bytes(0x80, 0xFF);
    add_bytes(0xFF, 0x01);
    printf("========================\n\n");

    /* part 4 */
    printf("Part 4: Detecting a Carry condition\n");
    printf("========================\n");
    add_bytes_carry(0x20, 0x35);
    add_bytes_carry(0x80, 0x7F);
    add_bytes_carry(0x80, 0xFF);
    add_bytes_carry(0xFF, 0x01);
    printf("========================\n\n");

    /* part 5 */
    printf("Part 5: Signed Addition and Overflow \n");
    printf("========================\n");
    add_bytes_overflow(0x20, 0x35);
    add_bytes_overflow(0x80, 0x7F);
    add_bytes_overflow(0x80, 0xFF);
    add_bytes_overflow(0xFF, 0x01);
    printf("========================\n\n");

    /* part 6 */
    printf("Part 6: Performing Extended Field Arithmetic\n");
    printf("========================\n");
    printf("6a)\n");
    printf("\nCarry Out = %d\n\n", arbitrary_byte_add(a, a1, a2, 5, 0));
    printf("6b)\n");
    printf("\nCarry Out = %d\n", arbitrary_byte_add(b, b1, b2, 5, 0));
    printf("========================");
    printf("\n");
    return 0;
}

/**
 * Creates a byte array and accesses the array as short
 * integers, integers, and long integers.
 */
void byteOrdering(void) {
  int i;
  unsigned char bytestring[] = {
    0x41, 0x33, 0x54, 0x80, 0xFF, 0x99, 0x01, 0x78,
    0x55, 0x20, 0xFE, 0xEE, 0x00, 0x00, 0x00, 0x00 };

  unsigned short int *a;
  unsigned int *b;
  unsigned long int *c;

  a = (unsigned short int *)bytestring;
  b = (unsigned int *)bytestring;
  c = (unsigned long int *)bytestring;

  printf("Part 2: Byte Ordering\n");
  printf("========================\n");

  /* 2a */
  printf("\n");
  printf("Byte Values of entire array (show as hexadecimal values, e.g., C7)):\n");
  printf("\n");
  for(i = 0; i < sizeof(bytestring); i++) {
    printf("%02x ", bytestring[i]);
  }
  printf("\n");

  /* 2b */
  printf("\n");
  printf("Short Int versions of the first four values of an array in hexadecimal:\n");
  printf("\n");
  for(i = 0; i < 4; i++) {
    printf("%4x ", *(a+i));
  }
  printf("\n");

  /* 2c */
  printf("\n");
  printf("Int versions of the first two values of an array in hexadecimal:\n");
  printf("\n");
  for(i = 0; i < 2; i++) {
    printf("%08x ", *(b+i));
  }
  printf("\n");

  /* 2d */
  printf("\n");
  printf("Long Int version of the first value of an array in hex:\n");
  printf("\n");
  printf("%lx ", *c);
  printf("\n");

  /* 2e */
  printf("\n");
  printf("2e: ");
  for(i = sizeof(bytestring); i > 0; i--) {
    printf("%02x ", bytestring[i]);
  }
  printf("\n");

  /* 2f */
  printf("\n");
  printf("2f: ");
  for(i = 7; i > 3; i--) {
    printf("%04x ", *(a + i));
  }
  printf("\n");

  /* 2g */
  printf("\n");
  printf("2g: ");
  for(i = 1; i > -1; i--) {
    printf("%08x ", *(b + i));
  }
  printf("\n");

  /* 2h */
  printf("\n");
  printf("2h: %016lx", *c);
  printf("\n");
  printf("========================\n");
}

/**
 * Adds two bytes together and prints the sum. The sum is one byte,
 * ignoring any overflow.
 * @param a the first byte to add
 * @param b the second byte to add
 */
void add_bytes(unsigned char a, unsigned char b) {
    unsigned char sum;
    sum = a + b;
    printf("0x%02x + 0x%02x = 0x%02x\n", a, b, sum);
}

/**
 * Adds two bytes together and determines if a carry condition occurred.
 * This means that the result was bigger than the maximum value of a byte (255).
 * @param a the first byte to add
 * @param b the second byte to add
 */
void add_bytes_carry(unsigned char a, unsigned char b) {
    int sum; /* store in an integer so sum can hold values greater than 255 */
    sum = a + b;
    printf("0x%02x + 0x%02x Carry: %d\n", a, b, sum > 255);
}

/**
 * Adds two bytes together and determines if an overflow condition occurred.
 * There are two cases where this can occur: when both operands are positive
 * and the result is negative, or when both operands are negative and the
 * result is positive.
 * @param a the first byte to add
 * @param b the second byte to add
 */
void add_bytes_overflow(char a, char b) {
    char sum;
    sum = a + b;

    printf("0x%02x + 0x%02x Overflow: ", (unsigned char)a , (unsigned char)b);
    printf("%d\n", (a < 0 && b < 0 && sum > 0) || (a > 0 && b > 0 && sum < 0));
}

/**
 * Adds two arrays of bytes and stores the result in the given array.
 * It also factors in a carry flag which will affect the rightmost
 * byte pair and propagate through to the leftmost byte pair before
 * being returned.
 *
 * It is assumed that result, a1, and a2 are not NULL pointers.
 *
 * @param result the array where the resulting sums will be stored
 * @param a1 the first array of bytes to add
 * @param a2 the second array of bytes to add
 * @param size the number of bytes in each array
 * @param carry_in the carry value to the rightmost byte pair
 * @return the carry from the leftmost byte pair
 */
unsigned int arbitrary_byte_add(unsigned char *result, unsigned char *a1,
                                unsigned char *a2, int size,
                                unsigned int carry_in) {
    int i, sum, carry;

    carry = carry_in;

    printf("\t");
    print_array(a1, size);
    printf("+\t");
    print_array(a2, size);
    printf("\n=\t");

    for (i = size - 1; i >= 0; i--) { /* start at the right */
        sum = a1[i] + a2[i] + carry;
        result[i] = (unsigned char) sum;
        carry = sum >> 8; /* shift away lower byte to get carry value */
    }
    print_array(result, size);
    return (unsigned int) carry;
}

/**
 * A helper function for arbitrary_byte_add() that prints an
 * array of size bytes.
 * @param a the byte array to print
 * @param size the number of bytes in a
 */
void print_array(unsigned char *a, int size) {
    int i = 0;
    while (i < size) {
        printf("0x%02x ", a[i]);
        i++;
    }
    printf("\n");
}
