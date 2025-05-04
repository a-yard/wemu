#ifndef __ISA_H__
#define __ISA_H__
#include "common.hpp"
#include "Memory.hpp"
#include "BUS.hpp"
#include "DiffTestDut.hpp"
class ISA{
    protected:
        BUS * BUSObj;
    public:
        virtual VAddr_t Get_PC()=0;
        virtual int isa_exec_once()=0;
        virtual void DesplayCPU_state()=0;
        ISA (BUS * InBUS);
        virtual Word_t Get_gpr(int n)=0;
        virtual bool isa_difftest_checkregs(Ref_CPU_state *ref_r, VAddr_t pc)=0;
        

};

#endif