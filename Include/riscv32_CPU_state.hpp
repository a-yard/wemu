#ifndef __riscv32_CPU_state_H__
#define __riscv32_CPU_state_H__
#include "common.hpp"
#include "CsrVector.hpp"

class riscv32_CPU_state{
    private:
        CsrVector csr;
    public:
        Word_t gpr[32];
        VAddr_t pc;
        Word_t trap;
        VAddr_t dnpc; // dynamic next pc
        Word_t  ReadCSR(Word_t CSRNumber){
            Word_t PrivilegedLevelMode = (csr[0x300].Reg&0x1800)>>11;
            if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL")return csr[CSRNumber].Reg;
            else {
                printf("rerrorcsr(%s) 0x%x\n",csr[CSRNumber].CsrName.c_str(),CSRNumber);
                trap=0x2;
            }
            return 0;
        }
        void WriteCSR(Word_t CSRNumber,Word_t WData){
            if(WData==csr[CSRNumber].Reg&csr[CSRNumber].CsrName!="NULL")return;
            Word_t PrivilegedLevelMode = (csr[0x300].Reg&0x1800)>>11;
            if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL"&csr[CSRNumber].RWPermission<3){
                csr[CSRNumber].Reg = WData;
            } 
            else {
                trap=0x2;
            }
            
        }
};

#endif