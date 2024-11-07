// Define a consignment with task details, resource requirements, and priority
consignment myTask {
    task: "Data Processing";
    cpu: 4;            // CPU cores required
    memory: "2GB";
    gpu: true;         // Use GPU if available
    cloud: true;       // Allows remote processing if local resources are insufficient
    priority: high;
    dependencies: [otherTask]; // Executes after 'otherTask' completes
};
