#ifndef __MONITOR_H__
#define __MONITOR_H__
#include "common.hpp"
#include "SOC.hpp"
#include "WEMUState.hpp"
class Monitor{
    private:
        SOC * SCOObj;
        WEMUState * WEMUStateObj;
    public:
        Monitor(int argc, char *argv[]);
        ~Monitor();
        int is_exit_status_bad() ;
};

#endif