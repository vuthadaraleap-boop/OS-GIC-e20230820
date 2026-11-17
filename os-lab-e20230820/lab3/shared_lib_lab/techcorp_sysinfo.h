#ifndef TECHCORP_SYSINFO_H
#define TECHCORP_SYSINFO_H

const char* tc_get_hostname(void);
const char* tc_get_uptime(void);
int tc_get_cpu_count(void);
long tc_get_memory_mb(void);

#endif
