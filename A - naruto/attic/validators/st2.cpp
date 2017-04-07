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
  ensuref(a == 0 and c - b <= 2, "It must be c - b <= 2");
  inf.readEoln();
  inf.readEof();
  return 0;
}
