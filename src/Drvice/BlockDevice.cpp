#include "../../Include/BlockDevice.hpp"

uint8_t* BlockDevice::GuestToHost(uint32_t paddr){
    return (uint8_t *)(this->PMem + paddr - BlockDeviceBASE);
}

uint32_t BlockDevice::HostToGuest(uint8_t *haddr){
    return (uint32_t)(haddr - this->PMem + BlockDeviceBASE);
}

uint32_t BlockDevice::host_read(void *addr, int len){
    switch (len)
    {
    case 1:
        return *(uint8_t *)addr;
    case 2:
        return *(uint16_t *)addr;
    case 4:
        return *(uint32_t *)addr;
    default:
        assert(0);
    }
}

void BlockDevice::host_write(void *addr, int len, uint32_t data)
{
    switch (len)
    {
    case 1:
        *(uint8_t *)addr = data;
        return;
    case 2:
        *(uint16_t *)addr = data;
        return;
    case 4:
        *(uint32_t *)addr = data;
        return;
    default:
        assert(0);
    }
}