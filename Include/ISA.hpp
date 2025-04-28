#ifndef __ISA_H__
#define __ISA_H__
#include "common.hpp"
#include "Memory.hpp"
#include "BUS.hpp"
class ISA{
    protected:
        BUS * BUSObj;
    public:
        virtual VAddr_t Get_PC()=0;
        virtual int isa_exec_once()=0;
        virtual void DesplayCPU_state()=0;
        ISA (BUS * InBUS);
        

};

#endif