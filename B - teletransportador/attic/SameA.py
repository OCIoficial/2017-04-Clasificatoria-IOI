import sys,random

random.seed(hash(sys.argv[1]))
N = int(sys.argv[2])
print(N)
A = random.randint(1,10**5)
print((str(A)+" ")*(N-1)+str(A))
for i in range(N-1):
	print(random.randint(1,10**3),end=' ')
print(random.randint(1,10**3))