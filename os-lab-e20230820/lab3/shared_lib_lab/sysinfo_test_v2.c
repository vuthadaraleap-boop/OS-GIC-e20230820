#include <stdio.h>
#include "techcorp_sysinfo.h"

int main(void) {
    printf("=== TechCorp System Info Report v2 ===\n");
    printf("Hostname : %s\n", tc_get_hostname());
    printf("Uptime   : %s\n", tc_get_uptime());
    printf("CPU Cores: %d\n", tc_get_cpu_count());
    printf("Memory   : %ld MB\n", tc_get_memory_mb());
    printf("======================================\n");
    return 0;
}
