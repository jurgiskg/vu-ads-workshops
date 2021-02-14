#include <math.h>
#include <stdio.h>

typedef struct {
    int x, y;
} Point;

double calculateSquaredDistance(Point a, Point b) {
    int x1 = a.x;
    int x2 = b.x;
    int y1 = a.y;
    int y2 = b.y;

    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int isTheSamePoint(Point a, Point b) {
    if (a.x == b.x && a.y == b.y) {
        return 1;
    }
    return -1;
}

int isTriangle(Point a, Point b, Point c) {
    if ((a.x == b.x == c.x) || (a.y == b.y == c.y)) {
        printf("All points are on the same line.\n");
        return -1;
    }

    if (isTheSamePoint(a, b) == 1 || isTheSamePoint(a, c) == 1 || isTheSamePoint(b, c) == 1) {
        printf("Two points match\n");
        return -1;
    }

    return 1;
}

int isRightTriangle(Point a, Point b, Point c) {
    if (isTriangle(a, b, c) == -1) {
        return -1;
    }

    double abSquared = calculateSquaredDistance(a, b);
    double bcSquared = calculateSquaredDistance(b, c);
    double acSquared = calculateSquaredDistance(a, c);

    if ((abSquared + bcSquared == acSquared) || (abSquared + acSquared == bcSquared) || (bcSquared + acSquared == abSquared)) {
        return 1;
    }

    return -1;
}

int main() {
    Point a = {12, -2};
    Point b = {10, -4};
    Point c = {-1, 7};

    int answer = isRightTriangle(a, b, c);
    printf("%d\n", answer);

    return 0;
}