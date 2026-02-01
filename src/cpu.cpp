#include "cpu.hpp"
#include <fstream>
#include <sstream>
#include <string>

struct CpuTimes {
  long long user, nice, system, idle, iowait, irq, softirq,
      steal; // content structure for /proc/stat
};

static CpuTimes read_cpu_times() {
  std::ifstream file("/proc/stat");
  std::string line;
  std::getline(file, line); // puts file line to string line
  std::istringstream ss(line);
  std::string cpu;
  CpuTimes t{}; // object t to make content
  ss >> cpu >> t.user >> t.nice >> t.system >> t.idle >> t.iowait >> t.irq >>
      t.softirq >> t.steal;
  return t;
};
static long long total_time(const CpuTimes &t) {
  return t.user + t.nice + t.system + t.idle + t.iowait + t.irq + t.softirq +
         t.steal;
}
double get_cpu_usage(){
    static CpuTimes prev =read_cpu_times();
    CpuTimes now=read_cpu_times();
    long long prev_idle=prev.idle+prev.iowait;
    long long idle_now=now.idle+now.iowait;
    long long prev_total=total_time(prev);
    long long total_now=total_time(now);


    long long total_diff=total_now-prev_total;
    long long idle_diff=idle_now-prev_idle;
    prev=now;
    if(total_diff==0){
        return 0.0;
    };
return 100.0 * (total_diff-idle_diff)/total_diff;
}