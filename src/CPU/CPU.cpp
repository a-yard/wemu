#include "../../Include/CPU.hpp"

CPU::CPU(BUS *InBUS,WEMUState * InWEMUState)
{
    this->ISAObj = new riscv32(InWEMUState,InBUS);
    this->WEMUStateObj = InWEMUState;
}

void CPU::exec_once()
{
    this->ISAObj->isa_exec_once();
}
void CPU::execute(uint64_t n)
{
    for (; n > 0; n--)
    {
        exec_once();
        if (WEMUStateObj->state != WEMU_RUNNING)
            break;
    }
}
void CPU::cpu_exec(uint64_t n)
{
    execute(n);
}
