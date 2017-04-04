import sys,random

random.seed(hash(eval(sys.argv[1])))
N = eval(sys.argv[2])
print(N)
for i in range(N):
	print(random.randint(1,10**9),end=' ')
print()
for i in range(N):
	print(random.randint(1,10**3),end=' ')



