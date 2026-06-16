#include <stdio.h>
#include "wave_buffer.h"

int main() {
    printf("🌡️  Activating ThermalWave-Buffer Streaming Kernel...\n\n");

    WaveRingBuffer* logs = init_wave_buffer(3);

    // Simulate high-frequency temperature oscillations in an industrial reactor
    printf("📥 Logging Temperature Waves: 45.2°C, 48.9°C, 52.1°C\n");
    push_wave_sample(logs, 45.2);
    push_wave_sample(logs, 48.9);
    push_wave_sample(logs, 52.1);

    printf("   📊 Current Integrated Wave Energy Quotient: %.2f\n", compute_rolling_energy(logs));

    // New element insertion triggers an automatic overwrite of the oldest record
    printf("\n📥 Logging New Peak Wave: 61.4°C (Triggers Overwrite)\n");
    push_wave_sample(logs, 61.4);

    printf("   🔮 Updated Wave Energy Quotient: %.2f\n", compute_rolling_energy(logs));

    free_wave_buffer(logs);
    return 0;
}
