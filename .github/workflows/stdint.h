#ifndef STDINT_H
#define STDINT_H

// Ensure we're using the appropriate types based on the architecture
#if defined(__riscv)

    // If we're working with a 64-bit RISC-V architecture, define the types
    #if defined(RV64)
        typedef unsigned long long uint64_t;
        typedef signed long long int64_t;
    #else  // Assume RV32
        typedef unsigned int uint32_t;
        typedef signed int int32_t;
    #endif

    typedef unsigned char uint8_t;
    typedef signed char int8_t;
    typedef unsigned short uint16_t;
    typedef signed short int16_t;

    typedef unsigned long uint64_t;
    typedef signed long int64_t;

    // Ensure size_t is correctly defined for RV32 or RV64
    #if defined(RV32)
        typedef unsigned int size_t;
    #elif defined(RV64)
        typedef unsigned long long size_t;
    #endif

#else
    #error "Unknown platform"
#endif

#endif /* STDINT_H */
