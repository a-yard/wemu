#ifndef __riscv32_CPU_state_H__
#define __riscv32_CPU_state_H__
#include "common.hpp"
#include "CsrVector.hpp"

class riscv32_CPU_state
{
private:
    CsrVector csr;

public:
    vector<string> regsName;
    Word_t gpr[32];
    VAddr_t pc;
    Word_t trap;
    VAddr_t dnpc; // dynamic next pc
    // Word_t  ReadCSR(Word_t CSRNumber){
    //     Word_t ReturnData = csr[CSRNumber].Reg;
    //     Word_t PrivilegedLevelMode = 3;//(csr[mstatusAddr].Reg&0x1800)>>11;
    //     if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL")return ReturnData;
    //     else {
    //         printf("rerrorcsr(%s) 0x%x\n",csr[CSRNumber].CsrName.c_str(),CSRNumber);
    //         trap=0x2;
    //     }
    //     return 0;
    // }
    // void WriteCSR(Word_t CSRNumber,Word_t WData){
    //     Word_t old_data = WData==csr[CSRNumber].Reg;
    //     if(CSRNumber==mieAddr){
    //         // this->csr.DisplayCsr();
    //         printf("\n=========\n");
    //         printf("wdata == %x\n\n",WData);
    //         printf("before mie w = %x\n",old_data);
    //         printf("mie w = %x\n",WData);
    //         printf("after mie w = %x\n",csr[CSRNumber].Reg);
    //         printf("=========\n");
    //     }

    //     if(WData==csr[CSRNumber].Reg&csr[CSRNumber].CsrName!="NULL")return;
    //     Word_t PrivilegedLevelMode = 3;//(csr[mstatusAddr].Reg&0x1800)>>11;
    //     if(csr[CSRNumber].PrivilegedLevel>=PrivilegedLevelMode & csr[CSRNumber].CsrName!="NULL"&csr[CSRNumber].RWPermission<3){
    //         csr[CSRNumber].Reg = WData;

    //     }
    //     else {
    //         printf("werrorcsr(%s) 0x%x\n",csr[CSRNumber].CsrName.c_str(),CSRNumber);
    //         trap=0x2;
    //     }

    // }
    Word_t GetCsrId(Word_t CSRAddr)
    {
        for (int i = 0; i < this->csr.csrvector.size(); i++)
        {
            if (CSRAddr == csr.csrvector[i].CsrNumber)
                return i;
        }
        return 0;
    }
    Word_t ReadCSR(Word_t CSRNumber)
    {
        if (CSRNumber == cycleAddr)
        {
            printf("oldvalid = %x CSRNumber==cycleAddr\n", csr.csrvector[GetCsrId(cycleAddr)].Reg);
        }
        Word_t PrivilegedLevelMode = 3; //(csr[mstatusAddr].Reg&0x1800)>>11;
        if (csr.csrvector[GetCsrId(CSRNumber)].PrivilegedLevel >= PrivilegedLevelMode & csr.csrvector[GetCsrId(CSRNumber)].CsrName != "NULL")
            return csr.csrvector[GetCsrId(CSRNumber)].Reg;
        else
        {
            printf("rerrorcsr(%s) 0x%x\n", csr.csrvector[GetCsrId(CSRNumber)].CsrName.c_str(), CSRNumber);
            trap = 0x2;
        }
        return 0;
    }

    void WriteCSR(Word_t CSRNumber, Word_t WData)
    {

        if (WData == csr.csrvector[GetCsrId(CSRNumber)].Reg & csr.csrvector[GetCsrId(CSRNumber)].CsrName != "NULL")
            return;
        Word_t PrivilegedLevelMode = 3; //(csr[mstatusAddr].Reg&0x1800)>>11;
        if (csr.csrvector[GetCsrId(CSRNumber)].PrivilegedLevel >= PrivilegedLevelMode & csr.csrvector[GetCsrId(CSRNumber)].CsrName != "NULL" & csr.csrvector[GetCsrId(CSRNumber)].RWPermission < 3)
        {
            csr.csrvector[GetCsrId(CSRNumber)].Reg = WData;
        }
        else
        {
            printf("werrorcsr(%s) 0x%x\n", csr.csrvector[GetCsrId(CSRNumber)].CsrName.c_str(), CSRNumber);
            trap = 0x2;
        }
    }

    void Addcycle()
    {
        csr.csrvector[GetCsrId(cycleAddr)].Reg++;
        if (csr.csrvector[GetCsrId(cycleAddr)].Reg == 0)
        {
            csr.csrvector[GetCsrId(cyclehAddr)].Reg++;
        }
    }

    void DisPlayCsr()
    {
        this->csr.DisplayCsr();
    }
    void DisPlayReg()
    {
        for (int i = 0; i < 32; i++)
    {
        printf("%s : 0x%x\n", regsName[i].c_str(),gpr[i]);
    }
    }
    riscv32_CPU_state()
    {
        const char *regsTmp[] = {
            "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
            "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
            "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
            "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
        for (int i = 0; i < 32; i++)
        {
            this->regsName.push_back(string(regsTmp[i]));
           
        }
    
    }
};

#endif