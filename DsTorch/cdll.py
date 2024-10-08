# Python进阶之-ctypes详解
# https://blog.csdn.net/weixin_41238626/article/details/139242532
import ctypes
import os

script_directory = os.path.dirname(os.path.abspath(__file__))

# Load the shared library
try:
    lib = ctypes.CDLL(script_directory + '/csrc/cmake-build-debug/libdstorch.dll')
except OSError as e:
    print(f"Error loading DLL: {e}")
    exit(1)

add = lib.add
add.argtypes = [ctypes.c_float, ctypes.c_float]
add.restype = ctypes.c_float

hello = lib.hello
