#include "../../Include/BUS.hpp"

BUS::BUS(Memory * InMemory){
    this->MemoryObj = InMemory;
}

Word_t BUS::BUSRead(VAddr_t RAddr,int len){
    if(RAddr<=MEMORY_SIZE+CONFIG_MBASE-1&RAddr>=(VAddr_t)CONFIG_MBASE){
        return this->MemoryObj->PMemRead(RAddr,len);
    }
    assert(0);
}
void BUS::BUSWirte(VAddr_t WAddr,Word_t WData,int WMask){
    if(WAddr<=MEMORY_SIZE+CONFIG_MBASE-1&WAddr>=CONFIG_MBASE){
        this->MemoryObj->PMemwrite(WAddr,WData,WMask);
        return ;
    }
    assert(0);
}