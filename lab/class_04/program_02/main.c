// Write a program to take 2 polynomials as input and perform the following
// operations -
// 1. addition
// 2. substraction
// 3. multiplication

// Take 1 polynomial as input & integrate it.

// Take 1 polynomial as input and differentiate it.

#include <stdio.h>

void inputPoly(double p[], int deg) {
  for (int i = 0; i <= deg; i++) scanf("%lf", &p[i]);
}

void printPoly(double p[], int deg) {
  int flag = 0;
  for (int i = 0; i <= deg; i++) {
    if (p[i] != 0) {
      if (flag && p[i] > 0) printf("+");
      if (deg - i == 0)
        printf("%.2f", p[i]);
      else if (deg - i == 1)
        printf("%.2fx", p[i]);
      else
        printf("%.2fx^%d", p[i], deg - i);
      flag = 1;
    }
  }
  if (!flag) printf("0");
  printf("\n");
}

void addPoly(double p1[], int d1, double p2[], int d2) {
  int maxd = d1 > d2 ? d1 : d2;
  double res[maxd + 1];
  for (int i = 0; i <= maxd; i++) {
    double c1 = (i <= d1) ? p1[i] : 0;
    double c2 = (i <= d2) ? p2[i] : 0;
    res[i] = c1 + c2;
  }
  printf("Addition: ");
  printPoly(res, maxd);
}

void subPoly(double p1[], int d1, double p2[], int d2) {
  int maxd = d1 > d2 ? d1 : d2;
  double res[maxd + 1];
  for (int i = 0; i <= maxd; i++) {
    double c1 = (i <= d1) ? p1[i] : 0;
    double c2 = (i <= d2) ? p2[i] : 0;
    res[i] = c1 - c2;
  }
  printf("Subtraction: ");
  printPoly(res, maxd);
}

void mulPoly(double p1[], int d1, double p2[], int d2) {
  double res[d1 + d2 + 1];
  for (int i = 0; i <= d1 + d2; i++) res[i] = 0;
  for (int i = 0; i <= d1; i++) {
    for (int j = 0; j <= d2; j++) {
      res[i + j] += p1[i] * p2[j];
    }
  }
  printf("Multiplication: ");
  printPoly(res, d1 + d2);
}

void integratePoly(double p[], int d) {
  double res[d + 2];
  for (int i = 0; i <= d + 1; i++) res[i] = 0;
  for (int i = 0; i <= d; i++) {
    res[i] = p[i] / (d - i + 1);
  }
  printf("Integration: ");
  printPoly(res, d + 1);
  printf("+C\n");
}

void diffPoly(double p[], int d) {
  if (d == 0) {
    printf("Differentiation: 0\n");
    return;
  }
  double res[d];
  for (int i = 0; i < d; i++) {
    res[i] = p[i] * (d - i);
  }
  printf("Differentiation: ");
  printPoly(res, d - 1);
}

int main() {
  int d1, d2;
  printf("Enter degree of 1st polynomial: ");
  scanf("%d", &d1);
  double p1[d1 + 1];
  printf("Enter coefficients (highest degree to constant):\n");
  inputPoly(p1, d1);

  printf("Enter degree of 2nd polynomial: ");
  scanf("%d", &d2);
  double p2[d2 + 1];
  printf("Enter coefficients (highest degree to constant):\n");
  inputPoly(p2, d2);

  addPoly(p1, d1, p2, d2);
  subPoly(p1, d1, p2, d2);
  mulPoly(p1, d1, p2, d2);

  int d3;
  printf("Enter degree of polynomial for integration/differentiation: ");
  scanf("%d", &d3);
  double p3[d3 + 1];
  printf("Enter coefficients:\n");
  inputPoly(p3, d3);

  integratePoly(p3, d3);
  diffPoly(p3, d3);

  return 0;
}

/* OUTPUT
Enter degree of 1st polynomial: 2
Enter coefficients (highest degree to constant):
1 2 1
Enter degree of 2nd polynomial: 1
Enter coefficients (highest degree to constant):
1 1
Addition: 1.00x^2+3.00x+2.00
Subtraction: 1.00x^2+1.00x+0.00
Multiplication: 1.00x^3+3.00x^2+3.00x+1.00
Enter degree of polynomial for integration/differentiation: 2
Enter coefficients:
1 2 1
Integration: 0.33x^3+1.00x^2+1.00x+0.00
+C
Differentiation: 2.00x+2.00
*/