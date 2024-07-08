#include "layer.h"

#ifndef MLP_H
#define MLP_H

// bjir kepake juga ya double linked list
typedef struct MLP {
    int n_layers;
    LayerPtr first_layer;
    LayerPtr last_layer;
} MLP;

typedef MLP * MLPPTr;

MLPPTr MLP_create(int n_layers, LayerPtr layers[]);

int MLP_addLayer(MLPPTr mlp, LayerPtr layer);

int MLP_forward(MLPPTr mlp, TensorPtr tensor);
int MLP_backward(MLPPTr mlp);

void MLP_print_layer_outputs_forward(MLPPTr mlp);
void MLP_print_layer_outputs_backward(MLPPTr mlp);
void MLP_print_wandb(MLPPTr mlp);
void MLP_print_grad(MLPPTr mlp);

#endif