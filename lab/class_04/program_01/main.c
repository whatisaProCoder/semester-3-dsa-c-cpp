// Write a program to take a polynomial as input, store it in array and print
// it.

#include <stdio.h>

int main() {
  int deg;
  printf("Enter degree of polynomial: ");
  scanf("%d", &deg);

  int poly[deg + 1];
  printf("Enter coefficients from highest degree to constant:\n");
  for (int i = 0; i <= deg; i++) {
    scanf("%d", &poly[i]);
  }

  printf("Polynomial: ");
  for (int i = 0; i <= deg; i++) {
    if (poly[i] != 0) {
      if (i != 0 && poly[i] > 0) printf("+");
      if (deg - i == 0)
        printf("%d", poly[i]);
      else if (deg - i == 1)
        printf("%dx", poly[i]);
      else
        printf("%dx^%d", poly[i], deg - i);
    }
  }
  printf("\n");

  return 0;
}

/* OUTPUT
Enter degree of polynomial: 3
Enter coefficients from highest degree to constant:
1 2 3 4
Polynomial: 1x^3+2x^2+3x+4
*/