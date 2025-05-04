#include "../../Include/SOC.hpp"

SOC::SOC(WEMUState * InWEMUState,char * img_file,char * dtb_file){
    this->BUSObj = new BUS(InWEMUState,img_file,dtb_file);
    this->CPUObj = new CPU(BUSObj,InWEMUState);
}