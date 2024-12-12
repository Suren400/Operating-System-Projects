#include <stdint.h>
#include "paging.h"
#include "syscalls.h"
#include "interrupts.h"
#include "process.h"

void kernel_main() {
    setup_paging();
    load_programs_to_memory();
    initialize_processes();
    setup_timer_interrupt();

    while (1) {
        schedule_next_process();
        if (all_processes_finished()) {
            sbi_system_reset();
        }
    }
}
