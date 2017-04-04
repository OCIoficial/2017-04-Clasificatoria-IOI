import sys,random

random.seed(hash(eval(sys.argv[1])))
N = eval(sys.argv[2])
print(N)
A = random.randint(1,10**9)
print((str(A)+" ")*N)
for i in range(N):
	print(random.randint(1,10**3),end=' ')



