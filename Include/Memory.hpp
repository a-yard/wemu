#ifndef __MEMORY_H__
#define __MEMORY_H__
#include "common.hpp"
class Memory{
    private:
        uint8_t * PMem;
        uint8_t *GuestToHost(uint32_t paddr);
        uint32_t HostToGuest(uint8_t *haddr);
        uint32_t host_read(void *addr, int len);
        void host_write(void *addr, int len, uint32_t data);
        void out_of_bound(uint32_t addr);
    public:
        Memory();
        ~Memory();
        uint32_t PMemRead(uint32_t addr, int len);
        void PMemwrite(uint32_t addr, int len, uint32_t data);
        void load_img(char* ImgFile);
        long img_size;
};

#endif