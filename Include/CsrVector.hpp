#ifndef __CSR_T_H__
#define __CSR_T_H__
#include "common.hpp"
enum PrivilegedLevel{
    PrivilegedLevelU=0,
    PrivilegedLevelS,
    PrivilegedLevelH,
    PrivilegedLevelM,
    
};

enum RWPermission{
    RWPermissionRW=0,
    RWPermissionRO=3
    
};

class CSR_T
{
    public:
        Word_t CsrNumber;
        string CsrName;
        Word_t Reg;
        Word_t PrivilegedLevel;
        Word_t RWPermission;
        
       
} ;



#define ADDCSR(csrname,csrn,RWPermission,PrivilegedLevel,InitVaalue) \
    CSR_T CSR_T__##csrn; \
    CSR_T__##csrn.CsrNumber = csrn; \
    CSR_T__##csrn.CsrName = csrname; \
    csrvector.push_back(CSR_T__##csrn)
    // Word_t cycle;   //cycle 计数器记录自处理器启动以来的时钟周期数  0xc00
	// Word_t cycleh;  //0xc80

	// Word_t time;   //timerl 是一个 32 位的寄存器，用于存储定时器（通常是系统时钟或定时中断机制）的低 32 位值  0xC01
	// Word_t timeh; //timeh 存储的是定时器 time 寄存器的高 32 位  0xC81

class CsrVector{
    private:
        vector<CSR_T> csrvector;
    public:
        string CsrName;
        int CsrNuber;
        
        CSR_T & operator[](int index) {
            for(int i=1;i<this->csrvector.size();i++){
                if(index==csrvector[i].CsrNumber)return csrvector[i];
            }
            return csrvector[0];
        }
        
        CsrVector (){
            ADDCSR("NULL",4096,0,0,0);
            ADDCSR("misa",0x301,RWPermissionRW,PrivilegedLevelM,0b01000010000000100000000000000000);//User mode implemented  Supervisor mode implemented
            ADDCSR("mvendorid",0xF11,RWPermissionRO,PrivilegedLevelM,0);  //表示非商业实现
            ADDCSR("marchid",0xF12,RWPermissionRO,PrivilegedLevelM,0);  //商业体系结构id
            ADDCSR("mimpid",0xF13,RWPermissionRO,PrivilegedLevelM,1); //处理器实现版本
            ADDCSR("mhartid",0xF14,RWPermissionRO,PrivilegedLevelM,0); //运行代码的硬件线程的整数 ID

            ADDCSR("mstatus",0x300,RWPermissionRW,PrivilegedLevelM,(0x3<<11)); //机器状态寄存器      note
            // ADDCSR("mstatush",0x310,RWPermissionRW,PrivilegedLevelM,0); //机器状态寄存器      note
            ADDCSR("mtvec",0x305,RWPermissionRW,PrivilegedLevelM,0); //机器陷阱向量基地址寄存器      
            ADDCSR("mip",0x344,RWPermissionRW,PrivilegedLevelM,0); //机器中断挂起。
            ADDCSR("mie",0x304,RWPermissionRW,PrivilegedLevelM,0); //机器中断使能寄存器    
            ADDCSR("mscratch",0x340,RWPermissionRW,PrivilegedLevelM,0); //机器陷阱处理程序的暂存器
            ADDCSR("mepc",0x341,RWPermissionRW,PrivilegedLevelM,0); //机器异常程序计数器
            ADDCSR("mcause",0x342,RWPermissionRW,PrivilegedLevelM,0); //机器成因寄存器
            ADDCSR("mtval",0x343,RWPermissionRW,PrivilegedLevelM,0); //机器错误地址或指令




        
    
            // ADDCSR("cycle",0xc00);
            // ADDCSR("cycleh",0xc80);
            // ADDCSR("time",0xC01);
            // ADDCSR("timeh",0xC81);

            // for(int i=0;i<0x10000;i++){
            //     ADDCSR("NULL",i,0,PrivilegedLevelM,0);
            // }

        }
};
#endif