import sys,randomTo

random.seed(hash(sys.argv[1]))
N = int(sys.argv[2])
print(N)
for i in range(N-1):
	b = random.randint(0,1)
	if b%2 == 0:
		print(random.randint(10**9-5,10**9),end=' ')
	else:
		print(random.randint(1,5),end=' ')
b = random.randint(0,1)
if b%2 == 0:
	print(random.randint(10**9-5,10**9))
else:
	print(random.randint(1,5))
print("1000 "*(N-1)+"1000")