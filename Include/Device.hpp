#ifndef __DRVICE_H__
#define __DRVICE_H__
#include "common.hpp"
class Device{
    protected:
        virtual void out_of_bound(uint32_t addr)=0;
    public:
        virtual uint32_t DrviceRead(uint32_t addr, int len)=0;
        virtual void DrviceWrite(uint32_t addr, int len, uint32_t data)=0;
};
#endif