#include "../../Include/CPU.hpp"

CPU::CPU(BUS * InBUS){
    this->ISAObj = new ISA(InBUS);
}