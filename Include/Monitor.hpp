#ifndef __MONITOR_H__
#define __MONITOR_H__
#include "common.hpp"
#include "SOC.hpp"
#include "WEMUState.hpp"
#include "sdb.hpp"
#include <getopt.h>
#define no_argument 0
#define required_argument 1
#define optional_argument 2

class Monitor
{
private:
    char *img_file;
    char *elf_file;
    char *diff_so_file;
    char * dtb_file;
    char * Kernal_file;
    SOC *SOCObj;
    sdb *sdbObj;
    WEMUState *WEMUStateObj;

public:
    Monitor(int argc, char *argv[]);
    ~Monitor();
    int is_exit_status_bad();
    int parse_args(int argc, char *argv[]);
    void welcome();
};

#endif