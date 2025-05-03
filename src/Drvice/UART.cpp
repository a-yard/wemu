#include "../../Include/UART.h"

UART::UART(){
    this->BlockDeviceBASE = UART_BASE;
    this->BlockDeviceSIZE = UART_SIZE;

}

uint32_t UART::DrviceRead(uint32_t addr, int len) {
    if(len!=1)assert(0);
    cout<<char(addr);
}
void UART::DrviceWrite(uint32_t addr, int len, uint32_t data) {
    assert(0);
}