#include <stdint.h>  // For uint32_t and size_t types
#ifndef PROCESS_H
#define PROCESS_H

// Process states
#define READY 1
#define RUNNING 2
#define TERMINATED 3

// Process structure
typedef struct {
    uint32_t pid;            // Process ID
    uint32_t *page_table;    // Pointer to the page table
    uint32_t *stack;         // Pointer to the process's stack
    int state;               // Process state (READY, RUNNING, TERMINATED)
} process_t;

// Global array of processes
#define MAX_PROCESSES 5
extern process_t processes[MAX_PROCESSES];  // Array to store processes

// Function declarations
void initialize_processes();  // Initialize processes
void load_program(uint32_t *dest, uint32_t *src, size_t size);  // Load program into process's memory
uint32_t *allocate_page_table();  // Function to allocate page table for process
uint32_t *allocate_stack();  // Function to allocate stack for process

#endif // PROCESS_H
