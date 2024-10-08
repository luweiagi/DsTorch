cmake_minimum_required(VERSION 3.21)
project(dstorch)
set(CMAKE_CXX_STANDARD 14)

set(prj_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/source)
file(GLOB_RECURSE root_src_files "${prj_src_dir}/*")
message(STATUS "root_src_files = ${root_src_files}")

# src file (*.cpp + *.h)
set(PRJ_SRC_LIST)
list(APPEND PRJ_SRC_LIST ${root_src_files})
message("PRJ_SRC_LIST = ${PRJ_SRC_LIST}")

# header path
include_directories(./;./source/;./source/define/;./source/dstorch/;./source/tensor/;)

add_library(${PROJECT_NAME} SHARED ${PRJ_SRC_LIST})
target_compile_definitions(${PROJECT_NAME} PRIVATE DLL_EXPORTS)
