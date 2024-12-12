#include <stddef.h>
#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "stdint.h"
#include "process.h" // for current_process and process_t structure

// Function prototypes
uint32_t pid();                          // Get the current process's PID
void exit();                             // Exit the current process
void write(char *message, size_t len);   // Write a message to the console
void sbi_system_reset();                 // Perform a system reset via SBI

#endif // SYSCALLS_H
