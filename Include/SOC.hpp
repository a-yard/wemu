#ifndef __SOC_H__
#define __SOC_H__
#include "Memory.hpp"
#include "CPU.hpp"
#include "BUS.hpp"
class SOC{
    private:
        Memory * MemoryObj;
        CPU * CPUObj;
        BUS * BUSObj;
        
};

#endif