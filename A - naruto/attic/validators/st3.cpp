#include "testlib.h"

int main()
{
  int N = 100;
  registerValidation();
  int a = inf.readInt(0, N, "N");
  inf.readSpace();
  int b = inf.readInt(0, N, "N");
  inf.readSpace();
  int c = inf.readInt(0, N, "N");
  ensuref(a <= b and b <= c, "It must be a <= b <= c");
  ensuref(c - a <= 2, "It must be c - a <= 2");
  inf.readEoln();
  inf.readEof();
  return 0;
}
