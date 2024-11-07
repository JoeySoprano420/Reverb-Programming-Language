APIHandler api;
api.setAuth("api_key", "my_secure_key");

// Dispatch task to cloud
api.uploadFile("cloud_endpoint", "data/input_data.txt");
api.startComputeJob("cloud_compute_endpoint", myTask);
