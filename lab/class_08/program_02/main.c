// Given the head of linked list and a value, insert a new node with that value
// at the end of the list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->value = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    struct Node* prev = head;
    while (prev->next != NULL) {
      prev = prev->next;
    }
    prev->next = temp;
  }
}

void printLL() {
  printf("LL :- ");
  struct Node* temp = head;
  if (head == NULL) {
    printf("Empty\n");
  } else {
    while (temp) {
      printf("%d ", temp->value);
      temp = temp->next;
    }
  }
}

int main() {
  int n, value;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter value for node %d : ", i + 1);
    int value;
    scanf("%d", &value);
    insert(value);
  }

  printLL();

  return 0;
}

/*OUTPUT
Enter the number of nodes: 5
Enter value for node 1 : 7
Enter value for node 2 : 6
Enter value for node 3 : 5
Enter value for node 4 : 4
Enter value for node 5 : 3
LL :- 7 6 5 4 3
*/