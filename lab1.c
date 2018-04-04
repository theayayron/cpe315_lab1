/* lab1.c */

#include <stdio.h>



void byteOrdering(void) {
  int i;
  unsigned char bytestring[] = {
    0x41, 0x33, 0x54, 0x80, 0xFF, 0x99, 0x01, 0x78,
    0x55, 0x20, 0xFE, 0xEE, 0x00, 0x00, 0x00, 0x00 };

  short int *a;
  int *b;
  long int *c;

  a = (short int *)bytestring;
  b = (int *)bytestring;
  c = (long int *)bytestring;

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
  for(i = 0; i < (4 * sizeof(unisigned char)); i += sizeof(unsigned char)) {
    printf("%04x ", *(a + i));
  }
  printf("\n");
}


int main(void) {

  byteOrdering();
  return 0;
}
