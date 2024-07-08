#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "value.h"
#include "tensor.h"
#include "neuron.h"
#include "layer.h"
#include "mlp.h"

int main(){
    srand(time(NULL));

    // MLP example ====================================================================================
    const int INPUT_SIZE = 3;
    TensorPtr input;
    double arr[INPUT_SIZE] = {2,3,4};
    input = Tensor_create(INPUT_SIZE, arr);

    const int N_LAYER = 2;
    LayerPtr layer_arr[N_LAYER] = {
        Layer_create(3,4),
        Layer_create(4,2),
    };

    MLPPTr nn = MLP_create(N_LAYER, layer_arr);

    printf("BEFORE=========================\n");
    MLP_print_layer_outputs_forward(nn);

    // forwardmaxxing
    MLP_forward(nn, input);

    // backwardmaxxing
    MLP_backward(nn);

    printf("SETELAH BEFORE=========================\n");
    MLP_print_layer_outputs_forward(nn);
    
    printf("GRAD=========================\n");
    MLP_print_grad(nn);

    // // layer example ====================================================================================
    // const int INPUT_SIZE = 3;
    // const int LAYER_SIZE = 1;
    // TensorPtr input;
    // double arr[INPUT_SIZE] = {2,3,4};
    // input = Tensor_create(INPUT_SIZE, arr);

    // LayerPtr linear_layer;
    // linear_layer = Layer_create(INPUT_SIZE, LAYER_SIZE);
    
    

    // // forwardmaxxing
    // Layer_forward(linear_layer, input);
    
    // // print the compute graph of one of the neurons
    // printf("BEFORE=========================\n");
    // Value_print_comp_graph(linear_layer->neurons[0]->output);

    // // backwardmaxxing
    // Layer_backward(linear_layer);

    // // print the compute graph of one of the neurons
    // printf("SETELAH BEFORE=========================\n");
    // Value_print_comp_graph(linear_layer->neurons[0]->output);

    // // one neuron example ====================================================================================
    // NeuronPtr n;
    // n = Neuron_create(3);
    // // Neuron_print_w_and_b(n);
    // double d[3] = {2, 0, 1};
    // TensorPtr input = Tensor_create(3, d);
    // Neuron_forward(n, input);
    
    // printf("BEFORE========================\n\n");
    // Value_print_comp_graph(n->output);

    // // backwardmaxxing
    // Neuron_backward(n);

    // printf("SETELAH BEFORE========================\n\n");
    // Value_print_comp_graph(n->output);

    // manual neural network example =========================================================================
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

    printf("BEFORE========================\n\n");
    Value_print_comp_graph(o);

    // backwardmaxxing
    Value_backward(o);

    printf("SETELAH BEFORE========================\n\n");
    Value_print_comp_graph(o);

    return 0;
}