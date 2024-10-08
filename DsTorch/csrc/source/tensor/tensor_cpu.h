//
// Created by luwei on 24/10/8.
//

#ifndef DSTORCH_TENSOR_CPU_H
#define DSTORCH_TENSOR_CPU_H

#include "define.h"
#include "tensor_struct.h"

DLL_API void add_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data);
DLL_API void sub_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data);
DLL_API void elementwise_mul_tensor_cpu(Tensor* tensor1, Tensor* tensor2, float* result_data);
DLL_API void assign_tensor_cpu(Tensor* tensor, float* result_data);

#endif //DSTORCH_TENSOR_CPU_H
