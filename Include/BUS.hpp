#ifndef __BUS_H__
#define __BUS_H__
class BUS{
    private:
        Memory * MemoryObj;
    public:
        Word_t BUSRead(VAddr_t RAddr);
        void BUSWirte(VAddr_t WAddr,Word_t WData,int WMask);
};
#endif