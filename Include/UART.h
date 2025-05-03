#ifndef __MyUART_H__
#define __MyUART_H__

#include "CharacterDevice.hpp"
// 

class UART : public CharacterDevice{
    public:
        UART();
        virtual uint32_t DrviceRead(uint32_t addr, int len) ;
        virtual void DrviceWrite(uint32_t addr, int len, uint32_t data) ;
};

#endif