#include <stdio.h>
int byteXor(int, int, int);
int logicalAnd(int, int);
int rotateLeft(int, int);
int mul2OK(int);
int mult3div2(int);
int main() {
    // printf("%d\n", !(!(0x0010 & 0x0001)));
    // printf("%d", byteXor(0x12345678, 0x87344321, 2));
    // printf("%d\n", logicalAnd(0x0010000, 0x0010000));
    // printf("%x\n", rotateLeft(0x87654321, 4));
    // printf("%x\n", 0x40000000 * 2);
    // printf("%x\n", mul2OK(0x30000000));
    printf("%d\n", mult3div2(-9));
    // printf("%d\n", (-1 & (0xC0000000)) | (-1 & 0x7FFFFFFF) >> 1);
    return 0;
}

int byteXor(int x, int y, int n) {
  // return 2;
  return !(((0x000000FF << (n << 3)) & x) ^ ((0x000000FF << (n << 3)) & y));
}
int logicalAnd(int x, int y) {
  // return 2;
  printf("%d %d\n",!x, !y);
  return (!!x & !!y);
}

int rotateLeft(int x, int n) {
  // return 2;
  int temp = (((~(0xFFFFFFFF << n)) << (32 - n)) & x ) >> (32 - n);
  return (x << n) | temp;
}

int mul2OK(int x) {
  // return 2;
  return !!(x << 1 & 0x80000000);
}

int mult3div2(int x) {
    // printf("%d %d\n", !!(x & 0x80000000), !!(x & 0x00000001));
    // printf("%d\n", (x + x + x) >> 1);
    int temp1 = (x + x + x) >> 1;
    int temp2 = !!(!!(x & 0x80000000) & !!(x & 0x000000011));
    return temp1 + temp2;
}