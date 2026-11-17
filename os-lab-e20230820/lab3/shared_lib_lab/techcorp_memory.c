#include "techcorp_sysinfo.h"
#include <stdio.h>

long tc_get_memory_mb(void) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp) {
        long mem_kb = 0;
        if (fscanf(fp, "MemTotal: %ld kB", &mem_kb) == 1) {
            fclose(fp);
            return mem_kb / 1024;
        }
        fclose(fp);
    }
    return -1;
}
