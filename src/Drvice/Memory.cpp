#include "../../Include/Memory.hpp"

Memory::Memory()
{
    this->PMem = (uint8_t *)malloc(MEMORY_SIZE);
    static const uint32_t init_img[] = {
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
        0x00d605b3,
    };
    
    memcpy(GuestToHost(MEMORY_BASE), init_img, sizeof(init_img));

}

Memory::~Memory()
{
    free(this->PMem);
}


uint32_t Memory::DrviceRead(uint32_t addr, int len)
{
    // if (addr > 0x80000000)
    // {
        // out_of_bound(addr);
    // }
    return host_read(GuestToHost(addr), len);
}
void Memory::DrviceWrite(uint32_t addr, int len, uint32_t data)
{
    // if (addr > 0x80000000)
    // {
    //     out_of_bound(addr);
    // }
    host_write(GuestToHost(addr), len, data);
}

void Memory::out_of_bound(uint32_t addr)
{
    cout << "access memory out of bound:" << hex << addr << endl;
    assert(0);
}

void Memory::load_img(char* ImgFile){
    printf("%s\n\n",ImgFile);
    if (ImgFile == NULL) {
        this->img_size= 4096; // built-in image size
        return;
      }
      printf("%s\n\n",ImgFile);
      FILE *fp = fopen(ImgFile, "rb");
    
      fseek(fp, 0, SEEK_END);
      long size = ftell(fp);
    
      fseek(fp, 0, SEEK_SET);
      int ret = fread(GuestToHost(MEMORY_BASE), size, 1, fp);
    
      fclose(fp);
      img_size=size;

}