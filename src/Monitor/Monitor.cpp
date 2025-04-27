#include "../../Include/Monitor.hpp"
Monitor::Monitor(int argc, char *argv[]){
    this->WEMUStateObj = new WEMUState();
    this->SCOObj = new SOC(WEMUStateObj);
    this->sdbObj = new sdb(SCOObj->BUSObj,SCOObj->CPUObj);
    this->sdbObj->sdb_mainloop();
}

int Monitor::is_exit_status_bad() {
    int good = (WEMUStateObj->state == WEMU_END && WEMUStateObj->halt_ret == 0) ||
      (WEMUStateObj->state == WEMU_QUIT) ;
    return !good;
  }


