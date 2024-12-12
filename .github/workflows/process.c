#include "process.h"

void initialize_processes() {
    for (int i = 0; i < 5; i++) {
        processes[i].pid = i;
        processes[i].page_table = allocate_page_table();
        processes[i].stack = allocate_stack();
        processes[i].state = READY;
        load_program(processes[i].stack, hard_drive_program_address[i], program_size);
    }
}

void load_program(uint32_t *dest, uint32_t *src, size_t size) {
    memcpy(dest, src, size);
}

void schedule_next_process() {
    process_t* next_process = pick_next_process();
    switch_to_process(next_process);
}

bool all_processes_finished() {
    return is_ready_queue_empty() && !is_any_process_running();
}