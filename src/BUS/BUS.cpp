#include "../../Include/BUS.hpp"

BUS::BUS( WEMUState *InWEMUState,char * img_file)
{
    this->MemoryObj = new Memory(img_file);
    this->UARTObj = new UART();
    this->WEMUStateObj = InWEMUState;
}

Word_t BUS::BUSRead(VAddr_t RAddr, int len)
{

    BUSLEAFNODEREAD(Memory);
    BUSLEAFNODEREAD(UART);
    AccessBUSOutOfBound(RAddr);
    
}
void BUS::BUSWirte(VAddr_t WAddr, Word_t WData, int WMask)
{
    if (WAddr == 0x80001000)
    {
        this->WEMUStateObj->state = WEMU_END;
        printf("--%d--\n", WData);
    }
    BUSLEAFNODEWIRTE(Memory);
    BUSLEAFNODEWIRTE(UART);
    AccessBUSOutOfBound(WAddr);
}

void BUS::AccessBUSOutOfBound(VAddr_t addr){
    cout<<"AccessBUSOutOfBound: 0x"<<hex<<addr<<endl;
    assert(0);
}