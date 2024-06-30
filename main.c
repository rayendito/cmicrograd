#include <stdio.h>
#include "value.h"

int main(){
    // ValuePtr x, c1, exp, c2, c3, y, y_tanh;

    // x = Value_create(3);
    // exp = Value_create(2);
    // c1 = Value_create(1);
    // c2 = Value_create(3);
    // c3 = Value_create(-1);

    // right, C does not support operator overloading :D
    // y = x^2 + 3x - 1
    // y = Value_add(Value_multiply(c1, Value_power(x, exp)),Value_add(Value_multiply(x, c2), c3));
    // Value_print(y);

    // karpathy's example
    ValuePtr a, b, c, d, e, f, L, L2;
    a = Value_create(2);
    b = Value_create(-3);
    c = Value_create(10);
    e = Value_multiply(a, b);
    d = Value_add(e, c);
    f = Value_create(-2);
    L = Value_multiply(d, f);
    // L2 = Value_tanh(L);

    printf("BEFORE\n");
    // Value_print(L2);
    // printf("\n");
    Value_print(L);
    printf("\n");
    Value_print(d);
    printf("\n");
    Value_print(f);
    printf("\n");
    Value_print(c);
    printf("\n");
    Value_print(e);
    printf("\n");
    Value_print(a);
    printf("\n");
    Value_print(b);

    // backwardmaxxing
    Value_backward(L);

    printf("SETELAH BEFORE\n");
    // Value_print(L2);
    // printf("\n");
    Value_print(L);
    printf("\n");
    Value_print(d);
    printf("\n");
    Value_print(f);
    printf("\n");
    Value_print(a);
    printf("\n");
    Value_print(b);

    return 0;
}