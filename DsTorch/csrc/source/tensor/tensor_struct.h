//
// Created by luwei on 24/10/8.
//

#ifndef DSTORCH_TENSOR_STRUCT_H
#define DSTORCH_TENSOR_STRUCT_H

/*
 * [[1, 2, 3],
 *  [4, 5, 6]]
 * */
typedef struct {
    float* data;  // 一维数组存储，优先行排列，即存储方式[1,2,3,4,5,6]
    int* strides;  // 步幅，[3, 1]，方便快速查找对应位置的元素值，例如找第2行3列的元素，那么位置就是(2-1)*3+(3-1)*1 = 3+2 = 5，即矩阵的第6个元素
    int* shape;  // 形状，[2,3]
    int ndim;  // 维度，2
    int size;  // 元素数量，6
    char* device;
} Tensor;

#endif //DSTORCH_TENSOR_STRUCT_H
