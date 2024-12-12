#include <syscalls.h>
int main() {
    int counter = 0;
    while (1) {
        for (volatile int i = 0; i < 1000000; i++) { // Simulate workload
            counter++;
        }
        write("Program A: Counter value updated.\n", 31); // Custom system call
    }
    return 0;
}
