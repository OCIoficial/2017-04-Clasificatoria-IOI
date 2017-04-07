#include "testlib.h"

int main()
{
  registerValidation();
  int T = inf.readInt(1, 1000, "T");
  inf.readSpace();
  inf.readInt(1, 1, "D");
  inf.readSpace();
  inf.readInt(1, 1, "C");
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
