#include "../../Include/BUS.hpp"

BUS::BUS( WEMUState *InWEMUState,char * img_file)
{
    this->MemoryObj = new Memory(img_file);
    this->WEMUStateObj = InWEMUState;
}

Word_t BUS::BUSRead(VAddr_t RAddr, int len)
{

    return this->MemoryObj->DrviceRead(RAddr, len);
}
void BUS::BUSWirte(VAddr_t WAddr, Word_t WData, int WMask)
{
    if (WAddr == 0x80001000)
    {
        this->WEMUStateObj->state = WEMU_END;
        printf("--%d--\n", WData);
    }

    this->MemoryObj->DrviceWrite(WAddr, WData, WMask);
    return;
}