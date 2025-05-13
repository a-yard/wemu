#include "../../Include/UART.h"

UART::UART(){
    this->BlockDeviceBASE = UART_BASE;
    this->BlockDeviceSIZE = UART_SIZE;
    this->UartReg[5]=0x60;
    this->UartReg[0]=0;
    

}

uint32_t UART::DrviceRead(uint32_t addr, int len) {
    if(len!=1)assert(0);
    // printf("read Addr = %x\n\n",addr);
    return this->UartReg[addr&0x7];
}
void UART::DrviceWrite(uint32_t addr, int len, uint32_t data) {
    if(len!=1)assert(0);
    // printf("%x\n%x\n",data,addr);
    this->UartReg[addr&0x7]=data&0xff;
    if(addr==UART_BASE)printf("%c",data&0xff);
    // printf("%c",data);
    // switch (addr&0x3)
    // {
    // case constant expression:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }
  
}