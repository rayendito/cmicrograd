#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int Neuron_forward(NeuronPtr neuron, ValuePtr values[], int input_size){
    if(neuron->size != input_size){  // sanity check
        return -1;
    }

    neuron->linear_comb = Value_multiply(neuron->w[0], values[0]);
    if(input_size > 1){
        for (int i = 1; i < input_size; i++) {
            neuron->linear_comb = Value_add(neuron->linear_comb, Value_multiply(neuron->w[i], values[i]));
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

double gen_random(){
    double div = RAND_MAX / 2;
    return -1 + (rand() / div);
}