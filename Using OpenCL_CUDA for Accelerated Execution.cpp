#include <CL/cl.hpp>  // OpenCL headers

static void executeOperation(const std::string& operation) {
    if (operation == "process") {
        // Sample OpenCL setup (error handling omitted for brevity)
        cl::Platform platform = cl::Platform::getDefault();
        cl::Device device = platform.getDevices(CL_DEVICE_TYPE_GPU).front();
        cl::Context context({ device });
        cl::Program program(context, loadKernelSource("path/to/kernel.cl"));
        program.build();

        // Execute OpenCL kernel
        cl::Kernel kernel(program, "processKernel");
        cl::CommandQueue queue(context, device);
        queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(256), cl::NullRange);
        queue.finish();
    }
}
