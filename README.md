# DsTorch
创造一个类似PyTorch的DIY深度学习框架。之所以叫DsTorch是因为DeepSky的缩写（Ds），后面仿照PyTorch加上Torch，所以就叫DsTorch。

DsTorch中的核心是自己写了一套类似Numpy的多维数组（tensor）的计算库，能实现数组的常见操作，在GPU上的加速，以及梯度反向传播的自动求导等功能。

> 问：pytorch中的torch是什么意思？
>
> 答：在PyTorch中，"torch" 这个词指的是PyTorch库的核心组件，它是PyTorch提供的一个类似于NumPy的多维数组（tensor）的计算库。"Torch" 这个词在这里是一个缩写，它代表 "Tensor Object Representations and Computation Heuristics"，即“张量对象表示和计算启发式”。

# 使用方法

pass

# Tensor核心C++动态链接库的编译

动态链接库已经编译好了，但是如果你想自己尝试编译，那就使用Clion打开文件夹`./DsTorch/csrc`，基于cmake编译，生成的动态链接库文件保存在文件夹`./DsTorch/csrc/cmake-build-debug`中。

# 自己编写深度学习框架的过程

## tensor的CPU运算

pass

## tensor的GPU运算（基于CUDA）

pass

## 反向传播中的自动微分求导

pass

## 神经网络和优化器模块

pass

## 总结

pass

# 参考资料

* 英文博客：[Recreating PyTorch from Scratch (with GPU Support and Automatic Differentiation)](https://towardsdatascience.com/recreating-pytorch-from-scratch-with-gpu-support-and-automatic-differentiation-8f565122a3cc)
* 中文翻译：[从头开始重新创建 PyTorch](https://mp.weixin.qq.com/s/G2vN4u7lfGHiYMr072ZR7A)
* GitHub：博客中的代码地址为[lucasdelimanogueira/PyNorch](https://github.com/lucasdelimanogueira/PyNorch)

本项目一开始参考的是此博客。

