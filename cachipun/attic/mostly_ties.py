import sys
import random

random.seed(hash(sys.argv[1]))


def generate_case(J, Q):
	print(J, Q)
	for _ in range(Q):
		a = random.randint(1,J)
		b = a
		while b == a:
			b = random.randint(1,J)
		m = random.choice([0]*2 + [1]*5 + [2]*2)
		
		print(a, b, m)	

J, Q = int(sys.argv[2]), int(sys.argv[3])

generate_case(J, Q)

