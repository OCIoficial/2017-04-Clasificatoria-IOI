import sys
import random

random.seed(hash(sys.argv[1]))


def generate_case(J, Q):
	print(J, Q)
	dJ = J//3
	rJ = dJ *3
	list_of_players = list(range(rJ))
	random.shuffle(list_of_players)
	first_third = list_of_players[0:dJ]
	second_third = list_of_players[dJ:2*dJ]
	third_third = list_of_players[2*dJ:]
	for _ in range(Q//2):
		a = random.choice(first_third)
		b = random.choice(second_third)
		c = random.choice(third_third)
		m1 = random.randint(0,2)
		m2 = random.randint(0,2)
		print(a+1,b+1,m1)
		print(b+1,c+1,m2)
	if Q%2:
		a = random.choice(first_third)
		b = random.choice(third_third)
		m = random.randint(0,1)
		print(a + 1, b + 1, m)


J, Q = int(sys.argv[2]), int(sys.argv[3])

generate_case(J, Q)
