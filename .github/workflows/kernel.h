#ifndef KERNEL_H
#define KERNEL_H

// Function prototypes
void load_programs_to_memory(void);
void schedule_next_process(void);
int all_processes_finished(void);
void sbi_system_reset(void);

#endif // KERNEL_H
