// WAP in C to reverse a number using stack.

#include <stdio.h>

#define MAX 20

int main() {
  int num, stack[MAX], top = -1, digit;
  printf("Enter a number: ");
  scanf("%d", &num);

  // Push digits onto stack
  while (num > 0) {
    stack[++top] = num % 10;
    num /= 10;
  }

  printf("Reversed number: ");
  // Pop digits to form reversed number
  while (top >= 0) {
    printf("%d", stack[top--]);
  }
  printf("\n");
  return 0;
}