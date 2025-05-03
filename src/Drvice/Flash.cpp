#include "../../Include/Flash.hpp"

Flash::Flash(){
    this->BlockDeviceBASE = FLASH_BASE;
    this->BlockDeviceSIZE = FLASH_SIZE;
    this->PMem = (uint8_t*)malloc(this->BlockDeviceSIZE);

}

Flash::Flash(char* ImgFile){
    Flash();
    this->load_img(ImgFile);
}