#include <stdint.h>
#ifndef PAGING_H
#define PAGING_H

void setup_paging();
void map_page(uint64_t *page_table, uint64_t virt_addr, uint64_t phys_addr, uint64_t flags);

#endif
