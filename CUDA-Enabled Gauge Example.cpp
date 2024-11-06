#include <cuda_runtime.h>
#include <iostream>

__global__ void adjustResource(int *resource, int base, int stretch) {
    int usage = base + stretch;
    *resource = usage > 100 ? 100 : usage;
}

void gpuGauge(int base, int stretch) {
    int *d_resource;
    cudaMalloc(&d_resource, sizeof(int));
    adjustResource<<<1, 1>>>(d_resource, base, stretch);
    cudaDeviceSynchronize();
    int result;
    cudaMemcpy(&result, d_resource, sizeof(int), cudaMemcpyDeviceToHost);
    std::cout << "Resource adjusted to: " << result << "%" << std::endl;
    cudaFree(d_resource);
}
