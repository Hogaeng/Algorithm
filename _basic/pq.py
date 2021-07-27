from queue import PriorityQueue as pq
from random import randrange
q=pq()
n=5
for i in range(n):
    x,y=randrange(n),randrange(n)
    print(-x,y)
    q.put((-x,y))
for i in range(len(q.queue)):
    print(q.get())
    print(len(q.queue))