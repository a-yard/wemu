#include "../../Include/SOC.hpp"

SOC::SOC(WEMUState * InWEMUState,char * img_file){
    this->BUSObj = new BUS(InWEMUState,img_file);
    this->CPUObj = new CPU(BUSObj,InWEMUState);
}