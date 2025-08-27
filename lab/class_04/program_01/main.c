// Write a program to take a polynomial as input, store it in array and print
// it.

void display(int poly[], int deg) {
  for (int i = deg - 1; i >= 0; i++) {
    if (poly[i] == 0) return;
    if (poly[i] > 0 && i > 0) printf("+");
    int coeff = poly[i];
    int pow = i;
    if (pow == 0)
      printf("%d", coeff);
    else if (pow == 1 && poly)
  }
}

int main() {
  int deg;
  printf("Enter degree of polynomial: ");
  scanf("%d", &deg);

  int poly[deg];

  printf("Enter the coefficients: ");
  for (int i = deg - 1; i >= 0; i++) {
    scanf("%d", poly[i]);
  }

  display(poly, deg);
}