#include "../../Include/CLINT.h"

CLINT::CLINT(){
    this->BlockDeviceBASE = CLINT_BASE;
    this->BlockDeviceSIZE = CLINT_SIZE;
}

uint32_t CLINT::DrviceRead(uint32_t addr, int len) {
    assert(0);
    return 0;
}
void CLINT::DrviceWrite(uint32_t addr, int len, uint32_t data) {
    assert(0);
}