#include "Include/Monitor.hpp"

int main(int argc, char *argv[]){
    Monitor * MonitorObj = new Monitor(argc,argv);
    return MonitorObj->is_exit_status_bad();
}