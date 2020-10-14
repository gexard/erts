
//the xy order is in agreement to the ncurses visualisation

void r_pentominio(int y, int x, int * limit, int * environment)
{
  environment[(y + 1) * limit[0] + (x + 2)] = 1;
  environment[(y + 1) * limit[0] + (x + 3)] = 1;
  environment[(y + 2) * limit[0] + (x + 1)] = 1;
  environment[(y + 2) * limit[0] + (x + 2)] = 1;
  environment[(y + 3) * limit[0] + (x + 2)] = 1;
}

void diehard(int y, int x, int * limit, int * environment)
{
  environment[(y + 1) * limit[0] + (x + 8)] = 1;
  environment[(y + 2) * limit[0] + (x + 1)] = 1;
  environment[(y + 2) * limit[0] + (x + 2)] = 1;
  environment[(y + 3) * limit[0] + (x + 2)] = 1;
  environment[(y + 3) * limit[0] + (x + 7)] = 1;
  environment[(y + 3) * limit[0] + (x + 8)] = 1;
  environment[(y + 3) * limit[0] + (x + 9)] = 1;
}

void acorn(int y, int x, int * limit, int * environment)
{
  environment[(y + 1) * limit[0] + (x + 2)] = 1;
  environment[(y + 2) * limit[0] + (x + 4)] = 1;
  environment[(y + 3) * limit[0] + (x + 1)] = 1;
  environment[(y + 3) * limit[0] + (x + 2)] = 1;
  environment[(y + 3) * limit[0] + (x + 5)] = 1;
  environment[(y + 3) * limit[0] + (x + 6)] = 1;
  environment[(y + 3) * limit[0] + (x + 7)] = 1;
}
