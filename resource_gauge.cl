// resource_gauge.cl
__kernel void adjustResource(__global int *resource, const int base, const int stretch) {
    int adjusted_usage = base + stretch;

    // Cap usage at 100 to simulate max capacity
    *resource = adjusted_usage > 100 ? 100 : adjusted_usage;
}
