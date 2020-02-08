#include<iostream>
#include<cuda.h>
#include<cuda_runtime.h>
#include <device_launch_parameters.h>
#include <device_functions.h>
#include <cuda_runtime_api.h>
#include<cstdlib>
#include<cstdio>
using namespace std;

template<class T>
void print(T a){
    cout << a << endl;
}


//all kernels have the 'void' return type
//global --> 1) runs on the device 2) called from the host code
// nvcc separates src code into host and device components
// host functions processed by the standard host compiler
// device funtions processed by the nvcc
__global__ void mykernel(void){  
    return;
}

__global__ void addInt(int *a, int *b, int *c){
    
    *c = *a + *b;
}

void testAddInt(){
    int a, b, c;
    int *d_a, *d_b, *d_c;
    int size = sizeof(double);//allocate space
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);

    a = 7, b = 2;

    cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

    addInt<<<1, 1>>>(d_a, d_b, d_c);

    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    cout << c << endl;
}

__global__ void addIntBlks(double* a, double *b, double *c){
    // __syncthreads();
    c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
    printf("BlockIdx.x: %d\n", blockIdx.x);
}

void testAddIntBlks(){
    // size_t N = 1<<25;
    size_t N = 10;
    double *d_a, *d_b, *d_c;
    size_t size = sizeof(double) * N;

    double *a = (double *)malloc(size);
    double *b = (double *)malloc(size);
    double *c = (double *)malloc(size);

    for (size_t i = 0; i < N; i++){
        a[i] = drand48();
        b[i] = drand48();
    }

    //allocate space
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);


    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    addIntBlks<<<N, 1>>>(d_a, d_b, d_c);

    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

    srand(1);
    cout << rand() << " " << rand() % N << endl;
    size_t i = rand() % N;
    cout << N << " " << i << endl;
    cout << "a[" << i << "] + b[" << i << "] = " << a[i] + b[i] << endl;
    cout << "c[" << i << "] =" << c[i] << endl;

    double res = 0;
    for (size_t i = 0; i < N; i++){
        res += a[i] + b[i] - c[i];
    }
    cout << res << endl;
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}

int main(){
    cout << "hello world!" << endl;
    print<string>(string("shabi"));
    mykernel<<<1,1>>>();

    testAddInt();
    testAddIntBlks();

    return 0;
}