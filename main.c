#include <stdio.h>
#include "value.h"
#include "neuron.h"

int main(){
    // one neuron example ====================================================================================
    NeuronPtr n;
    n = Neuron_create(2);
    // Neuron_printWandB(n);
    ValuePtr v[2] = {Value_create(1), Value_create(2)};
    Neuron_forward(n, v, 2);
    
    printf("BEFORE========================\n\n");
    Value_printCompGraph(n->output);

    // backwardmaxxing
    Neuron_backward(n);

    printf("SETELAH BEFORE========================\n\n");
    Value_printCompGraph(n->output);

    // // manual neural network example =========================================================================
    // ValuePtr x1, x2, w1, w2, b, x1w1, x2w2, x1w1x2w2, n, o;
    // x1 = Value_create(2);
    // x2 = Value_create(0);
    // w1 = Value_create(-3);
    // w2 = Value_create(1);
    // b = Value_create(6.8813735870195432);

    // x1w1 = Value_multiply(x1, w1);
    // x2w2 = Value_multiply(x2, w2);
    
    // x1w1x2w2 = Value_add(x1w1, x2w2);

    // n = Value_add(x1w1x2w2, b);

    // o = Value_tanh(n);

    // printf("BEFORE========================\n\n");
    // Value_printCompGraph(o);

    // // backwardmaxxing
    // Value_backward(o);

    // printf("SETELAH BEFORE========================\n\n");
    // Value_printCompGraph(o);

    return 0;
}