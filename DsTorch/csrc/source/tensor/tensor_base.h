//
// Created by luwei on 24/10/8.
//

#ifndef DSTORCH_TENSOR_BASE_H
#define DSTORCH_TENSOR_BASE_H

#include "define.h"
#include "tensor_struct.h"

DLL_API float add(float, float);
DLL_API Tensor* create_tensor(float* data, int* shape, int ndim, char* device);
DLL_API float get_item(Tensor* tensor, int* indices);
DLL_API Tensor* reshape_tensor(Tensor* tensor, const int* new_shape, int new_ndim);

#endif //DSTORCH_TENSOR_BASE_H
