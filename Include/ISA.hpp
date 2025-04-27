#ifndef __ISA_H__
#define __ISA_H__
#include "common.hpp"
#include "Memory.hpp"
class ISA{
    protected:
        BUS * BUSObj;
    public:
        virtual VAddr_t Get_PC();
        virtual void isa_exec_once();
        ISA (BUS * InBUS);
        

};

#endif