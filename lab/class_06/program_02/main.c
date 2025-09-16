// WAP in C to reverse a number using stack.

#include <stdio.h>
#define MAX 20

int main() {
  int num, stack[MAX], top = -1, digit, temp, isNegative = 0;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num == 0) {
    printf("Reversed number: 0\n");
    return 0;
  }

  if (num < 0) {
    isNegative = 1;
    num = -num;
  }

  temp = num;
  while (temp > 0) {
    stack[++top] = temp % 10;
    temp /= 10;
  }

  printf("Reversed number: ");
  if (isNegative) printf("-");
  for (int i = 0; i <= top; i++) {
    printf("%d", stack[i]);
  }
  printf("\n");
  return 0;
}

/* OUTPUT
Enter a number: 1234
Reversed number: 4321
*/