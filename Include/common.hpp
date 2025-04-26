#ifndef __COMMON_H__
#define __COMMON_H__
#include <bits/stdint-uintn.h>
typedef uint32_t VAddr_t;
typedef uint32_t Word_t;
class riscv32_CPU_state{
    public:
        Word_t gpr[32];
};
#endif