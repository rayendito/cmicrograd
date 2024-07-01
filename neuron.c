#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "value.h"
#include "neuron.h"

NeuronPtr Neuron_create(int size){
    srand(time(NULL));
    NeuronPtr newNeuron = malloc(sizeof(Neuron) + sizeof(ValuePtr[size]));
    newNeuron->output = Value_create(0.0);
    newNeuron->linear_comb = Value_create(0.0);
    newNeuron->b = Value_create(gen_random());
    newNeuron->size = size;
    for (int i = 0; i < size; i++) {
        newNeuron->w[i] = Value_create(gen_random());
    }
    return newNeuron;
}

int Neuron_forward(NeuronPtr neuron, TensorPtr tensor){
    if(neuron->size != tensor->size){  // sanity check
        return -1;
    }

    neuron->linear_comb = Value_multiply(neuron->w[0], tensor->elements[0]);
    if(tensor->size > 1){
        for (int i = 1; i < tensor->size; i++) {
            neuron->linear_comb = Value_add(neuron->linear_comb, Value_multiply(neuron->w[i], tensor->elements[i]));
        }
    }
    neuron->linear_comb = Value_add(neuron->linear_comb, neuron->b);
    neuron->output = Value_tanh(neuron->linear_comb);

    return 0;
}

int Neuron_backward(NeuronPtr neuron){
    Value_backward(neuron->output); // lol that's it?
    return 0;
}

void Neuron_printWandB(NeuronPtr neuron){
    printf("Weights: ");
    for (int i = 0; i< neuron->size; i++) {
        printf(" %.2f,", neuron->w[i]->data);
    }
    printf("\n");
    printf("Bias: %.2f\n", neuron->b->data);

    printf("\n");
    printf("Linear comb.: %.2f\n", neuron->linear_comb->data);
}

