import sys,random

random.seed(hash(sys.argv[1]))
N = 2
print(N)
for i in range(N-1):
	print(random.randint(1,10**9),end=' ')
print(random.randint(1,10**9))
for i in range(N-1):
	print(random.randint(1,10**3),end=' ')
print(random.randint(1,10**3))