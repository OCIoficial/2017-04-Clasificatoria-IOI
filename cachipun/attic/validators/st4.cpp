#include "testlib.h"

int main()
{
    registerValidation();
    int J = inf.readInt(1, 100000, "J");
    inf.readSpace();
    int Q = inf.readInt(1, 100000, "Q");
    inf.readEoln();

    for (int i = 0; i < Q; ++i) {
      int a = inf.readInt(1, J, "a");
      inf.readSpace();
      int b =inf.readInt(1, J, "b");
      inf.readSpace();
      ensuref(a != b, "a and b cannot be equal");
      inf.readInt(0, 2, "m");
      inf.readEoln();
    }
    inf.readEof();
    return 0;
}
