

void r_pentominio(int x, int y, int xlimit, int ylimit, int map[xlimit][ylimit])
{
  map[x + 1][y + 2] = 1;
  map[x + 1][y + 3] = 1;
  map[x + 2][y + 1] = 1;
  map[x + 2][y + 2] = 1;
  map[x + 3][y + 2] = 1;
}

void diehard(int x, int y, int xlimit, int ylimit, int map[xlimit][ylimit])
{
  map[x + 1][y + 8] = 1;
  map[x + 2][y + 1] = 1;
  map[x + 2][y + 2] = 1;
  map[x + 3][y + 2] = 1;
  map[x + 3][y + 7] = 1;
  map[x + 3][y + 8] = 1;
  map[x + 3][y + 9] = 1;
}

void acorn(int x, int y, int xlimit, int ylimit, int map[xlimit][ylimit])
{
  map[x + 1][y + 2] = 1;
  map[x + 2][y + 4] = 1;
  map[x + 3][y + 1] = 1;
  map[x + 3][y + 2] = 1;
  map[x + 3][y + 5] = 1;
  map[x + 3][y + 6] = 1;
  map[x + 3][y + 7] = 1;
}

void beacon(int x, int y, int xlimit, int ylimit, int map[xlimit][ylimit])
{
  map[x + 1][y + 1] = 1;
  map[x + 1][y + 2] = 1;
  map[x + 2][y + 1] = 1;
  map[x + 3][y + 4] = 1;
  map[x + 4][y + 3] = 1;
  map[x + 4][y + 4] = 1;
}

void glider(int x, int y, int xlimit, int ylimit, int map[xlimit][ylimit])
{
  map[x + 1][y + 2] = 1;
  map[x + 2][y + 3] = 1;
  map[x + 3][y + 1] = 1;
  map[x + 3][y + 2] = 1;
  map[x + 3][y + 3] = 1;
}
