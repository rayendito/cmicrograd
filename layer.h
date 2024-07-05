#include <stdio.h>
#include "neuron.h"
#include "tensor.h"

#ifndef LAYER_H
#define LAYER_H

typedef struct Layer {
    int input_size;
    int size;
    TensorPtr output;
    struct Layer* prev;
    struct Layer* next;
    NeuronPtr neurons[];
} Layer;

typedef Layer * LayerPtr;

LayerPtr Layer_create(int input_size, int size);
int Layer_forward(LayerPtr layer, TensorPtr tensor);
int Layer_backward(LayerPtr layer);

void Layer_print_output(LayerPtr layer);
void Layer_print_output_grad(LayerPtr layer);

void Layer_print_wandb(LayerPtr layer);

#endif