#include "../../Include/MROM.hpp"


MROM::MROM(){
    this->BlockDeviceBASE = MROM_BASE;
    this->BlockDeviceSIZE = MROM_SIZE;
    this->PMem = (uint8_t*)malloc(this->BlockDeviceSIZE);
}

void MROM::DrviceWrite(uint32_t addr, int len, uint32_t data){
    cout<<"MRON Can't Write"<<endl;
    assert(0);
}