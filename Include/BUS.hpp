#ifndef __BUS_H__
#define __BUS_H__
#include "Memory.hpp"
class BUS{
    private:
        Memory * MemoryObj;
    public:
        Word_t BUSRead(VAddr_t RAddr);
        void BUSWirte(VAddr_t WAddr,Word_t WData,int WMask);
        BUS (Memory * InMemory);
};
#endif