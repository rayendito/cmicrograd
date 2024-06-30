#include <stdlib.h>
#include <math.h>
#include "value.h"

// operator N is null. i couldn't NULL it for some reason

ValuePtr Value_create(double data){
    ValuePtr newValue = (ValuePtr) malloc (sizeof(Value));
    if(newValue != NULL){
        newValue->data = data;
        newValue->grad = 0.0;
        newValue->operator = ' ';
        newValue->operand1 = NULL;
        newValue->operand2 = NULL;
    }
    return newValue;
}

ValuePtr Value_createFromOperator(double data, char operator, ValuePtr op1, ValuePtr op2){
    ValuePtr newValue = (ValuePtr) malloc (sizeof(Value));
    if(newValue != NULL){
        newValue->data = data;
        newValue->grad = 0.0;
        newValue->operator = operator;
        newValue->operand1 = op1;
        newValue->operand2 = op2;
    }
    return newValue;
}

ValuePtr Value_add(ValuePtr a, ValuePtr b){
    return Value_createFromOperator(a->data + b->data, '+', a, b);
}

ValuePtr Value_multiply(ValuePtr a, ValuePtr b){
    return Value_createFromOperator(a->data * b->data, '*', a, b);
}

ValuePtr Value_power(ValuePtr a, ValuePtr b){
    return Value_createFromOperator(pow(a->data, b->data), 'p', a, b);
}

ValuePtr Value_tanh(ValuePtr a){
    return Value_createFromOperator(regular_tanh(a->data), 't', a, NULL);
}

double Value_getData(ValuePtr value){
    return value->data;
}

void Value_print(ValuePtr value){
    printf("Data is %.2f\n", value->data);
    printf("Grad is %.2f\n", value->grad);
}

void Value_backward(ValuePtr value){
    Value_backward_helper(NULL, value);
}

void Value_backward_helper(ValuePtr parent, ValuePtr value){
    if(!value){
        return;
    }
    if(!parent){
        value->grad = 1;
    }
    else{
        switch (parent->operator){
            case 't': //tanh
                value->grad += parent->grad * (1.0 - pow(regular_tanh(value->data), 2));
                break;
            case '+':
                value->grad += parent->grad;
                break;
            case '*':
                value->grad += parent->grad * getSiblingData(parent, value);
                break;
            default:
                break;
        }
    }
    Value_backward_helper(value, value->operand1);
    Value_backward_helper(value, value->operand2);
}

double getSiblingData(ValuePtr parent, ValuePtr value){
    if(parent->operator == '*'){ //can only be used by a Value whose parent is a multiply
        if(parent->operand1 == value){
            return parent->operand2->data;
        }
        return parent->operand1->data;
    }
    return NaN;
}

double regular_tanh(double x){
    return (exp(2*x) - 1)/(exp(2*x) + 1);
}