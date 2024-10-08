//
// Created by luwei on 24/10/8.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "tensor_math.h"
#include "tensor_cpu.h"
#include "tensor_base.h"

Tensor* add_tensor(Tensor* tensor1, Tensor* tensor2) {
    if (tensor1->ndim != tensor2->ndim) {
        fprintf(stderr, "Tensors must have the same number of dimensions %d and %d for addition\n", tensor1->ndim, tensor2->ndim);
        exit(1);
    }

    if (strcmp(tensor1->device, tensor2->device) != 0) {
        fprintf(stderr, "Tensors must be on the same device: %s and %s\n", tensor1->device, tensor2->device);
        exit(1);
    }

    int ndim = tensor1->ndim;
    int* shape = (int*)malloc(ndim * sizeof(int));
    if (shape == nullptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < ndim; i++) {
        if (tensor1->shape[i] != tensor2->shape[i]) {
            fprintf(stderr, "Tensors must have the same shape %d and %d at index %d for addition\n", tensor1->shape[i], tensor2->shape[i], i);
            exit(1);
        }
        shape[i] = tensor1->shape[i];
    }

    if (strcmp(tensor1->device, "cpu") == 0) {
        float* result_data = (float*)malloc(tensor1->size * sizeof(float));
        if (result_data == nullptr) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        add_tensor_cpu(tensor1, tensor2, result_data);
        return create_tensor(result_data, shape, ndim, tensor1->device);
    }
    else {
        // TODO
//        float* result_data;
//        cudaMalloc((void **)&result_data, tensor1->size * sizeof(float));
//        add_tensor_cuda(tensor1, tensor2, result_data);
//        return create_tensor(result_data, shape, ndim, tensor1->device);
        return nullptr;
    }
}
