#include <ncurses.h>
#include <stdlib.h>

int * createEnvironment(int * limit)
{
  int * environment = (int *) calloc(limit[0] * limit[0], sizeof(int));
  if (environment == NULL)
  {
    printf("ERROR: not enough space in memory\n");
    exit(1);
  }
  return (environment);
}

void visualize(int height, int width, int * offset, int * limit, int * environment)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (environment[(i + offset[0]) * limit[0] + (j + offset[1])] == 1)
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

int * nextframe(int * offset, int * limit, int * environment)
{
  //make a copy for reference of previous frame while new one is being generated
  int environment_copy[limit[0]][limit[0]];
  for (int i = 0; i < limit[0]; i++)
  {
    for (int j = 0; j < limit[0]; j++)
    {
      environment_copy[j][i] = environment[i * limit[0] + j];
    }
  }

  //modify environment indicators {(offset), (limit)}
  int mod_e[2] = {0, 0};

  //check life status
  int neighbors;
  for (int i = 1; i < limit[0] - 1; i++) //the range excludes the outer cells for
  {                                   //correct neighbor calculation
    for (int j = 1; j < limit[0] - 1; j++)
    {
      neighbors = 0;
      // count neighbors around cell (i,j)
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          if (environment_copy[j + 1 - k][i + 1 - l] == 1 && (k != 1 || l != 1))
          {
            neighbors++;
          }
        }
      }
      //determine alive status of cell (i,j)
      if (neighbors < 2 || neighbors > 3) //death conditions
      {
        environment[i * limit[0] + j] = 0;
      }
      else if (neighbors == 3 && environment_copy[j][i] == 0)  //conditions for bringing cell to life
      {
        environment[i * limit[0] + j] = 1;

        //check to see if a border needs to be increased
        if (i == 1 || j == 1)
        {
          mod_e[0] = 1;
        }
        else if (i == limit[0] - 1 || j == limit[0] - 1)
        {
          mod_e[1] = 1;
        }
      }
    }
  }

  //modify environment if needed
  if (mod_e[0] > 0 || mod_e[1] > 0)
  {
    //add up the borders that need to be increased to the new limit[0]
    limit[1] = limit[0] + (int) mod_e[0] + (int) mod_e[1];

    //increase offset according to the top and left borders
    if (mod_e[0] == 1)
    {
      offset[0] = offset[0] + 1;
      offset[1] = offset[1] + 1;
    }

    //increase allocated memory
    environment = (int *) realloc(environment, limit[1] * limit[1] * sizeof(int));

    //empty new environment
    for (int i = 0; i < (limit[1] * limit[1]); i++)
    {
      environment[i] = 0;
    }

    //fill new environment according to new limits and offset
    for (int j = 0; j < limit[0]; j++)
    {
      for (int k = 0; k < limit[0]; k++)
      {
        environment[(j + mod_e[0]) * limit[1] + (k + mod_e[0])] = environment_copy[k][j];
      }
    }
    limit[0] = limit[1];
  }
  return(environment);
}
