#ifndef __RISCV32_H__
#define __RISCV32_H__
#include "riscv32_CPU_state.hpp"
#include "WEMUState.hpp"
#include "ISA.hpp"
#include "decode.h"

static inline int check_reg_idx(int idx) {
    IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
    return idx;
  }
  static inline int check_csrreg_idx(int idx) {
    IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < 8));
    return idx;
  }
  
  #define gpr(idx) (CPU_State.gpr[check_reg_idx(idx)])
  #define RCsr(idx) CPU_State.ReadCSR(check_csrreg_idx(idx))
  #define WCsr(idx,WData) CPU_State.WriteCSR(check_csrreg_idx(idx),WData)
  #define MRCsr(idx) CPU_State.MReadCSR(check_csrreg_idx(idx))
  #define MWCsr(idx,WData) CPU_State.MWriteCSR(check_csrreg_idx(idx),WData)


  static inline const char* reg_name(int idx) {
    extern const char* regs[];
    return regs[check_reg_idx(idx)];
  }
  

#define R(i) gpr(i)
#define Mr this->BUSObj->BUSRead
#define Mw this->BUSObj->BUSWirte


enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, // none
  TYPE_J,TYPE_B,TYPE_R
};

#define SIGNEDEXTENSIONS(imm,len) ((Word_t)(imm |(((imm>>(len-1))==1u)?((0xffffffff>>(len-1))<<(len-1)):0x00000000) ))

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do {*imm = (SEXT(BITS(i,31,31),1)<<20 | BITS(i,30,21)<<1 | BITS(i,20,20)<<11 | BITS(i,19,12)<<12);}while(0)
#define immB() do {*imm = (SEXT(BITS(i,31,31),1)<<12 | BITS(i,30,25)<<5 | BITS(i,11,8)<<1 | BITS(i,7,7)<<11);}while(0)



class riscv32 : public ISA
{
private:
    riscv32_CPU_state CPU_State;
    WEMUState * WEMUStateObj;
    void restart();
    void decode_operand( int *rd, Word_t *src1, Word_t *src2, Word_t *imm, int type);
    int decode_exec();
    Word_t LRADDRFLag;
    bool wfiFlag;

    
    Word_t inst;
    void set_wemu_state(int state, VAddr_t pc, int halt_ret);
    void invalid_inst(VAddr_t thispc);
    unsigned char isa_logo[580];

public:
    riscv32(WEMUState *InWEMUState,BUS * InBUS);
    VAddr_t Get_PC();
    int isa_exec_once();
    void DesplayReg();
    void PrintfLog();
    Word_t Get_gpr(int n);
    bool isa_difftest_checkregs(Ref_CPU_state *ref_r, VAddr_t pc);
    void DesplayCSR();
};
#endif