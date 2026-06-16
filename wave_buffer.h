#ifndef WAVE_BUFFER_H
#define WAVE_BUFFER_H

typedef struct {
    double* amplitude_array;
    int head_index;
    int data_count;
    int max_capacity;
} WaveRingBuffer;

WaveRingBuffer* init_wave_buffer(int capacity);
void push_wave_sample(WaveRingBuffer* wb, double value);
double compute_rolling_energy(WaveRingBuffer* wb);
void free_wave_buffer(WaveRingBuffer* wb);

#endif
