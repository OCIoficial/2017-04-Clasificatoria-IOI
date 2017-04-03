import random
import sys

k = int(sys.argv[2])
n = int(sys.argv[3])
seed = int(sys.argv[1])

random.seed(hash(seed))

if(k == 1):
	a = 0
	b = 0
	c = random.randint(0,n)
if(k == 2):
	a = 0
	b = random.randint(0,n)
	c = random.randint(b,b+2)
if(k == 3):
	a = random.randint(0,n)
	b = random.randint(a,a+2)
	c = random.randint(b,a+2)
if(k == 4):
	a = random.randint(0,n)
	b = random.randint(a,n)
	c = random.randint(b,n)

print(a,b,c)

