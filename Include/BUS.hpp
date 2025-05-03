#ifndef __BUS_H__
#define __BUS_H__
#include "Memory.hpp"
#include "WEMUState.hpp"
#include "UART.h"
#define BUSLEAFNODEREAD(DeviceName) \
{ \
uint32_t DeviceNameAddrHead = DeviceName ## _BASE; \
uint32_t DeviceNameAddrTail = DeviceNameAddrHead+ DeviceName ## _SIZE; \
if(RAddr>=DeviceNameAddrHead&&RAddr<=DeviceNameAddrTail){\
            return this-> DeviceName ## Obj->DrviceRead(RAddr, len); \
    } \
}

#define BUSLEAFNODEWIRTE(DeviceName) \
{ \
uint32_t DeviceNameAddrHead = DeviceName ## _BASE; \
uint32_t DeviceNameAddrTail = DeviceNameAddrHead+ DeviceName ## _SIZE; \
if(WAddr>=DeviceNameAddrHead&&WAddr<=DeviceNameAddrTail){\
        this->MemoryObj->DrviceWrite(WAddr, WData, WMask); \
        return;\
    } \
}


class BUS{
    private:
        Memory * MemoryObj;
        WEMUState * WEMUStateObj;
        UART *UARTObj ;
        void AccessBUSOutOfBound(VAddr_t addr);

    public:
        Word_t BUSRead(VAddr_t RAddr,int len);
        void BUSWirte(VAddr_t WAddr,Word_t WData,int WMask);
        BUS (WEMUState * InWEMUState,char * img_file);
};
#endif