#include "testlib.h"

int main()
{
  registerValidation();
  int T = inf.readInt(1, 100, "T");
  inf.readSpace();
  inf.readInt(2, 2, "D");
  inf.readSpace();
  inf.readInt(0, 0, "C");
  inf.readEoln();
  for (int i = 0; i < T; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (j > 0)
        inf.readSpace();
      inf.readInt(0, 1, "b");
    }
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
