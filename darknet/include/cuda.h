#ifndef CUDA_H
#define CUDA_H

#include "cublas_v2.h"
#include "cuda_runtime.h"
#include "curand.h"

extern int gpu_index;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef DKGPU

#define BLOCK 512

#ifdef CUDNN
#include "cudnn.h"
#endif

void check_error(cudaError_t status);
cublasHandle_t blas_handle();
float *cuda_make_array(float *x, size_t n);
int *cuda_make_int_array(size_t n);
void cuda_push_array(float *x_gpu, float *x, size_t n);
void cuda_pull_array(float *x_gpu, float *x, size_t n);
void cuda_set_device(int n);
void cuda_free(float *x_gpu);
void cuda_random(float *x_gpu, size_t n);
float cuda_compare(float *x_gpu, float *x, size_t n, char *s);
dim3 cuda_gridsize(size_t n);

#ifdef CUDNN
cudnnHandle_t cudnn_handle();
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif
