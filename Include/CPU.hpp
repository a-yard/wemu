#ifndef __CPUEXEC_H__
#define __CPUEXEC_H__
#include "ISA.hpp"
#include "Memory.hpp"
class CPU
{
private:
    ISA *ISAObj;

public:
    CPU(Memory * InMemory);
    ~CPU();
};

#endif