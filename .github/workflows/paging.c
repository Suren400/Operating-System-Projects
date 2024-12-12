#include "paging.h"

void setup_paging() {
    uint64_t *page_table = allocate_page();
    map_page(page_table, 0x80000000, 0x80000000, KERNEL_FLAGS);  // Identity mapping for OS code
    map_page(page_table, 0x40000000, 0x84000000, USER_FLAGS);    // Map user programs
    write_satp(page_table);
}
