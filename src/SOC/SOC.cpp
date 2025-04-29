#include "../../Include/SOC.hpp"

SOC::SOC(WEMUState * InWEMUState,char * img_file){
    this->MemoryObj = new Memory();
    this->MemoryObj->load_img(img_file);
    this->BUSObj = new BUS(MemoryObj,InWEMUState);
    this->CPUObj = new CPU(BUSObj,InWEMUState);
}