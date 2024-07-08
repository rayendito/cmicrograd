#include <stdlib.h>
#include <time.h>
#include "layer.h"

LayerPtr Layer_create(int input_size, int size){
    srand(time(NULL));
    LayerPtr newLayer = (LayerPtr) malloc(sizeof(Layer) + sizeof(NeuronPtr[size]));
    newLayer->input_size = input_size;
    newLayer->size = size;

    newLayer->prev = NULL;
    newLayer->next = NULL;

    for (int i = 0; i < size; i++) {
        newLayer->neurons[i] = Neuron_create(input_size);
    }

    // to store outputs
    newLayer->output = Tensor_create_empty(size);
    for(int i = 0; i < size; i++){
        newLayer->output->elements[i] = newLayer->neurons[i]->output;
    }

    return newLayer;
}

// UNTESTED, gmn ya cara ngetes yang bener kwaokwaka

int Layer_forward(LayerPtr layer, TensorPtr tensor){
    if(layer->input_size != tensor->size){
        printf("layer->input_size and input_size mismatch!\n"); // i really should do checks like these to all lol
        return -1;
    }

    // calculate output for every neuron against the tensor input
    for(int i = 0; i < layer->size; i++){
        Neuron_forward(layer->neurons[i], tensor);
    }

    // updating the output pointers to point at Values of the neuron outputs
    for(int i = 0; i < layer->size; i++){
        layer->output->elements[i] = layer->neurons[i]->output;
    }

    return 0;
}

int Layer_backward(LayerPtr layer){
    // thassit?
    for(int i = 0; i < layer->size; i++){
        Neuron_backward(layer->neurons[i]);
    }
    return 0;
}

void Layer_print_output(LayerPtr layer){
    Tensor_print(layer->output);
}

void Layer_print_output_grad(LayerPtr layer){
    Tensor_print_grad(layer->output);
}

void Layer_print_wandb(LayerPtr layer){
    for(int i = 0; i < layer->size; i++){
        Neuron_print_w_and_b(layer->neurons[i]);
    }
}