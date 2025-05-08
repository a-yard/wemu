#ifndef __riscv32_CPU_state_H__
#define __riscv32_CPU_state_H__
#include "common.hpp"
#include "CsrVector.hpp"

class riscv32_CPU_state{
    private:
    
    public:
        Word_t gpr[32];
        VAddr_t pc;
        CsrVector csr;
        VAddr_t dnpc; // dynamic next pc
        Word_t  ReadCSR(Word_t CSRNumber){
            Word_t PrivilegedLevelMode = (csr[0x300].Reg&0x1800)>>11;
            if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL")return csr[CSRNumber].Reg;
            else {
                csr[0x341].Reg = pc;
                csr[0x342].Reg = 0x2;
                dnpc = csr[0x305].Reg;
            }
        }
        void WriteCSR(Word_t CSRNumber,Word_t WData){
            Word_t PrivilegedLevelMode = (csr[0x300].Reg&0x1800)>>11;
            if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL"&csr[CSRNumber].RWPermission<3){
                csr[CSRNumber].Reg = WData;
            } else {
                csr[0x341].Reg = pc;
                csr[0x342].Reg = 0x2;
                dnpc = csr[0x305].Reg;
            }
            
        }
};

#endif