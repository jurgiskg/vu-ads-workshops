#include <stdio.h>
#include <stdlib.h>

struct DivAndMod {
    int div;
    int mod;
};

int sum(int a, int b) {
    return a + b;
}

struct DivAndMod divAndMod(int a, int b) {
    struct DivAndMod res;

    if (b == 0) {
        printf("Cant divide by zero!\n");
        res.div = -1;
        return res;
    }
    
    res.div = a / b;
    res.mod = a % b;

    return res;
}

int main() {
    int a = 42;
    int b = 5;

    int sumRes = sum(a, b);
    printf("%d\n", sumRes);

    struct DivAndMod divAndModRes = divAndMod(a, b);
    if (divAndModRes.div == -1) {
        return 0;
    }
    printf("%d\n", divAndModRes.div);
    printf("%d\n", divAndModRes.mod);
    
    return 0;
}
