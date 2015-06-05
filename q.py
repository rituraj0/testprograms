import Queue as Q

pq = Q.PriorityQueue();

pq.put(10);

for xy in range(1,10):
	pq.put(xy*xy%47);

while not pq.empty():
	print( pq.get() );