#include <ncurses.h>
#include <unistd.h>
#include "cpu.hpp"
int main() {
  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, TRUE); // make getch unblockable
  while (true) {
    clear();
    mvprintw(1, 2, "leafmon");
    double cpu=get_cpu_usage();
    mvprintw(3, 2, "CPU :%.1f %%",cpu);
    mvprintw(5, 2, "MEM --");
    mvprintw(7, 2, "Press q to quit");

    refresh();
    int ch = getch();
    if (ch == 'q') {
      break;
    }

    // sleep for 200 ms for less ram consumption
    int sleepTime = 200000;
    usleep(sleepTime);
  }
  endwin();
  return 0;
}