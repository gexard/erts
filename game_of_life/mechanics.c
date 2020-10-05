#include <ncurses.h>

void nextframe(int xlimit, int ylimit, int map[xlimit][ylimit])
{
  //make a copy for reference of previous frame while new one is being generated
  int mapcopy[xlimit][ylimit];
  for (int i = 0; i < xlimit; i++)
  {
    for (int j = 0; j < ylimit; j++)
    {
      mapcopy[i][j] = map[i][j];
    }
  }

  int neighbors;
  for (int i = 1; i < xlimit - 1; i++)    //starting at 1 and ending at an index
  {                                       // before the limit in order to calculate
    for (int j = 1; j < ylimit - 1; j++)  // neighbors properly around the edges
    {
      neighbors = 0;
      // count neighbors around cell (i,j)
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          if (mapcopy[i + 1 - k][j + 1 - l] == 1 && (k != 1 || l != 1))
          {
            neighbors++;
          }
        }
      }
      //determine alive status of cell (i,j)
      if (neighbors < 2 || neighbors > 3) //death conditions
      {
        map[i][j] = 0;
      }
      else if (neighbors == 3 && mapcopy[i][j] == 0)  //conditions for bringing cell to life
      {
        map[i][j] = 1;
      }
    }
  }
}

void visualize(int xlimit, int ylimit, int environment[xlimit][ylimit])
{
  for (int i = 0; i < xlimit; i++)
  {
    for (int j = 0; j < ylimit; j++)
    {
      if (environment[i][j] == 1)
      {
        mvaddch(i,j,'X'); //marks any alive cell with an 'X'
      }
      else
      {
        mvaddch(i,j,' '); //makes sure all dead cells are empty
      }
    }
  }
  refresh();
}
