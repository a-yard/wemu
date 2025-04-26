#ifndef __CPUEXEC_H__
#define __CPUEXEC_H__
#include "ISA.hpp"
class CPUExec
{
private:
    ISA * ISAObj;
public:
    CPUExec();
    ~CPUExec();
};



#endif