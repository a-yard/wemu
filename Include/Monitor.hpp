#ifndef __MONITOR_H__
#define __MONITOR_H__
#include "common.hpp"
#include "SOC.hpp"
#include "WEMUState.hpp"
#include "sdb.hpp"
class Monitor{
    private:
        SOC * SCOObj;
        sdb * sdbObj;
        WEMUState * WEMUStateObj;
    public:
        Monitor(int argc, char *argv[]);
        ~Monitor();
        int is_exit_status_bad() ;
};

#endif