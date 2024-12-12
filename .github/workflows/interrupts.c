#include "interrupts.h"

void timer_interrupt_handler() {
    save_process_state(current_process);
    current_process = (current_process + 1) % num_processes;
    load_process_state(current_process);
}
