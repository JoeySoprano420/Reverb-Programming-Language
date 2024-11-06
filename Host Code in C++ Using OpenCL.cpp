#include <CL/cl.hpp>
#include <iostream>
#include <vector>

void openclGauge(int base, int stretch) {
    // Platform and device setup
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    cl::Platform default_platform = platforms[0];

    std::vector<cl::Device> devices;
    default_platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
    cl::Device default_device = devices[0];

    cl::Context context({default_device});
    cl::Program::Sources sources;

    // Load kernel source
    std::string kernel_code = R"(
        __kernel void adjustResource(__global int *resource, const int base, const int stretch) {
            int adjusted_usage = base + stretch;
            *resource = adjusted_usage > 100 ? 100 : adjusted_usage;
        }
    )";
    sources.push_back({kernel_code.c_str(), kernel_code.length()});

    // Build program
    cl::Program program(context, sources);
    if (program.build({default_device}) != CL_SUCCESS) {
        std::cerr << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(default_device) << std::endl;
        return;
    }

    // Buffer allocation
    int resource = 0;
    cl::Buffer buffer_resource(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, sizeof(int), &resource);

    // Create kernel and set arguments
    cl::Kernel kernel(program, "adjustResource");
    kernel.setArg(0, buffer_resource);
    kernel.setArg(1, base);
    kernel.setArg(2, stretch);

    // Queue execution
    cl::CommandQueue queue(context, default_device);
    queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(1), cl::NDRange(1));
    queue.enqueueReadBuffer(buffer_resource, CL_TRUE, 0, sizeof(int), &resource);

    std::cout << "Adjusted Resource Usage: " << resource << "%" << std::endl;
}
