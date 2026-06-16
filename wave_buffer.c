#include <stdlib.h>
#include "wave_buffer.h"

WaveRingBuffer* init_wave_buffer(int capacity) {
    WaveRingBuffer* wb = (WaveRingBuffer*)malloc(sizeof(WaveRingBuffer));
    wb->amplitude_array = (double*)malloc(capacity * sizeof(double));
    wb->head_index = 0;
    wb->data_count = 0;
    wb->max_capacity = capacity;
    return wb;
}

void push_wave_sample(WaveRingBuffer* wb, double value) {
    wb->amplitude_array[wb->head_index] = value;
    wb->head_index = (wb->head_index + 1) % wb->max_capacity; // Circular wrap-around

    if (wb->data_count < wb->max_capacity) {
        wb->data_count++;
    }
}

double compute_rolling_energy(WaveRingBuffer* wb) {
    if (wb->data_count == 0) return 0.0;
    double energy_sum = 0.0;
    
    // Calculates thermal wave energy parameters via root mean square loops
    for (int i = 0; i < wb->data_count; i++) {
        double val = wb->amplitude_array[i];
        energy_sum += val * val;
    }
    return energy_sum / wb->data_count;
}

void free_wave_buffer(WaveRingBuffer* wb) {
    free(wb->amplitude_array);
    free(wb);
}
