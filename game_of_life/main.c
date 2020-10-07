#include <ncurses.h>  //used for visualisation
#include <unistd.h>   //used for sleep
//#include <stdlib.h>   //used for memory management (malloc, free)

#include "conway.h"

int main()
{
  initscr();  //initiates ncurses

  //create environment
  int xlimit, ylimit;
  getmaxyx(stdscr, xlimit, ylimit);
  int environment[xlimit][ylimit];

  //call structures to be implemented
  r_pentominio(25, 120, xlimit, ylimit, environment);
  //diehard(25, 100, xlimit, ylimit, environment);
  //acorn(25, 100, xlimit, ylimit, environment);
  //beacon(15, 15, xlimit, ylimit, environment);
  //glider(5, 5, xlimit, ylimit, environment);

  int life_period = 100;
  for (int i = 0; i < life_period; i++)
  {
    visualize(xlimit, ylimit, environment);
    usleep(200000);
    //calculate next frame
    nextframe(xlimit, ylimit, environment);
  }
  endwin();           //terminates ncurses
  return 0;
}
