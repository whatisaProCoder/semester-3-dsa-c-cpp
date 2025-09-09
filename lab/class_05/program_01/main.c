/*
Write a program in C to perform the following operations with a menu-based
system. Observe the flow of data in stack and write the outputs in your
laboratory notes.
i. push - add item to stack (Print "overflow" if stack full)
ii. pop - remove item from stack
iii. peek - see the top item of stack
iv. view - gives the view of the stack.
*/

#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;

void push(int x) {
  if (top == MAX - 1)
    printf("overflow\n");
  else
    stack[++top] = x;
}

void pop() {
  if (top == -1)
    printf("underflow\n");
  else
    top--;
}

void peek() {
  if (top == -1)
    printf("empty\n");
  else
    printf("%d\n", stack[top]);
}

void view() {
  for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
  printf("\n");
}

int main() {
  int ch, x;
  do {
    printf("1.Push 2.Pop 3.Peek 4.View 5.Exit\n");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        scanf("%d", &x);
        push(x);
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
      case 5:
        break;
      default:
        printf("Wrong choice!");
    }
  } while (ch != 5);
  return 0;
}

/* OUTPUT
1.Push 2.Pop 3.Peek 4.View 5.Exit
1
5
1.Push 2.Pop 3.Peek 4.View 5.Exit
4
5
1.Push 2.Pop 3.Peek 4.View 5.Exit
5
*/