import sys
import random


random.seed(hash(sys.argv[1]))

n_tiempos = int(sys.argv[2])
n_dedos = int(sys.argv[3])
demora = int(sys.argv[4])
max_notas = int(sys.argv[5])
n_botones = 5


def gen(b, m, anterior=None):
  if anterior and not random.randint(0, 2):
    return anterior

  x = [0 for i in range(b)]
  for i in range(random.randint(0, m)):
    x[random.randint(0, 4)] = 1
  return x

print(n_tiempos, n_dedos, demora)

dedos = None
for i in range(n_tiempos):
  dedos = gen(n_botones, max_notas, anterior=dedos)
  print(' '.join(str(d) for d in dedos))
