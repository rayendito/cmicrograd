#include <stdio.h>
#include "value.h"

int main(){
    // neural network example
    ValuePtr x1, x2, w1, w2, b, x1w1, x2w2, x1w1x2w2, n, o;
    x1 = Value_create(2);
    x2 = Value_create(0);
    w1 = Value_create(-3);
    w2 = Value_create(1);
    b = Value_create(6.8813735870195432);

    x1w1 = Value_multiply(x1, w1);
    x2w2 = Value_multiply(x2, w2);
    
    x1w1x2w2 = Value_add(x1w1, x2w2);

    n = Value_add(x1w1x2w2, b);

    o = Value_tanh(n);

    printf("BEFORE\n");
    Value_print(o);
    printf("\n");
    Value_print(n);
    printf("\n");
    Value_print(x1w1x2w2);
    printf("\n");
    Value_print(x2w2);
    printf("\n");
    Value_print(x1w1);
    printf("\n");
    Value_print(w2);
    printf("\n");
    Value_print(x2);
    printf("\n");
    Value_print(w1);
    printf("\n");
    Value_print(x1);

    // backwardmaxxing
    Value_backward(o);

    printf("SETELAH BEFORE\n");
    Value_print(o);
    printf("\n");
    Value_print(n);
    printf("\n");
    Value_print(x1w1x2w2);
    printf("\n");
    Value_print(x2w2);
    printf("\n");
    Value_print(x1w1);
    printf("\n");
    Value_print(w2);
    printf("\n");
    Value_print(x2);
    printf("\n");
    Value_print(w1);
    printf("\n");
    Value_print(x1);

    return 0;
}