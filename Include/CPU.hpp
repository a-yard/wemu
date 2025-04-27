#ifndef __CPUEXEC_H__
#define __CPUEXEC_H__
#include "ISA.hpp"
#include "Memory.hpp"
#include "BUS.hpp"
class CPU
{
private:
    ISA *ISAObj;

public:
    CPU(BUS * InBUS);
    ~CPU();
};

#endif