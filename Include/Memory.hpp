#ifndef __MEMORY_H__
#define __MEMORY_H__
#include "BlockDevice.hpp"
class Memory:public BlockDevice{
    private:    
        void out_of_bound(uint32_t addr);
    public:
        Memory();
        ~Memory();
        uint32_t DrviceRead(uint32_t addr, int len);
        void DrviceWrite(uint32_t addr, int len, uint32_t data);
        void load_img(char* ImgFile);
        long img_size;
};

#endif