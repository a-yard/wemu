#ifndef __SOC_H__
#define __SOC_H__
#include "Memory.hpp"
#include "CPU.hpp"
#include "BUS.hpp"
class SOC{
    public:
        Memory * MemoryObj;
        CPU * CPUObj;
        BUS * BUSObj;
        WEMUState * WEMUStateObj;
        SOC(WEMUState * InWEMUState);
        
};

#endif