#include <ncurses.h>  //used for visualisation
#include <unistd.h>   //used for sleep
#include <stdlib.h>   //used for memory management

#include "conway.h"

int main()
{
  //create environment
  int xlimit = 255;
  int ylimit = 255;
  int (*environment)[ylimit] = calloc(xlimit, ylimit * sizeof(int)); //sets allocated memory to zero
  initscr();  //initiates ncurses

  //call structures to be implemented
  r_pentominio(25, 120, xlimit, ylimit, environment);
  //diehard(25, 100, xlimit, ylimit, environment);
  //acorn(25, 100, xlimit, ylimit, environment);
  //beacon(15, 15, xlimit, ylimit, environment);
  //glider(5, 5, xlimit, ylimit, environment);

  int life_period = 1000;
  for (int i = 0; i < life_period; i++)
  {
    visualize(xlimit, ylimit, environment);
    sleep(0.1);
    //calculate next frame
    nextframe(xlimit, ylimit, environment);
  }
  endwin();           //terminates ncurses
  free(environment);  //free up heap
  return 0;
}
