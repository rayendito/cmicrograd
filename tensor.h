#include "value.h"

#ifndef TENSOR_H
#define TENSOR_H

typedef struct Tensor{
    int size;
    ValuePtr elements[];
} Tensor;

typedef Tensor * TensorPtr;

TensorPtr Tensor_create(int size, double data[]);
TensorPtr Tensor_create_empty(int size);
TensorPtr Tensor_create_random(int size);
TensorPtr Tensor_create_zeros(int size);

void Tensor_print(TensorPtr tensor);
void Tensor_print_grad(TensorPtr tensor);

#endif