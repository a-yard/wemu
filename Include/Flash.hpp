#ifndef __FLASH_H__
#define __FLASH_H__
#include "common.hpp"
#include "BlockDevice.hpp"
class Flash : public BlockDevice
{
public:
    Flash();
    uint32_t DrviceRead(uint32_t addr, int len);
    void DrviceWrite(uint32_t addr, int len, uint32_t data);

};
#endif