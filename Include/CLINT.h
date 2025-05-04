#ifndef __CLINT_H__
#define __CLINT_H__
#include "CharacterDevice.hpp"
class CLINT:public CharacterDevice{
    public:
        CLINT();
        virtual uint32_t DrviceRead(uint32_t addr, int len) ;
        virtual void DrviceWrite(uint32_t addr, int len, uint32_t data) ;
};
#endif