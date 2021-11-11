#include <stdio.h>

struct complex {
    int real;
    int imag;
};

struct complex add(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

struct complex multiply(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

int main() {
    struct complex a, b, c;
    scanf("%d", &a.real);
    scanf("%d", &a.imag);
    scanf("%d", &b.real);
    scanf("%d", &b.imag);
    c = add(a, b);
    printf("%d+%di\n", c.real, c.imag);
    c = multiply(a, b);
    printf("%d+%di\n", c.real, c.imag);
    return 0;
}