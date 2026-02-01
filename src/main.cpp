#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    while (true) {

        clear();

        mvprintw(1, 2, "leafmon");
        mvprintw(3, 2, "Running...");
        mvprintw(5, 2, "Press q to quit");

        refresh();

        int ch = getch();
        if (ch == 'q')
            break;

        usleep(200000);
    }

    endwin();
    return 0;
}
