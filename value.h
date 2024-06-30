#include <stdio.h>
#include <string.h>

#ifndef VALUE_H
#define VALUE_H

#define NaN (-1.0 / 0.0)

typedef struct Value {
    double data;
    double grad;
    char operator;
    struct Value* operand1;
    struct Value* operand2;
} Value;

typedef Value* ValuePtr;

ValuePtr Value_create(double data);
ValuePtr Value_createFromOperator(double data, char operator, ValuePtr op1, ValuePtr op2);

ValuePtr Value_add(ValuePtr a, ValuePtr b);
ValuePtr Value_multiply(ValuePtr a, ValuePtr b);
ValuePtr Value_power(ValuePtr a, ValuePtr b);
ValuePtr Value_tanh(ValuePtr a);

double Value_getData(ValuePtr value);

void Value_print(ValuePtr value);

void Value_backward(ValuePtr value);
void Value_backward_helper(ValuePtr parent, ValuePtr value);

double getSiblingData(ValuePtr parent, ValuePtr value);
double regular_tanh(double x);

#endif