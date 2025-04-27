#ifndef __CPUEXEC_H__
#define __CPUEXEC_H__
#include "ISA.hpp"
#include "Memory.hpp"
#include "BUS.hpp"
#include "WEMUState.hpp"
class CPU
{
private:
    ISA *ISAObj;
    WEMUState * WEMUStateObj;
    void exec_once();
    void execute(uint64_t n);

public:
    CPU(BUS * InBUS,WEMUState * InWEMUState);
    ~CPU();
    void cpu_exec(uint64_t n);
};

#endif