#include "../../Include/SOC.hpp"

SOC::SOC(WEMUState * InWEMUState){
    this->MemoryObj = new Memory();
    this->BUSObj = new BUS(MemoryObj);
    this->CPUObj = new CPU(BUSObj,InWEMUState);
}