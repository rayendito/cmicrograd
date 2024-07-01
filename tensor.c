#include <stdlib.h>
#include <time.h>
#include "tensor.h"

// so far only supports 1D tensors, tomorrow? idk

TensorPtr Tensor_create(int size, double data[]){
    TensorPtr newTensor = (TensorPtr) malloc(sizeof(Tensor) + sizeof(ValuePtr[size]));
    newTensor->size = size;
    for(int i = 0; i < size; i++){
        newTensor->elements[i] = Value_create(data[i]);
    }
    return newTensor;
}

TensorPtr Tensor_create_empty(int size){
    TensorPtr newTensor = (TensorPtr) malloc(sizeof(Tensor) + sizeof(ValuePtr[size]));
    newTensor->size = size;
    return newTensor;
}

TensorPtr Tensor_create_random(int size){
    srand(time(NULL));
    TensorPtr newTensor = (TensorPtr) malloc(sizeof(Tensor) + sizeof(ValuePtr[size]));
    newTensor->size = size;
    for(int i = 0; i < size; i++){
        newTensor->elements[i] = Value_create(gen_random());
    }
    return newTensor;
}

TensorPtr Tensor_create_zeros(int size){
    TensorPtr newTensor = (TensorPtr) malloc(sizeof(Tensor) + sizeof(ValuePtr[size]));
    newTensor->size = size;
    for(int i = 0; i < size; i++){
        newTensor->elements[i] = Value_create(0);
    }
    return newTensor;
}

void Tensor_print(TensorPtr tensor){
    printf("[%.2f", tensor->elements[0]->data);
    for(int i = 1; i < tensor->size; i++){
        printf(", %.2f", tensor->elements[i]->data);
    }
    printf("]\n");
}