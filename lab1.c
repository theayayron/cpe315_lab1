/* lab1.c */

#include <stdio.h>


/* void -> void 
 * creates a byte array and accesses the array as short
 * integers, integers, and long integers. */
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
  
}


int main(void) {

  byteOrdering();
  return 0;
}
