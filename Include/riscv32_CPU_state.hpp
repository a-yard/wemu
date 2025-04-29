#ifndef __riscv32_CPU_state_H__
#define __riscv32_CPU_state_H__
#include "common.hpp"
class riscv32_CPU_state{
    public:
        Word_t gpr[32];
        VAddr_t pc;
        // Word_t mepc;  //存放触发异常的PC
        // Word_t mstatus; //存放处理器的状态
        // Word_t mcause;  //存放触发异常的原因
        // Word_t mtvec;   //存放异常入口地址
        Word_t csr[0x1000];
};

#endif