#include "../../Include/Monitor.hpp"
Monitor::Monitor(int argc, char *argv[]){
    this->parse_args(argc,argv);
    this->WEMUStateObj = new WEMUState();
    printf("%s",this->img_file);
    this->SOCObj = new SOC(WEMUStateObj,this->img_file);
    this->sdbObj = new sdb(SOCObj->BUSObj,SOCObj->CPUObj);
    this->sdbObj->sdb_mainloop();
}

int Monitor::is_exit_status_bad() {
    int good = (WEMUStateObj->state == WEMU_END && WEMUStateObj->halt_ret == 1) ||
      (WEMUStateObj->state == WEMU_QUIT) ;
    return !good;
 }


int Monitor::parse_args(int argc, char *argv[])
  {
      const struct option table[] = {
          {"batch", no_argument, NULL, 'b'},
          {"log", required_argument, NULL, 'l'},
          {"diff", required_argument, NULL, 'd'},
          {"port", required_argument, NULL, 'p'},
          {"help", no_argument, NULL, 'h'},
          {0, 0, NULL, 0},
      };
      int o;
      while ((o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1)
      {
          switch (o)
          {
          case 'b':
              this->sdbObj->sdb_set_batch_mode();
              break;
          // case 'p': sscanf(optarg, "%d", &difftest_port); break;
          // case 'l': log_file = optarg; break;
          case 'd':
              diff_so_file = optarg;
              break;
          case 'e':
              elf_file = optarg;
              break;
          case 1:
              img_file = optarg;
              return 0;
          default:
              printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
              printf("\t-b,--batch              run with batch mode\n");
              printf("\t-l,--log=FILE           output log to FILE\n");
              printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
              printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
              printf("\n");
              exit(0);
          }
      }
      return 0;
  }