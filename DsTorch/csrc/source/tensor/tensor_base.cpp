//
// Created by luwei on 24/10/8.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "tensor_base.h"
#include "tensor_cpu.h"

float add(float a, float b) {
    return a + b;
}

Tensor* create_tensor(float* data, int* shape, int ndim, char* device) {
    auto* tensor = (Tensor*)malloc(sizeof(Tensor));
    if (tensor == nullptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    tensor->data = data;
    tensor->shape = shape;
    tensor->ndim = ndim;

    tensor->device = (char*)malloc(strlen(device) + 1);
    if (device != nullptr) {
        strcpy(tensor->device, device);
    } else {
        fprintf(stderr, "Memory allocation failed\n");
        exit(-1);
    }

    tensor->size = 1;
    for (int i = 0; i < ndim; i++) {
        tensor->size *= shape[i];
    }

    tensor->strides = (int*)malloc(ndim * sizeof(int));
    if (tensor->strides == nullptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int stride = 1;
    for (int i = ndim - 1; i >= 0; i--) {
        tensor->strides[i] = stride;
        stride *= shape[i];
    }

    return tensor;
}

// 查找对应位置的元素值
float get_item(Tensor* tensor, int* indices) {
    int index = 0;
    for (int i = 0; i < tensor->ndim; i++) {
        index += indices[i] * tensor->strides[i];
    }

    float result;
    result = tensor->data[index];

    return result;
}

Tensor* reshape_tensor(Tensor* tensor, const int* new_shape, int new_ndim) {
    int ndim = new_ndim;
    int* shape = (int*)malloc(ndim * sizeof(int));
    if (shape == nullptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < ndim; i++) {
        shape[i] = new_shape[i];
    }

    // Calculate the total number of elements in the new shape
    int size = 1;
    for (int i = 0; i < new_ndim; i++) {
        size *= shape[i];
    }

    // Check if the total number of elements matches the current tensor's size
    if (size != tensor->size) {
        fprintf(stderr, "Cannot reshape tensor. Total number of elements in new shape does not match the current size of the tensor.\n");
        exit(1);
    }

    if (strcmp(tensor->device, "cpu") == 0) {
        auto* result_data = (float*)malloc(tensor->size * sizeof(float));
        if (result_data == nullptr) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        assign_tensor_cpu(tensor, result_data);
        return create_tensor(result_data, shape, ndim, tensor->device);
    }
    else {
        // TODO
//        float* result_data;
//        cudaMalloc((void **)&result_data, tensor->size * sizeof(float));
//        assign_tensor_cuda(tensor, result_data);
//        return create_tensor(result_data, shape, ndim, tensor->device);
        return nullptr;
    }
}
