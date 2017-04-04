import sys,random

random.seed(hash(eval(sys.argv[1])))
N = eval(sys.argv[2])
print(N)
for i in range(N):
	b = random.randint(0,1)
	if b%2 == 0:
		print(random.randint(10**9-5,10**9),end=' ')
	else:
		print(random.randint(1,5),end=' ')		
print()
for i in range(N):
	print(random.randint(1,10**3),end=' ')



