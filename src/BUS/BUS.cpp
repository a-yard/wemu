#include "../../Include/BUS.hpp"

BUS::BUS(Memory * InMemory,WEMUState * InWEMUState){
    this->MemoryObj = InMemory;
    this->WEMUStateObj = InWEMUState;
}

Word_t BUS::BUSRead(VAddr_t RAddr,int len){
    
        return this->MemoryObj->DrviceRead(RAddr,len);
    
    assert(0);
}
void BUS::BUSWirte(VAddr_t WAddr,Word_t WData,int WMask){
    if(WAddr==0x80001000){
        this->WEMUStateObj->state = WEMU_END;
        printf("--%d--\n",WData);
    }
   
        this->MemoryObj->DrviceWrite(WAddr,WData,WMask);
        return ;
   
    assert(0);
}