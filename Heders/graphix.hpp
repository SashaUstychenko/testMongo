
#include <curses.h>
#include <ncurses.h>



namespace GRP_USTYCNEKO
{
  void func()
  {
        initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Виведення тексту
    attron(COLOR_PAIR(1));
    printw("Red text in the center of the screen");
    attroff(COLOR_PAIR(1));

    // Оновлення екрану
    refresh();

    // Чекає на введення клавіші
    getch();

    // Завершення ncurses
    endwin();

  }

}
