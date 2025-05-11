#include "../../Include/CLINT.h"

CLINT::CLINT(){
    this->BlockDeviceBASE = CLINT_BASE;
    this->BlockDeviceSIZE = CLINT_SIZE;
    this->mtimecmpH=0;
    this->mtimecmpL=0x10000;
    this->mtimeH=0;
    this->mtimeL=0;
    this->msip=0;
    time_t timep;
    time(&timep);
    // 强制转换为 64 位无符号整数（确保兼容性）
    uint64_t time_val = (uint64_t)timep;
    this->StartTime = time_val;
}

uint32_t CLINT::DrviceRead(uint32_t addr, int len) {
    UpDataState();
    
    uint32_t ReadData=-1;
    switch (addr&0x10000)
    {
    case 0XBFF8:
        ReadData=this->mtimeL;
        break;
    case 0XBFFC:
        ReadData=this->mtimeH;
        break;
    case 0X4000:
        ReadData=this->mtimecmpL;
        break;
    case 0X4004:
        ReadData=this->mtimecmpH;
        break;
    case 0:
        ReadData=this->msip;
        break;
    default:
        assert(0);
        break;
    }
    // printf("\nread addr = %x data = %x\n",addr,ReadData);

    return ReadData;
}
void CLINT::DrviceWrite(uint32_t addr, int len, uint32_t data) {
    // printf("\n  CLINT Write addr = %x  wdata = %x\n",addr,data);
    switch (addr)
    {
    case 0X200BFF8:
        this->mtimeL=data;
        return;
    case 0X200BFFC:
        this->mtimeH=data;
        return;
    case 0X2004000:
        this->mtimecmpL=data;
        return;
    case 0X2004004:
        this->mtimecmpH=data;
        return;
    case 0x2000000:
        
        this->msip = data;
        return;
    default:
        cout<<"access CLINT :"<<hex<<addr<<" error"<<endl;
        assert(0);
        break;
    }
}

void CLINT::UpDataState(){
    time_t timep;
    time(&timep);
    // 强制转换为 64 位无符号整数（确保兼容性）
    uint64_t time_val = (uint64_t)timep;
    // 提取高 32 位和低 32 位
    this->mtimeH = (uint32_t)((time_val-StartTime) >> 32); // 右移 32 位取高 32 位
    this->mtimeL  = (uint32_t)((time_val-StartTime) & 0xFFFFFFFF); // 掩码取低 32 位

    uint64_t mtime = ((uint64_t)this->mtimeH)<<32+this->mtimeL;
    uint64_t mtimecmp = ((uint64_t)this->mtimecmpH)<<32+this->mtimecmpL;
    if(	mtime >= mtimecmp){
        this->msip=1;
    }
}





