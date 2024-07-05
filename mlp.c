#include <stdlib.h>
#include "mlp.h"

MLPPTr MLP_create(int n_layers, LayerPtr layer_array[]){
    int status = 0;
    MLPPTr newMLP = (MLPPTr) malloc(sizeof(MLP));
    newMLP->n_layers = n_layers;
    for(int i = 0; i < n_layers; i++){
        if(i == 0){
            newMLP->first_layer = layer_array[i];
            newMLP->last_layer = layer_array[i];
        }
        else{
            status = MLP_addLayer(newMLP, layer_array[i]);
            if(status == -1){
                printf("Layer size mismatch error, abort create MLP\n");
                return NULL;
            }
        }
    }

    return newMLP;
}

int MLP_addLayer(MLPPTr mlp, LayerPtr layer){
    if(mlp->last_layer->size != layer->input_size){
        printf("ERROR: previous layer size of %d mismatch with new layer %d\n", mlp->last_layer->size, layer->input_size);
        return -1;
    }

    mlp->last_layer->next = layer;
    layer->prev = mlp->last_layer;
    mlp->last_layer = mlp->last_layer->next;

    mlp->n_layers = mlp->n_layers + 1;

    return 0;
}

int MLP_forward(MLPPTr mlp, TensorPtr tensor){
    if(mlp->first_layer->input_size != tensor->size){
        printf("layer->input_size and input_size mismatch!\n");
        return -1;
    }
    
    TensorPtr to_forward = tensor;
    LayerPtr current_layer = mlp->first_layer;
    while(current_layer != NULL){
        Layer_forward(current_layer, to_forward);
        to_forward = current_layer->output;
        current_layer = current_layer->next;
    }

    return 0;
}


// this should be an opitmizer though, instead of just backprop-ing on the logits
// but for the time being, leave it at this
int MLP_backward(MLPPTr mlp){
    Layer_backward(mlp->last_layer); // wait dassit?
    return 0;
}

// for testing if things work tbh wkwk i know maybe there are better ways than just printing lol
void MLP_printLayerOutputsForward(MLPPTr mlp){
    LayerPtr layr = mlp->first_layer;
    while(layr != NULL){
        Layer_print_output(layr);
        layr = layr->next;
    }
}

void MLP_printLayerOutputsBackward(MLPPTr mlp){
    LayerPtr layr = mlp->last_layer;
    while(layr != NULL){
        Layer_print_output(layr);
        layr = layr->prev;
    }
}

void MLP_print_wandb(MLPPTr mlp){
    LayerPtr layr = mlp->first_layer;
    while(layr != NULL){
        Layer_print_wandb(layr);
        layr = layr->next;
    }
}

void MLP_print_grad(MLPPTr mlp){
    LayerPtr layr = mlp->first_layer;
    while(layr != NULL){
        Layer_print_output_grad(layr);
        layr = layr->next;
    }
}