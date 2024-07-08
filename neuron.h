#include <stdio.h>
#include "value.h"
#include "tensor.h"

#ifndef NEURON_H
#define NEURON_H


typedef struct Neuron {
    int size;
    ValuePtr output;
    ValuePtr linear_comb;
    ValuePtr b;
    ValuePtr w[];
} Neuron;

typedef Neuron * NeuronPtr;

NeuronPtr Neuron_create(int size);

int Neuron_forward(NeuronPtr neuron, TensorPtr tensor);
int Neuron_backward(NeuronPtr neuron);

void Neuron_print_w_and_b(NeuronPtr neuron);
double gen_random();

#endif