#include "../../Include/Monitor.hpp"
Monitor::Monitor(int argc, char *argv[]){
    this->WEMUStateObj = new WEMUState();
}

int Monitor::is_exit_status_bad() {
    int good = (WEMUStateObj->state == WEMU_END && WEMUStateObj->halt_ret == 0) ||
      (WEMUStateObj->state == WEMU_QUIT) ;
    //printf("nemu_state.state = %d nemu_state.halt_ret = %d nemu_state.state = %d good = %d\n",nemu_state.state,nemu_state.halt_ret,nemu_state.state,good);
    return !good;
  }