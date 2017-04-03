#include "testlib.h"

int main()
{
    registerValidation();
    int N = inf.readInt(2, 2, "N");
    inf.readEoln();

    for (int i = 0; i < N; ++i) {
      if (i > 0)
        inf.readSpace();
      inf.readInt(1, 10, "A");
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
