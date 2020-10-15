#include <ncurses.h>  //used for visualisation
#include <unistd.h>   //used for sleep
#include <stdlib.h>   //used for memory management (malloc, free)

#include "conway.h"

int main()
{
  initscr();  //initiates ncurses

  //create environment with an inital size of 300x300 and no offsets
  int limit[2] = {300, 300};
  int offset[2] =  {0, 0};
  int * environment = createEnvironment(limit);

  //obtain screen limits
  int height = 50, width = 200;
  //getmaxyx(stdscr, height, width);

  //call structures to be implemented
  r_pentominio(25, 25, limit, environment);
  diehard(25, 50, limit, environment);
  acorn(25, 75, limit, environment);

  //play game!
  int life_period = 1000;
  for (int i = 0; i < life_period; i++)
  {
    visualize(height, width, offset, limit, environment);
    usleep(100000);
    environment = nextframe(offset, limit, environment);
  }

  free(environment);
  endwin();
  return 0;
}
