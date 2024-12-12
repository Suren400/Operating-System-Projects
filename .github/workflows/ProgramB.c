#include <syscalls.h>
int main() {
    int sum = 0;
    while (1) {
        for (volatile int i = 0; i < 1000000; i++) { // Simulate workload
            sum += i;
        }
        write("Program B: Sum calculation complete.\n", 34); // Custom system call
    }
    return 0;
}
