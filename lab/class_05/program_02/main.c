#include <stdio.h>
#include <stdlib.h>

int *stack, top = -1, size;

void push(int val) {
  if (top == size - 1) {
    printf("overflow\n");
    return;
  }
  stack[++top] = val;
}

void pop() {
  if (top == -1) {
    printf("underflow\n");
    return;
  }
  top--;
}

void peek() {
  if (top == -1) {
    printf("empty\n");
    return;
  }
  printf("%d\n", stack[top]);
}

void view() {
  if (top == -1) {
    printf("empty\n");
    return;
  }
  for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
  printf("\n");
}

int main() {
  int ch, val;
  printf("Enter stack size: ");
  scanf("%d", &size);
  stack = (int *)malloc(size * sizeof(int));
  while (1) {
    printf("1. Push 2. Pop 3. Peek 4. View 5. Exit\n");
    scanf("%d", &ch);
    if (ch == 5) break;
    switch (ch) {
      case 1:
        scanf("%d", &val);
        push(val);
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        view();
        break;
    }
  }
  free(stack);
  return 0;
}