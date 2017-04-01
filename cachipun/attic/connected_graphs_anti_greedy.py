import sys
import random
import math

random.seed(hash(sys.argv[1]))


def generate_case(J, Q):
	print(J, Q)
	
	n_clusters = int(math.log(J))
	list_of_players = list(range(J))
	random.shuffle(list_of_players)
	n_players_cluster = J // n_clusters
	clusters = [ list_of_players[x:x+n_players_cluster] for x in range(0, J, n_players_cluster)]
	for i in range(n_clusters):
		cluster = clusters[i]
		for _ in range(n_players_cluster*(n_players_cluster-1)//2):
			a = random.choice(cluster)
			b = a
			while b == a:
				b = random.choice(cluster)
			m = random.randint(0, 2)
			if Q < n_clusters:
				break
			print(a, b, m)
			Q-=1

	for _ in range(Q):
		a = random.choice(random.choice(clusters))
		b = random.choice(random.choice(clusters))
		m = random.randint(0, 2)
		print(a, b, m)
		
		
		

J, Q = int(sys.argv[2]), int(sys.argv[3])

generate_case(J, Q)

