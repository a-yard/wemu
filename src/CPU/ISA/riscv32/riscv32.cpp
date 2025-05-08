#include "../../../../Include/riscv32.hpp"

riscv32::riscv32(WEMUState *InWEMUState, BUS *InBUS) : ISA(InBUS)
{
    unsigned char isa_logotmp[] = {
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x5f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20,
        0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x20, 0x0a, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x5f, 0x29,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x5f, 0x5f,
        0x5f, 0x20, 0x5c, 0x5f, 0x5f, 0x20, 0x5c, 0x20, 0x20, 0x7c, 0x20, 0x20,
        0x5c, 0x2f, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x0a, 0x20, 0x20, 0x5f, 0x20,
        0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x20, 0x5f, 0x20,
        0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x20, 0x20, 0x5f, 0x5f, 0x29,
        0x20, 0x7c, 0x20, 0x29, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x5c, 0x20, 0x20,
        0x2f, 0x20, 0x7c, 0x20, 0x5f, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f,
        0x5f, 0x20, 0x20, 0x5f, 0x20, 0x20, 0x20, 0x5f, 0x20, 0x20, 0x5f, 0x5f,
        0x20, 0x5f, 0x7c, 0x20, 0x7c, 0x0a, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20,
        0x60, 0x20, 0x5f, 0x20, 0x5c, 0x7c, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20,
        0x5c, 0x2f, 0x20, 0x5f, 0x5f, 0x7c, 0x7c, 0x5f, 0x5f, 0x20, 0x3c, 0x20,
        0x2f, 0x20, 0x2f, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x5c, 0x2f, 0x7c, 0x20,
        0x7c, 0x2f, 0x20, 0x5f, 0x60, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20, 0x5c,
        0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x2f, 0x20, 0x5f, 0x60, 0x20,
        0x7c, 0x20, 0x7c, 0x0a, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c,
        0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x5f, 0x29, 0x20, 0x5c,
        0x5f, 0x5f, 0x20, 0x5c, 0x5f, 0x5f, 0x5f, 0x29, 0x20, 0x2f, 0x20, 0x2f,
        0x5f, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20,
        0x28, 0x5f, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20,
        0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x20, 0x28, 0x5f, 0x7c, 0x20, 0x7c, 0x20,
        0x7c, 0x0a, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x7c,
        0x5f, 0x7c, 0x5f, 0x7c, 0x20, 0x2e, 0x5f, 0x5f, 0x2f, 0x7c, 0x5f, 0x5f,
        0x5f, 0x2f, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x5f, 0x5f, 0x5f, 0x5f, 0x7c,
        0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x7c, 0x5f, 0x7c, 0x5c, 0x5f, 0x5f,
        0x2c, 0x5f, 0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x5c, 0x5f, 0x5f,
        0x2c, 0x5f, 0x7c, 0x5c, 0x5f, 0x5f, 0x2c, 0x5f, 0x7c, 0x5f, 0x7c, 0x0a,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x7c, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c,
        0x5f, 0x7c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, '\0'};
    for (int i = 0; i < 580; i++)
    {
        this->isa_logo[i] = isa_logotmp[i];
    }
    this->WEMUStateObj = InWEMUState;


    restart();
}

void riscv32::restart()
{
    /* Set the initial program counter. */
    CPU_State.pc = RESET_VECTOR;
    // CPU_State.mepc = 0;
    // CPU_State.mstatus = 0x1800;
    // CPU_State.mcause = 0;
    // CPU_State.mtvec = 0;
    /* The zero register is always 0. */
    CPU_State.gpr[0] = 0;
    CPU_State.gpr[10] = HART_ID;
    CPU_State.gpr[11] = DEVICE_TREE_ADDR;


    this->CPU_State.pc = RESET_VECTOR;
    CPU_State.dnpc = RESET_VECTOR+4;

}
void riscv32::decode_operand(int *rd, Word_t *src1, Word_t *src2, Word_t *imm, int type)
{
    uint32_t i = this->inst;
    int rs1 = BITS(i, 19, 15);
    int rs2 = BITS(i, 24, 20);
    *rd = BITS(i, 11, 7);

    switch (type)
    {
    case TYPE_R:
        src1R();
        src2R();
        break;
    case TYPE_I:
        src1R();
        immI();
        break;
    case TYPE_S:
        src1R();
        src2R();
        immS();
        break;
    case TYPE_B:
        src1R();
        src2R();
        immB();
        break;
    case TYPE_U:
        immU();
        break;
    case TYPE_J:
        immJ();
        break;
    }
}

int riscv32::decode_exec()
{
    int rd = 0;
    Word_t src1 = 0, src2 = 0, imm = 0,zimm=0;
    zimm = (this->inst<<12)>>27;
    CPU_State.dnpc = this->CPU_State.pc;

    INSTPAT_START();

    INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R, R(rd) = src1 + src2);
    INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R, R(rd) = src1 - src2);
    INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll, R, R(rd) = src1 << ((src2) & 0x0000001f));
    INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, R, R(rd) = ((signed)src1 < (signed)src2) ? 1 : 0);
    INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, R, R(rd) = (src1 < src2) ? 1 : 0);
    INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor, R, R(rd) = src1 ^ src2);
    INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl, R, R(rd) = (src1 >> (src2 & 0x0000001f)));
    INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra, R, R(rd) = (signed)src1 >> (src2 & 0x0000001f));
    INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R, R(rd) = src1 | src2);
    INSTPAT("0000000 ????? ????? 111 ????? 01100 11", sub, R, R(rd) = src1 & src2);

    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I, R(rd) = src1 + SIGNEDEXTENSIONS(imm, 12));
    INSTPAT("??????? ????? ????? 010 ????? 00100 11", sltiu, I, R(rd) = (src1 < (SIGNEDEXTENSIONS(imm, 12))) ? 1 : 0);
    INSTPAT("??????? ????? ????? 011 ????? 00100 11", slti, I, R(rd) = (src1 < (SIGNEDEXTENSIONS(imm, 12))) ? 1 : 0);
    INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I, R(rd) = src1 ^ SIGNEDEXTENSIONS(imm, 12));
    INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori, I, R(rd) = src1 | SIGNEDEXTENSIONS(imm, 12));
    INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I, R(rd) = src1 & SIGNEDEXTENSIONS(imm, 12));
    INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli, I, R(rd) = src1 << imm);
    INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli, I, R(rd) = src1 >> imm);
    INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai, I, R(rd) = ((src1 >> (imm & 0x0000ffff)) | ((src1 >> 31) == 1 ? ((0xffffffff >> (32u - (imm & 0x0000ffff))) << (32u - (imm & 0x0000ffff))) : 0x0000000)));
    INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb, I, R(rd) = SIGNEDEXTENSIONS(Mr(src1 + SIGNEDEXTENSIONS(imm, 12), 1), 8));
    INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I, R(rd) = SIGNEDEXTENSIONS(Mr(src1 + SIGNEDEXTENSIONS(imm, 12), 2), 16));
    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I, R(rd) = Mr(src1 + SIGNEDEXTENSIONS(imm, 12), 4));
    INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I, R(rd) = Mr(src1 + SIGNEDEXTENSIONS(imm, 12), 1));
    INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I, R(rd) = Mr(src1 + SIGNEDEXTENSIONS(imm, 12), 2));
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, R(rd) = CPU_State.pc + 4; CPU_State.dnpc = src1 + SIGNEDEXTENSIONS(imm, 12));

    INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall, I,CPU_State.dnpc=RCsr(0x305); WCsr(0x341,CPU_State.pc);WCsr(0x342,11));//note
    INSTPAT("0011000 00010 00000 000 00000 11100 11", mret, I, CPU_State.dnpc = RCsr(0x341); ); // cpu.mcause= 8;  //note
    
    INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S, Mw(src1 + (SIGNEDEXTENSIONS(imm, 12)),  src2,1));
    INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S, Mw(src1 + (SIGNEDEXTENSIONS(imm, 12)),  src2,2));
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S, Mw(src1 + (SIGNEDEXTENSIONS(imm, 12)), src2,4));

    INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B, if ((signed)src1 >= (signed)src2) CPU_State.dnpc = CPU_State.pc + imm);       // note
    INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, if (src1 == src2) CPU_State.dnpc = CPU_State.pc + SIGNEDEXTENSIONS(imm, 13)); // note
    INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, if (src1 != src2) CPU_State.dnpc = CPU_State.pc + imm);
    INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B, if ((signed)src1 < (signed)src2) CPU_State.dnpc = CPU_State.pc + imm);
    INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B, if (src1 < src2) CPU_State.dnpc = CPU_State.pc + imm);
    INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B, if (src1 >= src2) CPU_State.dnpc = CPU_State.pc + imm);

    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(rd) = CPU_State.pc + imm);
    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(rd) = imm);

    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(rd) = CPU_State.pc + 4; CPU_State.dnpc = CPU_State.pc + SIGNEDEXTENSIONS(imm, 21)); // rd默认为x1

    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, set_wemu_state(WEMU_END, CPU_State.pc, R(10))); // R(10) is $a0

    //fence
    INSTPAT("0000??? ????? 00000 000 00000 00011 11", fence, I, ); 
    INSTPAT("0000000 00000 00000 001 00000 00011 11", fence_i, I, ); 

    //csr
    INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw, I, Word_t t = RCsr(imm);WCsr(imm,src1);R(rd)=t);
    INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs, I, Word_t t = RCsr(imm);WCsr(imm,src1 | t);R(rd)=t);
    INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc, I, Word_t t = RCsr(imm);WCsr(imm,src1 & t);R(rd)=t);
    INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi, I, Word_t t = RCsr(imm);WCsr(imm,zimm);R(rd)=t);     //note
    INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi, I, Word_t t = RCsr(imm);WCsr(imm,t |zimm);R(rd)=t);  //note
    INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci, I, Word_t t = RCsr(imm);WCsr(imm,t &zimm);R(rd)=t);  //note

    //M  note
    INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, R, R(rd) = (int64_t)(signed)src1 * (int64_t)(signed)src2);                                                                    
    INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh, R, R(rd) = ((((int64_t)(signed)src1) * ((int64_t)(signed)src2)) >> 32)); 
    INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu, R, R(rd) = (uint32_t)((((signed long)(signed)src1) * (src2)) >> 32));
    INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu, R, R(rd) = ((((unsigned long)(unsigned)src1) * ((unsigned long)(unsigned)src2)) >> 32));  
    INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div, R, {if(src2==0)R(rd)=-1; else R(rd) = ((int32_t)src1 == INT32_MIN && (int32_t)src2 == -1)?src1 : ((int32_t)src1/(int32_t)src2) ;} );                                                  
    INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu, R, R(rd)=(src2==0)?0xffffffff:src1/src2);                                                                   
    INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem, R,  {if(src2==0)R(rd)=src1; else R(rd) = ((int32_t)src1 == INT32_MIN && (int32_t)src2 == -1)?0 : ((int32_t)src1%(int32_t)src2) ;} );                                          
    INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, R, R(rd) = (src2==0)?src1:src1%src2 );                                                         
    
    //原子指令 note
    INSTPAT("00010?? 00000 ????? 010 ????? 01011 11", lr_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);R(rd)=tmp);  
    INSTPAT("00011?? ????? ????? 010 ????? 01011 11", sc_w, R, this->BUSObj->BUSWirte(src1,src2,4);R(rd)=0);  
    INSTPAT("00001?? ????? ????? 010 ????? 01011 11", amoswap_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);this->BUSObj->BUSWirte(src1,src2,4);R(rd)=tmp); 
    INSTPAT("00000?? ????? ????? 010 ????? 01011 11", amoadd_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);this->BUSObj->BUSWirte(src1,src2+tmp,4);R(rd)=tmp); 
    INSTPAT("00100?? ????? ????? 010 ????? 01011 11", amoxor_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);this->BUSObj->BUSWirte(src1,src2^tmp,4);R(rd)=tmp); 
    INSTPAT("01100?? ????? ????? 010 ????? 01011 11", amoand_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);this->BUSObj->BUSWirte(src1,src2&tmp,4);R(rd)=tmp); 
    INSTPAT("01000?? ????? ????? 010 ????? 01011 11", amoor_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);this->BUSObj->BUSWirte(src1,src2|tmp,4);R(rd)=tmp); 
    INSTPAT("10000?? ????? ????? 010 ????? 01011 11", amomin_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);if((int32_t)src2 < (int32_t)tmp) this->BUSObj->BUSWirte(src1,src2,4); else this->BUSObj->BUSWirte(src1,tmp,4);R(rd)=tmp);
    INSTPAT("10100?? ????? ????? 010 ????? 01011 11", amomax_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);if((int32_t)src2 > (int32_t)tmp) this->BUSObj->BUSWirte(src1,src2,4); else this->BUSObj->BUSWirte(src1,tmp,4);R(rd)=tmp); 
    INSTPAT("11000?? ????? ????? 010 ????? 01011 11", amominu_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);if(src2 < tmp) this->BUSObj->BUSWirte(src1,src2,4); else this->BUSObj->BUSWirte(src1,tmp,4);R(rd)=tmp); 
    INSTPAT("11100?? ????? ????? 010 ????? 01011 11", amomaxu_w, R, Word_t tmp = this->BUSObj->BUSRead(src1,4);if(src2 > tmp) this->BUSObj->BUSWirte(src1,src2,4); else this->BUSObj->BUSWirte(src1,tmp,4);R(rd)=tmp); 


    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, invalid_inst(this->CPU_State.pc));

    INSTPAT_END();

    R(0) = 0; // reset $zero to 0

    return 0;
}

int riscv32::isa_exec_once()
{

    this->inst = this->BUSObj->BUSRead(this->CPU_State.pc, 4);
    cout << "PC:" << hex << this->CPU_State.pc << ": 0x" << hex << inst << endl;
    this->CPU_State.pc+=4;
    this->decode_exec();
    this->CPU_State.pc = CPU_State.dnpc;
    this->BUSObj->CLINTObj->AddMtime();
    return 0;
}

VAddr_t riscv32::Get_PC()
{
    return this->CPU_State.pc;
}

void riscv32::DesplayCPU_state()
{
    for (int i = 0; i < 32; i++)
    {
        printf("%d  %x\n", i, this->CPU_State.gpr[i]);
    }
}

void riscv32::set_wemu_state(int state, VAddr_t pc, int halt_ret)
{
    this->WEMUStateObj->state = state;
    this->WEMUStateObj->halt_pc = pc;
    this->WEMUStateObj->halt_ret = halt_ret;
}
void riscv32::invalid_inst(VAddr_t thispc)
{

    uint32_t temp[2];
    VAddr_t pc = thispc;
    temp[0] = this->BUSObj->BUSRead(pc, 4);
    temp[1] = this->BUSObj->BUSRead(pc, 4);

    uint8_t *p = (uint8_t *)temp;
    printf("invalid opcode(PC = 0x%016x):\n"
           "\t%02x %02x %02x %02x %02x %02x %02x %02x ...\n"
           "\t%08x %08x...\n",
           thispc, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], temp[0], temp[1]);

    printf("There are two cases which will trigger this unexpected exception:\n"
           "1. The instruction at PC = 0x%016x is not implemented.\n"
           "2. Something is implemented incorrectly.\n",
           thispc);
    printf("Find this PC(0x%016x) in the disassembling result to distinguish which case it is.\n\n", thispc);
    printf(ANSI_FMT("If it is the first case, see\n%s\nfor more details.\n\n"
                    "If it is the second case, remember:\n"
                    "* The machine is always right!\n"
                    "* Every line of untested code is always wrong!\n\n",
                    ANSI_FG_RED),
           isa_logo);

    set_wemu_state(WEMU_ABORT, thispc, -1);
}

void riscv32::PrintfLog()
{

    cout << this->isa_logo << endl;
}
Word_t riscv32::Get_gpr(int n){
    return this->CPU_State.gpr[n];
}


bool riscv32::isa_difftest_checkregs(Ref_CPU_state *ref_r, VAddr_t pc){
    for (int i = 0; i < 32; i++)
    {
        if (ref_r->gpr[i] != this->CPU_State.gpr[i])
        {
            // printf("%s ref_f  = %x dut  = %x  error!\n", regsName[i].c_str(), ref_r->gpr[i], CPU_state.gpr[i]);
            pc = CPU_State.pc;
            return false;
        }
    }

    return true;
}