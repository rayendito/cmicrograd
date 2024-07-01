#include <stdio.h>
#include "value.h"

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

int Neuron_forward(NeuronPtr neuron, ValuePtr values[], int input_size);
int Neuron_backward(NeuronPtr neuron);

void Neuron_printWandB(NeuronPtr neuron);
double gen_random();

#endif