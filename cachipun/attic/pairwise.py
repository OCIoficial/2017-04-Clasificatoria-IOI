import sys
import random

random.seed(hash(sys.argv[1]))


def generate_case(J, Q):
	print(J, Q)
	dJ = J//2
	rJ = dJ *2 
	list_of_players = list(range(rJ))
	random.shuffle(list_of_players)
	first_half = list_of_players[0:dJ]
	second_half = list_of_players[dJ:]
	for _ in range(Q):
		a = random.choice(first_half)
		b = random.choice(second_half)
		m = random.randint(0,2)
		
		print(a,b,m)
			
	

J, Q = int(sys.argv[2]), int(sys.argv[3])

generate_case(J, Q)
