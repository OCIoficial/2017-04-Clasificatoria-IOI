import sys
import random

random.seed(hash(sys.argv[0]))


def generate_case(J, Q):
	print J, Q
	for _ in range(Q):
		a = random.randint(0,J)
		b = a
		while b == a:
			b = random.randint(0,J)
		m = random.randint(0,2)
		
		print a, b, m	

J, Q = int(sys.argv[1]), int(sys.argv[2])

print generate_case(J, Q)

