struct color {
    int r;
    int g;
    int b;
};
typedef struct color Color;

void initColor(Color *c, int r, int g, int b) {
    c->r = r;
    c->g = g;
    c->b = b;
}

Color averageColor(Color c[], int n) {
    Color Average;
    c[n];
    int sum_r = 0;
    for (int i = 0; i < n; i++) {
        sum_r += c[i].r;
    }
    Average.r = sum_r / n;
    int sum_g = 0;
    for (int i = 0; i < n; i++) {
        sum_g += c[i].g;
    }
    Average.g = sum_g / n;
    int sum_b = 0;
    for (int i = 0; i < n; i++) {
        sum_b += c[i].b;
    }
    Average.b = sum_b / n;
    return Average;
}

double brightness(Color *c) {
    double br;
    br = (c->r + c->g + c->b) / 3.;
    return br;
}

void printColor(Color *c) {
    printf("(%d, %d, %d) ", c->r, c->g, c->b);
    printf("%f\n", brightness(c));
}