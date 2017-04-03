#include "testlib.h"

int main()
{
    registerValidation();
    int N = inf.readInt(2, 1000000, "N");
    inf.readEoln();

    int prev = -1;
    for (int i = 0; i < N; ++i) {
      if (i > 0)
        inf.readSpace();
      int A = inf.readInt(1, 1000000000, "A");
      if (i > 0)
        ensuref(A == prev, "Initial costs must be equal");
      prev = A;
    }
    inf.readEoln();
    for (int i = 0; i < N; ++i) {
      if (i > 0)
        inf.readSpace();
      inf.readInt(1, 1000, "C");
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}
