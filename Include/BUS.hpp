#ifndef __BUS_H__
#define __BUS_H__
#include "Memory.hpp"
#include "WEMUState.hpp"
class BUS{
    private:
        Memory * MemoryObj;
        WEMUState * WEMUStateObj;

    public:
        Word_t BUSRead(VAddr_t RAddr,int len);
        void BUSWirte(VAddr_t WAddr,Word_t WData,int WMask);
        BUS (Memory * InMemory,WEMUState * InWEMUState);
};
#endif