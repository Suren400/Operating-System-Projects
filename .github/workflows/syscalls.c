#include "syscalls.h"

uint32_t pid() {
    return current_process->pid;
}

void exit() {
    current_process->state = FINISHED;
}

void write(char *message, size_t len) {
    char *phys_addr = translate_virt_to_phys(current_process->page_table, message);
    sbi_debug_console_write(phys_addr, len);
}

void exit() {
    // Mark the process as finished or handle the termination logic
    sbi_system_reset();
}