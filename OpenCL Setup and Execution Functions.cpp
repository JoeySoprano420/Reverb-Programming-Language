#include <CL/cl.hpp>
#include <iostream>

class ReverbRuntime {
public:
    ReverbRuntime() {
        // Initialize OpenCL platform, device, context, and queue
        cl::Platform::get(&platforms);
        platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &devices);
        context = cl::Context(devices);
        queue = cl::CommandQueue(context, devices[0]);
    }

    void executeGauge(int base, int stretch) {
        std::string gaugeKernelCode = R"(
            __kernel void gaugeKernel(__global float* output, const int base, const int stretch) {
                int id = get_global_id(0);
                output[id] = base + stretch * id; // Simple example computation
            }
        )";

        cl::Program::Sources sources;
        sources.push_back({gaugeKernelCode.c_str(), gaugeKernelCode.length()});

        cl::Program program(context, sources);
        if (program.build(devices) != CL_SUCCESS) {
            std::cerr << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[0]) << std::endl;
            return;
        }

        // Allocate memory for output and initialize base/stretch on the device
        cl::Buffer bufferOutput(context, CL_MEM_WRITE_ONLY, sizeof(float) * 1024);
        cl::Kernel kernel(program, "gaugeKernel");
        kernel.setArg(0, bufferOutput);
        kernel.setArg(1, base);
        kernel.setArg(2, stretch);

        queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(1024), cl::NullRange);
        queue.finish();
    }

    void executePulse(int frequency, bool stabilize) {
        std::string pulseKernelCode = R"(
            __kernel void pulseKernel(__global float* output, const int frequency, const int stabilize) {
                int id = get_global_id(0);
                output[id] = stabilize ? frequency * id : frequency; // Example pulse calculation
            }
        )";

        cl::Program::Sources sources;
        sources.push_back({pulseKernelCode.c_str(), pulseKernelCode.length()});

        cl::Program program(context, sources);
        if (program.build(devices) != CL_SUCCESS) {
            std::cerr << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[0]) << std::endl;
            return;
        }

        cl::Buffer bufferOutput(context, CL_MEM_WRITE_ONLY, sizeof(float) * 1024);
        cl::Kernel kernel(program, "pulseKernel");
        kernel.setArg(0, bufferOutput);
        kernel.setArg(1, frequency);
        kernel.setArg(2, (int)stabilize);

        queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(1024), cl::NullRange);
        queue.finish();
    }

private:
    std::vector<cl::Platform> platforms;
    std::vector<cl::Device> devices;
    cl::Context context;
    cl::CommandQueue queue;
};
