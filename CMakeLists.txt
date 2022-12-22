cmake_minimum_required(VERSION 3.16)
project(ndarray_backend LANGUAGES CXX CUDA)

find_package(pybind11 REQUIRED)
find_package(CUDA REQUIRED)

set(CMAKE_CUDA_ARCHITECTURES "75")
set(CMAKE_CXX_FLAGS "-O3 -march=native -mavx")
set(CMAKE_CUDA_FLAGS "-O3 -march=native -mavx")

set(SOURCE_DIR "ndarray/backend")
include_directories(${SOURCE_DIR})

set(SOURCES 

)

if(${CUDA_ERROR_CHECK} MATCHES "True")
  add_compile_definitions(_CUDA_ERROR_CHECK)
endif()

pybind11_add_module(${PROJECT_NAME} ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
