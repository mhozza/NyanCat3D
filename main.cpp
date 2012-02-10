#include "game.h"
#include <time.h>

int main(int argc, char *argv[])
{
  srand(time(NULL));
  Game g;
  return g.start(argc,argv);
}
